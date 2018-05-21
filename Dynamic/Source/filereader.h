#ifndef FILEREADER_H
#define FILEREADER_H

#include "rep_filereader_source.h"

class FileReader : public FileReaderSource
{
    Q_OBJECT
public:
    FileReader(QObject *parent = 0);
    virtual QByteArray content() const override{
        return m_content;
    }

    virtual void read(QString path) override;
private:
    QByteArray m_content;
};

#endif // FILEREADER_H
