#include "filereader.h"
#include <QFile>
#include <QtDebug>


#include "fileinfo.h"

FileReader::FileReader(QObject *parent)
    : FileReaderSource(parent)
{
    using namespace boost::interprocess;
    qDebug()<<"created";
    m_sharedMemory =
            managed_shared_memory(create_only, "MySharedMemory", 65536);

    managed_shared_memory::size_type free_memory = m_sharedMemory.get_free_memory();
    qDebug()<<"sizeof size_type:"<<sizeof(free_memory);



}

void FileReader::read(QString path)
{
    using namespace boost::interprocess;
    typedef allocator<int, managed_shared_memory::segment_manager>  ShmemAllocator;

    const ShmemAllocator alloc_inst (m_sharedMemory.get_segment_manager());

    //Construct a vector named "MyVector" in shared memory with argument alloc_inst
    FileInfo *myvector = m_sharedMemory.construct<FileInfo>("MyVector")(alloc_inst);
}
