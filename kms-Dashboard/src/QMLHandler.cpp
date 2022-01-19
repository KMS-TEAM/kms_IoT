#include "QMLHandler.h"

QMLHandler *QMLHandler::m_instance = nullptr;

QMLHandler *QMLHandler::getInstance()
{
    if (nullptr == m_instance)
    {
        m_instance = new QMLHandler();
    }
    return m_instance;
}

void QMLHandler::qmlSendEvent(int event)
{
    emit notifyQMLEvent(event);
}

void QMLHandler::qmlMessage(QString msg)
{

}

QMLHandler::QMLHandler()
{

}
