#include <QGuiApplication>
#include "AppEngine.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    AppEngine engine;
    engine.initEngine();
    engine.startApplication();

    return app.exec();
}
