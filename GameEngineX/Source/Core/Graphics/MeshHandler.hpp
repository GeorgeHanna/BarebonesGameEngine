//
//  MeshHandler.hpp
//  GameEngineX
//
//  Created by George Hanna on 21/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef MeshHandler_hpp
#define MeshHandler_hpp

#include <stdio.h>
#include <string>
#include <fstream>

#include <map>

#include "Mesh.hpp"

class MeshHandler
{
    
public:
    std::string _path = "";
    std::map<std::string, std::weak_ptr<Mesh>> _meshes;

    void Initialize();
    MeshPtr GetMesh(std::string meshname, std::string meshpath);
    
};


#endif /* MeshHandler_hpp */
