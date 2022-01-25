#include "QSensorMQTT.h"

QSensorMQTT::QSensorMQTT(QObject *parent)
    : QObject{parent}
{

}

QSensorMQTT *QSensorMQTT::getInstance()
{

}

QSensorMQTT::~QSensorMQTT()
{

}

void QSensorMQTT::loadMQTTSetting()
{

}

int QSensorMQTT::initBokerHost()
{

}

void QSensorMQTT::connectMQTT(QString bokerName, qint16 port)
{

}

QString QSensorMQTT::MQTT_Received()
{

}

void QSensorMQTT::onMQTT_Connected()
{

}

void QSensorMQTT::onMQTT_disconnected()
{

}

void QSensorMQTT::onMQTT_Received(const QString message)
{

}

void QSensorMQTT::MQTT_Publish(SensorNode node, QString message)
{

}

void QSensorMQTT::MQTT_Subcrib(SensorNode node)
{

}
