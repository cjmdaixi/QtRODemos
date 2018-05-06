#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "rep_filereader_replica.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QRemoteObjectNode node;
    node.connectToNode(QUrl("local:filereader"));
    auto replica = node.acquire<FileReaderReplica>();

    engine.rootContext()->setContextProperty("$replica", replica);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    auto result = app.exec();
    delete replica;
    return result;
}
