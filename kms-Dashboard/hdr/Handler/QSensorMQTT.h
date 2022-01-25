#ifndef QSENSORMQTT_H
#define QSENSORMQTT_H

#include <QObject>
#include <QString>
#include <QtMqtt/QtMqtt>
#include <QtMqtt/QMqttClient>
#include <QVector>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QFile>
#include <QMutex>

struct SensorNode {
    QString topic_data;
    QString topic_control;
    QString token;
    QString mac_address;
};

class QSensorMQTT : public QObject
{
    Q_OBJECT
    static QSensorMQTT *m_instance;

public:
    static QSensorMQTT *getInstance();
    ~QSensorMQTT();

    void loadMQTTSetting();
    int initBokerHost();
    void connectMQTT(QString bokerName, qint16 port);

public slots:
    QString MQTT_Received();
    void onMQTT_Connected();
    void onMQTT_disconnected();
    void onMQTT_Received(const QString message);

    void MQTT_Publish(SensorNode node, QString message);
    void MQTT_Subcrib(SensorNode node);

signals:

public:
    QVector<QString> brokerHosts;
    QVector<SensorNode> sensorsNode;

    QString device_path;
    QString broker_path;

private:
    QSensorMQTT(QObject* parent = nullptr);
    QSensorMQTT(const QSensorMQTT&) = delete;
    void operator =(const QSensorMQTT&) = delete;

    QMqttClient *m_client;
    SensorNode m_current_device;
    SensorNode m_current_sub;
    SensorNode m_current_pub;

};

#endif // QSENSORMQTT_H
