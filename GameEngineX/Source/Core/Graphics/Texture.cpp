//
//  Texture.cpp
//  GameEngineX
//
//  Created by George Hanna on 22/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "Texture.hpp"

Texture::~Texture() {
    glDeleteTextures(1, &_texture);
    _texture = 0;
}

void Texture::Initialize(int width, int height, bool repeat, unsigned char* pixeldata)
{
    _width = width;
    _height = height;
    _repeat = repeat;
    
    GLenum glErr;

    while ( ( glErr = glGetError() ) != GL_NO_ERROR) {
        std::cerr << glErr;
    }
    
    glGenTextures(1, &_texture);
    glBindTexture(GL_TEXTURE_2D, _texture);

    
    GLint texturewrapmode = GL_REPEAT;
    if(_repeat)
        texturewrapmode = GL_REPEAT;
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, texturewrapmode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, texturewrapmode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixeldata);
    while ( ( glErr = glGetError() ) != GL_NO_ERROR) {
        std::cerr << glErr;
    }
    
    glBindTexture(GL_TEXTURE_2D, 0);

    //glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture::Bind(unsigned int unit) {
  glActiveTexture(GL_TEXTURE0 + unit);
  glBindTexture(GL_TEXTURE_2D, _texture);
}

float Texture::width() const
{
  return _width;
}

float Texture::height() const
{
  return _height;
}
