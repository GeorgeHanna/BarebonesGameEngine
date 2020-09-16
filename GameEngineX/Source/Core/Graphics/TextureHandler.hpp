//
//  TextureHandler.hpp
//  GameEngineX
//
//  Created by George Hanna on 22/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef TextureHandler_hpp
#define TextureHandler_hpp

#include <stdio.h>
#include <string>
#include <map>
#include <memory>
#include "Texture.hpp"

class TextureHandler {
public:
    std::string _path = "";
    std::map<std::string, std::weak_ptr<Texture>> _textures;

    ~TextureHandler();
    void Initialize();
    TexturePtr GetTexture(std::string texturename, std::string texturepath);
};



#endif /* TextureHandler_hpp */
