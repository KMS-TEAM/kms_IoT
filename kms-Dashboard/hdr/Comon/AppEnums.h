#ifndef APPENUMS_H
#define APPENUMS_H

#include <QObject>

class AppEnums : public QObject
{
    Q_OBJECT

    Q_ENUMS(E_SCREEN_t)
    Q_ENUMS(E_EVENT_t)

public:

    enum E_SCREEN_t
    {
        SearchScreen = 0,
        HomeScreen,
        ControlScreen,
        MapScreen,
        UserScreen,
    };

    enum E_EVENT_t
    {
        UserClickSearch = 0,
        UserClickHome,
        UserClickControl,
        UserClickMap,
        UserClickAccount,
    };

signals:

};

#endif // APPENUMS_H
