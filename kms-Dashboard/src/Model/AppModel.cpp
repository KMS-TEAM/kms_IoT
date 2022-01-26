#include <QDebug>

#include "AppModel.h"
#include "Constants_Def.h"

AppModel* AppModel::m_instance = nullptr;
QMutex AppModel::m_lock;

AppModel *AppModel::getInstance()
{
    m_lock.lock();
    if(nullptr == m_instance)
    {
        m_instance = new AppModel();
    }
    m_lock.unlock();
    return m_instance;
}

int AppModel::currentScreenID() const
{
    return m_currentScreenID;
}

void AppModel::setCurrentScreenID(int currentScreenID)
{
    if (m_currentScreenID == currentScreenID)
        return;

    m_currentScreenID = currentScreenID;
    CONSOLE << "SCREEN ID: " << currentScreenID;
    emit currentScreenIDChanged(m_currentScreenID);
}

void AppModel::slotReceiveEvent(int event)
{
    switch (event) {
    case static_cast<int>(AppEnums::E_SCREEN_t::HomeScreen):
        CONSOLE <<  "Home Screen";
        setCurrentScreenID(AppEnums::HomeScreen);
        break;
    case static_cast<int>(AppEnums::E_SCREEN_t::SearchScreen):
        CONSOLE <<  "Search Screen";
        setCurrentScreenID(AppEnums::SearchScreen);
        break;
    case static_cast<int>(AppEnums::E_SCREEN_t::ControlScreen):
        CONSOLE << "Control Screen";
        setCurrentScreenID(AppEnums::ControlScreen);
        break;
    case static_cast<int>(AppEnums::E_SCREEN_t::MapScreen):
        CONSOLE << "Map Screen";
        setCurrentScreenID(AppEnums::MapScreen);
        break;
    case static_cast<int>(AppEnums::E_SCREEN_t::UserScreen):
        CONSOLE << "User Screen";
        setCurrentScreenID(AppEnums::UserScreen);
        break;
    default:
        break;
    }
}

AppModel::AppModel(QObject *parent)
    : QObject(parent)
    , m_currentScreenID {static_cast<int>(AppEnums::HomeScreen)}
{
    m_sensor = QSensorMQTT::getInstance();
    m_sensor->initBokerHost();

}
