//
//  SpriteLightRenderComponent.cpp
//  GameEngineX
//
//  Created by George Hanna on 02/07/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "SpriteLightRenderComponent.hpp"


void SpriteLightRenderComponent::Initialize()
{
  //Remove this when implementing proper loading of entities and resources
    _lightshaderprogram = Resources::AddSimpleLightingShaderProgram(std::string("LightingVert.glsl"), std::string("LightingFrag.glsl"));
    _mesh = Resources::GetMesh(_meshname);
    _texture = Resources::GetTexture(_texturename);
    Resources::GetPhysicsWorld("1")->_collisionlistener->AddCollisionEventListener(std::bind(&SpriteLightRenderComponent::Collided, this, std::placeholders::_1));
}

void SpriteLightRenderComponent::Collided(Contact* contact)
{
    //printf("hej");
}

void SpriteLightRenderComponent::Draw()
{
    glm::mat4x4 mvpmatrix = _transformation._mvpmatrix;
    glm::mat4x4 mvmatrix = _transformation._mvmatrix;
    glm::mat4x4 mmatrix = _transformation._mmatrix;
    
    std::vector<float> directionallightdirection = Resources::GetLightHandler()->GetDirectionalLightDirection();
    std::vector<float> directionallightcolor = Resources::GetLightHandler()->GetDirectionalLightColor();
    float ambient = Resources::GetLightHandler()->GetDirectionalLightAmbient();
    
    std::vector<float> pointlightpositions = Resources::GetLightHandler()->GetPointLightPositions();
    std::vector<float> pointlightcolors = Resources::GetLightHandler()->GetPointLightColors();
    std::vector<float> pointlightsizes = Resources::GetLightHandler()->GetPointLightSizes();
    

    
    GLenum glErr;
    
    while ( ( glErr = glGetError() ) != GL_NO_ERROR) {
        std::cerr << glErr;
    }
    
    glUseProgram(_lightshaderprogram->_program);
    _mesh->BindVBO();
    
    //uniforms
    glUniformMatrix4fv(_lightshaderprogram->_mvpmatrix, 1, 0, &mvpmatrix[0][0]);
    glUniformMatrix4fv(_lightshaderprogram->_mvmatrix, 1, 0, &mvmatrix[0][0]);
    glUniformMatrix4fv(_lightshaderprogram->_mmatrix, 1, 0, &mmatrix[0][0]);
    
    glUniform3f(_lightshaderprogram->_directionallightdir, directionallightdirection[0], directionallightdirection[1], directionallightdirection[2]);
    glUniform3f(_lightshaderprogram->_directionallightcol, directionallightcolor[0], directionallightcolor[1], directionallightcolor[2]);
    glUniform1f(_lightshaderprogram->_directionallightambient, ambient);
    
    glUniform3fv(_lightshaderprogram->_pointlightpositions, (GLsizei) pointlightpositions.size()/3, &pointlightpositions[0]);
    glUniform3fv(_lightshaderprogram->_pointlightcolors, (GLsizei) pointlightcolors.size() / 3, &pointlightcolors[0]);
    glUniform1fv(_lightshaderprogram->_pointlightsizes, (GLsizei) pointlightsizes.size(), &pointlightsizes[0]);
    
    _texture->Bind(0);
    glUniform1i(_lightshaderprogram->_texture, 0);
    
    // 2
    glVertexAttribPointer(_lightshaderprogram->_positionattribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glVertexAttribPointer(_lightshaderprogram->_normalattribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) (sizeof(float) * 3));
    glVertexAttribPointer(_lightshaderprogram->_texcoordattribute, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) (sizeof(float) * 6));
    //glVertexAttribPointer(_lightshaderprogram->_colorattribute, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) (sizeof(float) * 8));
    
    
    
    
    // 3
    //glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, (GLsizei)_mesh->NumberOfIndices(), GL_UNSIGNED_INT, 0);
    
    
}
