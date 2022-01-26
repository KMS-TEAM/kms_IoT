#ifndef APPMODEL_H
#define APPMODEL_H

#include <QObject>
#include <QString>
#include <QMutex>
#include "AppEnums.h"
#include "QSensorMQTT.h"

#define MODEL AppModel::getInstance()

class AppModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentScreenID READ currentScreenID WRITE setCurrentScreenID NOTIFY currentScreenIDChanged)
public:
    static AppModel *getInstance();

    int currentScreenID() const;
    void startHomeScreen();

public slots:
    void setCurrentScreenID(int currentScreenID);
    void slotReceiveEvent(int event);

signals:
    void currentScreenIDChanged(int currentScreenID);

private:
    AppModel(QObject* parent = nullptr);
    AppModel(const AppModel&) = delete;
    void operator =(const AppModel&) = delete;

    static AppModel* m_instance;
    static QMutex m_lock;
    int m_currentScreenID;
    QSensorMQTT *m_sensor;
};

#endif // APPMODEL_H
