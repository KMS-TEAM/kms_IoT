#include "QSensorMQTT.h"
#include "Constants_Def.h"

QSensorMQTT* QSensorMQTT::m_instance = nullptr;

QSensorMQTT::QSensorMQTT(QObject *parent)
    : QObject{parent}
{

}

QSensorMQTT *QSensorMQTT::getInstance()
{
    if(nullptr == m_instance)
    {
        m_instance = new QSensorMQTT();
    }
    return m_instance;
}

QSensorMQTT::~QSensorMQTT()
{

}

int QSensorMQTT::loadMQTTSetting()
{
    QFile file(device_path.toStdString().c_str());
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val = file.readAll();
    file.close();
    QJsonArray a = QJsonDocument::fromJson(val.toUtf8()).array();

    for (int i = 0; i < a.count(); ++i) {
        QJsonValue v = a[i];
        SensorNode node;
        node.topic_data = v["topic-sensor"].toString();
        node.topic_control = v["topic-control"].toString();
        node.token = v["token"].toString();
        node.mac_address = v["mac_address"].toString();
        sensorsNode.push_back(node);
    }
    return 0;
}

int QSensorMQTT::initBokerHost()
{
    QFile f(broker_path.toStdString().c_str());
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val = f.readAll();
    QJsonArray array = QJsonDocument::fromJson(val.toUtf8()).array();
    for(int i = 0; i < array.size(); i++){
        QJsonObject t_obj = array[i].toObject();
        brokerHosts.push_back(t_obj["hostname"].toString());
        //        qDebug()<< i << "-" <<hostnames[i];
    }
    return 0;
}

void QSensorMQTT::connectMQTT(QString brokerName, qint16 port)
{
    m_client = new QMqttClient();
    connect(m_client, &QMqttClient::disconnected, this, &QSensorMQTT::onMQTT_disconnected);
    connect(m_client, &QMqttClient::messageReceived, this, &QSensorMQTT::onMQTT_Received);
    m_client->setHostname(brokerName);
    m_client->setPort(port);
    m_client->connectToHost();
}


void QSensorMQTT::onMQTT_Connected(QString topic)
{
    auto sub = m_client->subscribe(topic, quint8(2));
    if (!sub){
        qDebug() << "Could not subcribe. Is there avalid connection?";
    }
}

void QSensorMQTT::onMQTT_disconnected()
{
    CONSOLE << "DISCONNECTED";
}

void QSensorMQTT::onMQTT_Received(const QByteArray &message, const QMqttTopicName &topic)
{
    CONSOLE << "TOPIC: " << topic;
    CONSOLE << "MESSAGE: " << message;

    emit MQTT_Received();
}

void QSensorMQTT::MQTT_Publish(SensorNode node, QString message)
{
    m_current_pub = node;
    m_client->publish(node.topic_control, message.toUtf8());
}

void QSensorMQTT::MQTT_Subcrib(SensorNode node)
{
    m_client->unsubscribe(m_current_sub.topic_data);
    m_current_device = node;
    m_current_sub = node;
    onMQTT_Connected(m_current_sub.topic_data);
}
