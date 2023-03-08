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
    Q_PROPERTY(QString sensorMess READ sensorMess WRITE setSensorMess NOTIFY sensorMessChanged)
    Q_PROPERTY(QString currentHostName READ currentHostName WRITE setCurrentHostName NOTIFY currentHostNameChanged)
    Q_PROPERTY(QString currentPort READ currentPort WRITE setCurrentPort NOTIFY currentPortChanged)
public:
    static AppModel *getInstance();

    int currentScreenID() const;
    QString sensorMess() const;
    QString currentHostName() const;
    QString currentPort() const;

    void startHomeScreen();

public slots:
    void setCurrentScreenID(int currentScreenID);
    void slotReceiveEvent(int event);
    void setSensorMess(QString msg);
    void setCurrentHostName(QString hostName);
    void setCurrentPort(QString port);

signals:
    void currentScreenIDChanged(int currentScreenID);
    void sensorMessChanged(QString msg);
    void currentHostNameChanged(QString hostName);
    void currentPortChanged(QString port);

private:
    AppModel(QObject* parent = nullptr);
    AppModel(const AppModel&) = delete;
    void operator =(const AppModel&) = delete;

    static AppModel* m_instance;
    static QMutex m_lock;

    int m_currentScreenID;
    QString m_mess;

    QSensorMQTT *m_sensor;

};

#endif // APPMODEL_H
