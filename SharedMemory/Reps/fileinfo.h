#ifndef FILEINFO_H
#define FILEINFO_H

#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <QVector3D>

class FileInfo{
public:
    FileInfo(boost::interprocess::managed_shared_memory segment){
        using namespace boost::interprocess;
        typedef allocator<float[3], managed_shared_memory::segment_manager>  VertexAllocator;
        typedef allocator<unsigned[3], managed_shared_memory::segment_manager>  TriangleAllocator;

        typedef boost::interprocess::offset_ptr<boost::interprocess::vector<unsigned int[3]> > VERTICES;
        typedef boost::interprocess::offset_ptr<boost::interprocess::vector<unsigned int[3]> > TRIANGLES;
        const VertexAllocator alloc_vertices (segment.get_segment_manager());
        m_vertices = segment.construct<FileInfo>("MyVector")(alloc_inst);
    }
    boost::interprocess::offset_ptr<boost::interprocess::vector<unsigned int[3]> > m_vertices;
    boost::interprocess::offset_ptr<boost::interprocess::vector<unsigned int[3]> > m_triangles;
};

#endif
