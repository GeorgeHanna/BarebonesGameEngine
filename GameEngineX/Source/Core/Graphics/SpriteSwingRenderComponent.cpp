//
//  SpriteSwingRenderComponent.cpp
//  GameEngineX
//
//  Created by Stefan Söderberg on 2016-07-17.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "SpriteSwingRenderComponent.hpp"
#include <math.h>

SpriteSwingRenderComponent::SpriteSwingRenderComponent(float theBendFactor, float theSpeed, bool willExpand, bool inSync, bool reverseBend)
{
    speed = theSpeed;
    bend = theBendFactor;
    expand = willExpand;
    sync = inSync;
    reverse = reverseBend;
}

void SpriteSwingRenderComponent::Initialize()
{
    //Remove this when implementing proper loading of entities and resources
    _lightshaderprogram = Resources::AddSimpleSwingShaderProgram("SwingVert.glsl", "SwingFrag.glsl");
    _mesh = Resources::GetMesh(_meshname);
    _texture = Resources::GetTexture(_texturename);
    _normalmap = Resources::GetTexture(_normalmapname);
    
    //randomTime = 0.0;
    offset = (float)(rand()%100 +10);
}

void SpriteSwingRenderComponent::Update(Timer* timer)
{
    Component::Update(timer);
    
    //test move
    time = timer->_totalelapsedtime;
    //Calculate leading bend for all from windpower varying randomly
    
    /*
     //When random timeinteval reached create random speed and bend
     if(randomTime == 0 || (timer->_totalelapsedtime - lastTotalTime) > randomTime)
     {
     lastTotalTime = timer->_totalelapsedtime;
     //Create random secondInterval between 0.2s to 1s
     randomTime = (float)(rand()%100 +10)/10.0;
     
     //Create random speed and bend
     oldRandomBend = randomBend;
     randomBend = (float)(rand()%(1-10 + 1) + 1)/100.0;
     
     //Create random speed and bend
     oldRandomSpeed = randomSpeed;
     randomSpeed = (rand()%20+10)/10.0;
     // 1.0 - 2.0
     }
     
     //glUniform1f(_lightshaderprogram->_speed, randomSpeed);
     
     //glUniform1f(_lightshaderprogram->_bendFactor, randomBend);
     if(fabsf(randomSpeed - currentSpeed) < 0.02)
     {
     
     }
     else if(randomSpeed > currentSpeed)
     {
     currentSpeed = currentSpeed + 0.01;
     }//lerp(timer->_dt/1000, oldRandomSpeed, randomSpeed);
     else
     {
     currentSpeed = currentSpeed - 0.01;
     }
     currentPos = (sin((timer->_totalelapsedtime * currentSpeed)) * 0.01);
     glUniform1f(_lightshaderprogram->_time, currentPos);
     */
}


void SpriteSwingRenderComponent::Draw()
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
    
    float theTime;
    if(sync)
    {
        theTime = time;
    }
    else
    {
        theTime = time+offset;
    }
    float in_offset = (sin(theTime * speed) * bend);
    glUniform1f(_lightshaderprogram->_offset, in_offset);
    float expandVal;
    if(expand)
        expandVal = time+offset;
    else
        expandVal = 0;
    glUniform1f(_lightshaderprogram->_time, expandVal);
    glUniform1f(_lightshaderprogram->_reverse, reverse);
    //glUniform1f(_lightshaderprogram->_speed, speed);
    //glUniform1f(_lightshaderprogram->_bend, bend);
    
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
    
    
    /*
     _texture->Bind(0);
     
     _normalmap->Bind(1);
     */
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _texture->_texture);
    glUniform1i(_lightshaderprogram->_texture, 0);
    
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, _normalmap->_texture);
    glUniform1i(_lightshaderprogram->_normalmap, 1);
    
    // 2
    glVertexAttribPointer(_lightshaderprogram->_positionattribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glVertexAttribPointer(_lightshaderprogram->_normalattribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) (sizeof(float) * 3));
    glVertexAttribPointer(_lightshaderprogram->_texcoordattribute, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) (sizeof(float) * 6));
    glVertexAttribPointer(_lightshaderprogram->_colorattribute, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*) (sizeof(float) * 8));
    
    
    
    
    
    // 3
    //glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, (GLsizei)_mesh->_indices.size(), GL_UNSIGNED_INT, 0);
    while ( ( glErr = glGetError() ) != GL_NO_ERROR) {
        std::cerr << glErr;
    }
    
}