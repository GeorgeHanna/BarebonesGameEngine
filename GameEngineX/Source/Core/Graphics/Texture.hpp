//
//  Texture.hpp
//  GameEngineX
//
//  Created by George Hanna on 22/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "openglinclude.h"


class Texture {

public:
    ~Texture();
    void Initialize(int width, int height, bool repeat, unsigned char* pixeldata);
    void Bind(unsigned int unit);
    float width() const;
    float height() const;
    GLuint _texture;

private:
    float _width;
    float _height;
    bool _repeat;
};
typedef std::shared_ptr<Texture> TexturePtr;
#endif /* Texture_hpp */
