#ifndef APPENUMS_H
#define APPENUMS_H

#include <QObject>

class AppEnums : public QObject
{
    Q_OBJECT
public:

    enum E_SCREEN_t
    {
        SearchScreen = 0,
        HomeScreen,
        ControlScreen,
        MapScreen,
        UserScreen,
    };
    Q_ENUM(E_SCREEN_t)

    enum E_EVENT_t
    {
        UserClickSearch = 0,
        UserClickHome,
        UserClickControl,
        UserClickMap,
        UserClickAccount,
    };
    Q_ENUM(E_EVENT_t)

signals:

};

#endif // APPENUMS_H
