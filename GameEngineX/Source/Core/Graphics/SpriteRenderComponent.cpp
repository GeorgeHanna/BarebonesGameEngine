//
//  SpriteRenderComponent.cpp
//  GameEngineX
//
//  Created by George Hanna on 21/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "SpriteRenderComponent.hpp"

SpriteRenderComponent::SpriteRenderComponent()
{
    _color = glm::vec4(1,1,1,1);
}

void SpriteRenderComponent::Initialize()
{
    //Remove this when implementing proper loading of entities and resources
    _shaderprogram = Resources::AddSimpleShaderProgram("Vert.glsl", "Frag.glsl");
    _mesh = Resources::GetMesh(_meshname);
    _texture = Resources::GetTexture(_texturename);

}



void SpriteRenderComponent::Draw()
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
