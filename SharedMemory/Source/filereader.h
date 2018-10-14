#ifndef FILEREADER_H
#define FILEREADER_H

#include "rep_filereader_source.h"
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/mapped_region.hpp>

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
    boost::interprocess::managed_shared_memory m_sharedMemory;
};

#endif // FILEREADER_H
