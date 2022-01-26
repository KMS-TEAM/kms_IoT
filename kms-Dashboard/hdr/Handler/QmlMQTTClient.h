#ifndef QMLMQTTCLIENT_H
#define QMLMQTTCLIENT_H

#include <QObject>
#include <QtMqtt/QMqttClient>
#include <QtMqtt/QMqttSubscription>
#include "QSensorMQTT.h"

class QmlMqttClient;

// Topic Subscription Class
class QmlMqttSubscription : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QMqttTopicFilter topic MEMBER m_topic NOTIFY topicChanged)

public:
    QmlMqttSubscription(QMqttSubscription *sub, QmlMqttClient *client);
    ~QmlMqttSubscription() {};

signals:
    void topicChanged(QString topic);
    void messageReceived(const QString &msg);

public slots:
    void handleMessage(const QMqttMessage &qmsg);

private:
    Q_DISABLE_COPY(QmlMqttSubscription);
    QMqttSubscription *m_sub;
    QmlMqttClient *m_client;
    QMqttTopicFilter m_topic;
};

// Client Class
class QmlMqttClient : public QMqttClient
{
    Q_OBJECT
public:
    explicit QmlMqttClient(QObject *parent = nullptr);

    Q_INVOKABLE QmlMqttSubscription *subcribe(const QString &topic);

private:
    Q_DISABLE_COPY(QmlMqttClient)

signals:

};

#endif // QMLMQTTCLIENT_H
