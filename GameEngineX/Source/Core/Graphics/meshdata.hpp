#ifndef MESHDATA_H
#define MESHDATA_H
#include <vector>
#include <string>
#include "vertex.hpp"

class MeshData
{
public:
    MeshData();
    static MeshData FromObjFile(const std::string& objstring);

    std::vector<Vertex> _vertices;
    std::vector<unsigned int> _indices;
};

#endif // MESHDATA_H
