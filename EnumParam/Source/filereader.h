#ifndef FILEREADER_H
#define FILEREADER_H

#include "rep_filereader_source.h"

class FileReader : public FileReaderSource
{
    Q_OBJECT
public:
    FileReader(QObject *parent = 0);

    FileStatus fe() const override {return m_fe;}
    void setFe(FileReaderSource::FileStatus newFe) override;
private:
    FileStatus m_fe = FS_OK;
};

#endif // FILEREADER_H
