//
//  AnimationComponent.cpp
//  GameEngineX
//
//  Created by George Hanna on 17/07/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "AnimationComponent.hpp"

void AnimationComponent::Initialize()
{
    //Remove this when implementing proper loading of entities and resources
    _shaderprogram = Resources::AddSimpleShaderProgram("Vert.glsl", "Frag.glsl");
    _texture = Resources::GetTexture(_texturename);
    
    //Animations have their own mesh because they need to change buffer data
    SetupAnimationMesh();
    _currentframe = 0;
    _currentoffsetx = _offsetx;
    _currentoffsety = _offsety;
}

void AnimationComponent::Update(Timer* timer)
{
    Component::Update(timer);
    float timeperframe = _duration / _nrframes;
    _timeelapsed += timer->_dt;
    
    if(_timeelapsed > timeperframe)
    {
        if(_currentframe >= _nrframes && _loop)
        {
            //reset
            _currentoffsetx = _offsetx;
            _currentoffsety = _offsety;
            _currentframe = 0;
            _timeelapsed = 0;
        }
        else if(_currentframe < _nrframes)
        {
            if(_currentframe > 0)
            {
                _currentoffsetx += _framewidth;
                
                if(_currentoffsetx + _framewidth >= _texture->width())
                {
                    _currentoffsetx = 0;
                    _currentoffsety += _frameheight;
                }
            }
            _currentframe++;
        }
        
        _timeelapsed = 0;
    }
}

void AnimationComponent::Draw()
{
    Component::Draw();
    glm::mat4x4 mvpmatrix = _transformation._mvpmatrix;
    glm::mat4x4 mvmatrix = _transformation._mvmatrix;
    
    
    GLenum glErr;
    
    while ( ( glErr = glGetError() ) != GL_NO_ERROR) {
        std::cerr << glErr;
    }
    
    glUseProgram(_shaderprogram->_program);
    _mesh->BindVBO();
    
    std::vector<Vertex> updatedverts = _mesh->Vertices();
    
    updatedverts[0]._texcoord[0] = _currentoffsetx / _texture->width();
    updatedverts[0]._texcoord[1] = (_currentoffsety + _frameheight) / _texture->height();
    updatedverts[1]._texcoord[0] = (_currentoffsetx + _framewidth) / _texture->width();
    updatedverts[1]._texcoord[1] = (_currentoffsety + _frameheight) / _texture->height();
    updatedverts[2]._texcoord[0] = (_currentoffsetx + _framewidth) / _texture->width();
    updatedverts[2]._texcoord[1] = _currentoffsety / _texture->height();
    updatedverts[3]._texcoord[0] = _currentoffsetx / _texture->width();
    updatedverts[3]._texcoord[1] = _currentoffsety / _texture->height();
    
    /*
     vt 0.0000 1.0000
     vt 1.0000 1.0000
     vt 1.0000 0.0000
     vt 0.0000 0.0000
     */
    
    
    glBufferSubData(GL_ARRAY_BUFFER, 0, 4*sizeof(Vertex), &updatedverts[0]);
    
    //uniforms
    glUniformMatrix4fv(_shaderprogram->_mvpmatrix, 1, 0, &mvpmatrix[0][0]);
    glUniformMatrix4fv(_shaderprogram->_mvmatrix, 1, 0, &mvmatrix[0][0]);
    glUniform4f(_shaderprogram->_color, _color.x, _color.y, _color.z, _color.w);
    
    _texture->Bind(0);
    glUniform1i(_shaderprogram->_texture, 0);
    
    // 2
    glVertexAttribPointer(_shaderprogram->_positionattribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glVertexAttribPointer(_shaderprogram->_texcoordattribute, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) (sizeof(float) * 6));
    
    // 3
    //glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, (GLsizei)_mesh->NumberOfIndices(), GL_UNSIGNED_INT, 0);
}

void AnimationComponent::SetupAnimationMesh()
{
    _mesh = MeshPtr(new Mesh());
    std::vector<unsigned int> indices;

    //f1
    indices.push_back(0);
    //_mesh->_indices.push_back(0);
    //_mesh->_indices.push_back(0);
    //f2
    indices.push_back(1);
    indices.push_back(2);
    //_mesh->_indices.push_back(2);
    //_mesh->_indices.push_back(2);
    //f4
    indices.push_back(2);
    //_mesh->_indices.push_back(2);
    //_mesh->_indices.push_back(2);
    //f5
    indices.push_back(3);
    //_mesh->_indices.push_back(3);
    //_mesh->_indices.push_back(3);
    //f6
    indices.push_back(0);
    //_mesh->_indices.push_back(0);
    //_mesh->_indices.push_back(0);



    Vertex v1;
    Vertex v2;
    Vertex v3;
    Vertex v4;
    
    v1.SetPosition(-0.1f, -0.1f, 0.0f);
    v2.SetPosition(0.1f, -0.1f, 0.0f);
    v3.SetPosition(0.1f, 0.1f, 0.0f);
    v4.SetPosition(-0.1f, 0.1f, 0.0f);
    v1.SetTexcoord(0, 1);
    v2.SetTexcoord(1, 1);
    v3.SetTexcoord(1, 0);
    v4.SetTexcoord(0, 0);
    
    std::vector<Vertex> vertices;
    vertices.push_back(v1);
    vertices.push_back(v2);
    vertices.push_back(v3);
    vertices.push_back(v4);

    _mesh->Initialize(vertices, indices);
    
    /*
     v -100.5000 -100.5000 0.0
     v 100.5000 -100.5000 0.0
     v 100.5000 100.5000 0.0
     v -100.5000 100.5000 0.0
     
     vt 0.0000 1.0000
     vt 1.0000 1.0000
     vt 1.0000 0.0000
     vt 0.0000 0.0000
     
     vn -0.7071 -0.7071 0.0
     vn 0.7071 -0.7071 0.0
     vn 0.7071 0.7071 0.0
     vn -0.7071 0.7071 0.0
     
     f 0/0/0 1/1/1 2/2/2
     f 2/2/2 3/3/3 0/0/0
     
     */
}
