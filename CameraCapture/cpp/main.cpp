#include <QGuiApplication>>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "cpp/CameraCapture.h"
#include "cpp/MVideoPlayerItem.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<CameraCapture>("MohsenCpp", 1, 0, "CameraCapture");
    qmlRegisterType<MVideoPlayerItem>("MohsenCpp", 1, 0, "MVideoPlayerItem");

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");

    engine.load("qrc://qml/main.qml");

    return app.exec();
}
