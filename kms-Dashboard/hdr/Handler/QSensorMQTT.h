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

#include "QmlMQTTClient.h"

struct SensorNode {
    QString topic_data;
    QString topic_control;
    QString token;
    QString mac_address;
};

class QSensorMQTT : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString mqttMesage READ mqttMessage WRITE setMqttMessage NOTIFY mqttMessageChanged)
    Q_PROPERTY(SensorNode currentSensorNode READ currentSensorNode WRITE setCurrentSensorNode NOTIFY currentSensorNodeChanged)

    static QSensorMQTT *m_instance;

public:
    static QSensorMQTT *getInstance();
    ~QSensorMQTT();

    int loadMQTTSetting(QString path);
    int initBokerHost(QString path);
    void connectMQTT(QString brokerName, qint16 port);

    QString mqttMessage() const;
    SensorNode currentSensorNode() const;

public slots:
    void onMQTT_Connected();
    void onMQTT_disconnected();
    void onMQTT_Received(const QByteArray &message, const QMqttTopicName &topic);

    void MQTT_Publish(SensorNode node, QString message);
    void MQTT_Subcrib(SensorNode node);

    void setMqttMessage(QString &msg);
    void setCurrentSensorNode(SensorNode node);

signals:
    void MQTT_Received();
    void mqttMessageChanged();
    void currentSensorNodeChanged();

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

    QString m_mqttMessage;
    SensorNode m_currentSensorNode;
};

#endif // QSENSORMQTT_H
