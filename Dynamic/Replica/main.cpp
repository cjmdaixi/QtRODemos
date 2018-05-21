#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QRemoteObjectNode>
#include <QRemoteObjectDynamicReplica>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QRemoteObjectNode node;
    node.connectToNode(QUrl("local:filereader"));
    auto replica = node.acquireDynamic("FileReader");

    engine.rootContext()->setContextProperty("$replica", replica);
    QObject::connect(replica, &QRemoteObjectDynamicReplica::initialized, &app, [&](){
        engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    });


    auto result = app.exec();
    delete replica;
    return result;
}
