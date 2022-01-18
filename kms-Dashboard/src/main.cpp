#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/qml/main.qml")));

    if(engine.rootObjects().isEmpty())
    {
        return -1;
    }

    return app.exec();
}
