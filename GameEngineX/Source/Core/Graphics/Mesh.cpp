//
//  Mesh.cpp
//  GameEngineX
//
//  Created by George Hanna on 21/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "Mesh.hpp"
#include "../Common/stringhelpers.h"

Mesh::~Mesh() {
    glDeleteBuffers(1, &_vertexbuffer);
    glDeleteBuffers(1, &_indexbuffer);
}

void Mesh::Initialize(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
{
    _vertices = vertices;
    _indices = indices;
    // Setup VBO
    glGenBuffers(1, &_vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices[0]) * _vertices.size(), &_vertices[0], GL_STATIC_DRAW);
    
    glGenBuffers(1, &_indexbuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexbuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * _indices.size(), &_indices[0], GL_STATIC_DRAW);
}

void Mesh::BindVBO()
{
    glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexbuffer);
}

void Mesh::addVertex(const Vertex &vertex)
{
  _vertices.push_back(vertex);
}

void Mesh::addIndex(unsigned int index)
{
  _indices.push_back(index);
}

unsigned int Mesh::NumberOfIndices() const
{
  return _indices.size();
}

const std::vector<Vertex> &Mesh::Vertices() const
{
  return _vertices;
}
void Mesh::LoadFromString(std::string objstring)
{
    _vertices.clear();
    _indices.clear();
    
    std::vector<std::vector<float>> vertpositions;
    std::vector<std::vector<float>> vertnormals;
    std::vector<std::vector<float>> verttexcoords;
    
    std::vector<std::string> lines = StringHelpers::split(objstring, '\n');
    for (auto it = lines.begin(); it != lines.end(); it++) {
        std::vector<std::string> words = StringHelpers::split(*it, ' ');
        if(words.size() < 1)
            continue;
        if(words[0] == "v")
        {
            float vpos[3];
            vpos[0] = atof(words[1].c_str());
            vpos[1] = atof(words[2].c_str());
            vpos[2] = atof(words[3].c_str());
            
            //Divide by 100 since polygons are large and 1 in the physics engine means 1 meter while polygons are curently larger than 100 in "size" making movements in the physics engine look slow.
            //Remove this when it has been fixed in the editor
            /*
            vpos[0] *= 2;
            vpos[1] *= 2;
            vpos[2] *= 2;
            
            printf("\nv %f %f %f 1", vpos[0], vpos[1], vpos[2]);
            */
            vertpositions.push_back({vpos[0], vpos[1], vpos[2]});
            //_vertices.push_back()
        }
        if(words[0] == "vn")
        {
            float vnorm[3];
            vnorm[0] = atof(words[1].c_str());
            vnorm[1] = atof(words[2].c_str());
            vnorm[2] = atof(words[3].c_str());
            vertnormals.push_back({vnorm[0], vnorm[1], vnorm[2]});
            //_vertices.push_back()
        }
        else if (words[0] == "vt")
        {
            float vtex[2];
            vtex[0] = atof(words[1].c_str());
            vtex[1] = atof(words[2].c_str());
            verttexcoords.push_back({vtex[0], vtex[1]});
        }
        else if (words[0] == "f")
        {
            std::vector<std::string> faceindex1 = StringHelpers::split(words[1], '/');
            std::vector<std::string> faceindex2 = StringHelpers::split(words[2], '/');
            std::vector<std::string> faceindex3 = StringHelpers::split(words[3], '/');
            unsigned int index1 = atoi(faceindex1[0].c_str());
            unsigned int index2 = atoi(faceindex2[0].c_str());
            unsigned int index3 = atoi(faceindex3[0].c_str());
            //index -1 because face indices start at 1 in obj format
            _indices.push_back(index1-1);
            _indices.push_back(index2-1);
            _indices.push_back(index3-1);
            //printf("\nf %d/%d/%d %d/%d/%d %d/%d/%d", index1+1, index1+1, index1+1, index2+1, index2+1, index2+1, index3+1, index3+1, index3+1);
        }
    }
    
    
    // Adjust vertpositions to be centered around 0,0,0
    float mincoords[3] = {vertpositions[0][0], vertpositions[0][1],vertpositions[0][2]};
    float maxcoords[3] = {vertpositions[0][0], vertpositions[0][1],vertpositions[0][2]};
    for (int i = 0; i<vertpositions.size(); i++) {
        //min
        if(mincoords[0] > vertpositions[i][0])
            mincoords[0] = vertpositions[i][0];
        if(mincoords[1] > vertpositions[i][1])
            mincoords[1] = vertpositions[i][1];
        if(mincoords[2] > vertpositions[i][2])
            mincoords[2] = vertpositions[i][2];
        //max
        if(maxcoords[0] < vertpositions[i][0])
            maxcoords[0] = vertpositions[i][0];
        if(maxcoords[1] < vertpositions[i][1])
            maxcoords[1] = vertpositions[i][1];
        if(maxcoords[2] < vertpositions[i][2])
            maxcoords[2] = vertpositions[i][2];
        
    }
    
    float xminzerodiff =  - mincoords[0];
    float yminzerodiff =  - mincoords[1];
    float zminzerodiff =  - mincoords[2];
    
    float xminmaxdiff = maxcoords[0] - mincoords[0];
    float yminmaxdiff = maxcoords[1] - mincoords[1];
    float zminmaxdiff = maxcoords[2] - mincoords[2];
    
    for (int i = 0; i<vertpositions.size(); i++) {
        vertpositions[i][0] = vertpositions[i][0] + xminzerodiff - (xminmaxdiff/2);
        vertpositions[i][1] = vertpositions[i][1] + yminzerodiff - (yminmaxdiff/2);
        vertpositions[i][2] = vertpositions[i][2] + zminzerodiff - (zminmaxdiff/2);
    }
    
    // Save mesh data
    for (int i = 0; i < vertpositions.size(); i++) {
        Vertex vertex;
        vertex._position[0] = vertpositions[i][0];
        vertex._position[1] = vertpositions[i][1];
        vertex._position[2] = vertpositions[i][2];
        vertex._normal[0] = vertnormals[i][0];
        vertex._normal[1] = vertnormals[i][1];
        vertex._normal[2] = vertnormals[i][2];
        vertex._texcoord[0] = verttexcoords[i][0];
        vertex._texcoord[1] = verttexcoords[i][1];
        _vertices.push_back(vertex);
    }
    Initialize(_vertices, _indices);

}


