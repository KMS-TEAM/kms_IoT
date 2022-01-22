#include "AppEngine.h"
#include "Constants_Def.h"
#include "Screen_Def.h"
#include "AppEnums.h"
#include "QMLHandler.h"

ScreenDef* ScreenDef::m_instance = nullptr;
QMutex ScreenDef::m_lock;
Constants_Def* Constants_Def::m_instance = nullptr;
QMutex Constants_Def::m_lock;

AppEngine::AppEngine(QObject *parent)
    : QObject(parent)
{
    m_rootContext = m_engine.rootContext();
}

AppEngine::~AppEngine()
{
    // DELETE_DEFS;
    // DELETE_SCR_DEF;
}

void AppEngine::initEngine()
{
    qmlRegisterUncreatableType<AppEnums>("QmlCustomItem", 1, 0, "ENUMS", "Uncreatable");

    // set context properties
    m_rootContext->setContextProperty("QmlHandler", QML_HANDLER);
    m_rootContext->setContextProperty("CONST", DEFS);
    m_rootContext->setContextProperty("SCREEN", SCR_DEF);
    m_rootContext->setContextProperty("AppModel", MODEL);
}

void AppEngine::startApplication()
{
    m_engine.load(SCR_DEF->QML_APP());
}


