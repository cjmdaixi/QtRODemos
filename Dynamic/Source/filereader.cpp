#include "filereader.h"
#include <QFile>
#include <QtDebug>

FileReader::FileReader(QObject *parent)
    : FileReaderSource(parent)
{
    qDebug()<<"created";
}

void FileReader::read(QString path)
{
    QFile inf(path);
    if(!inf.exists()){
        qWarning()<<"file"<<path<<"does not exist!";
        return;
    }
    if(!inf.open(QIODevice::ReadOnly)){
        qWarning()<<"cannot open file"<<path;
        return;
    }
    m_content = inf.readAll();
    emit contentChanged(m_content);
}
