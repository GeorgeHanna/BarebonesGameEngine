//
//  Mesh.hpp
//  GameEngineX
//
//  Created by George Hanna on 21/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include "openglinclude.h"
#include "vertex.hpp"



class Mesh
{
public:
    ~Mesh();
    
    void Initialize(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices);
    void BindVBO();
    void addVertex(const Vertex& vertex);
    void addIndex(unsigned int index);
    unsigned int NumberOfIndices() const;
    const std::vector<Vertex>& Vertices() const;
    void LoadFromString(std::string objstring);

    std::vector<Vertex> _vertices;
    std::vector<unsigned int> _indices;
private:

    GLuint _vertexbuffer;
    GLuint _indexbuffer;

};
typedef std::shared_ptr<Mesh> MeshPtr;
#endif /* Mesh_hpp */
