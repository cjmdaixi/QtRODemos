#include <QCoreApplication>
#include "filereader.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QRemoteObjectHost host;
    host.setHostUrl(QUrl("local:filereader"));
    auto fileReader = new FileReader;
    host.enableRemoting(fileReader, QStringLiteral("FileReader"));

    auto result = app.exec();
    host.disableRemoting(fileReader);
    return result;
}
