//
//  TextureHandler.cpp
//  GameEngineX
//
//  Created by George Hanna on 22/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "TextureHandler.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

TextureHandler::~TextureHandler() {
    _textures.clear();
}

void TextureHandler::Initialize()
{
}

TexturePtr TextureHandler::GetTexture(std::string texturename, std::string texturepath)
{
    //if loaded return the one i memory
    auto it = _textures.find(texturename);
    if(it != _textures.end()) {
        std::weak_ptr<Texture> texw = it->second;
        if(texw.expired()) {
            _textures.erase(it);
        }
        else
            return it->second.lock();
    }

    
    int width,height, comp;
    unsigned char* pixeldata = stbi_load(texturepath.c_str(), &width, &height, &comp, STBI_rgb_alpha);
    
    TexturePtr texture = TexturePtr(new Texture());
    texture->Initialize(width, height, false, pixeldata);
    
    //add to map
    _textures[texturename] = texture;
    
    return texture;
}
