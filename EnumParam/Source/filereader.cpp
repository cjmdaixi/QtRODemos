#include "filereader.h"
#include <QFile>
#include <QtDebug>

FileReader::FileReader(QObject *parent)
    : FileReaderSource(parent)
{
    qDebug()<<"created";
}

void FileReader::setFe(FileReaderSource::FileStatus newFe)
{
    if(m_fe == newFe) return;
    m_fe = newFe;
    emit feChanged(m_fe);
    emit statusRenewed(m_fe);
}
