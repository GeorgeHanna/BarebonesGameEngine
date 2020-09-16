//
//  MeshHandler.cpp
//  GameEngineX
//
//  Created by George Hanna on 21/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "MeshHandler.hpp"


    
void MeshHandler::Initialize()
{
    
}

MeshPtr MeshHandler::GetMesh(std::string meshname, std::string meshpath)
{
    //if loaded return the one i memory
    std::map<std::string, std::weak_ptr<Mesh>>::const_iterator it = _meshes.find(meshname);
    if(it != _meshes.end())
    {
        if(it->second.expired()) {
            _meshes.erase(it);
        }
        else
            return it->second.lock();
    }
    //else load new
    std::ifstream ifs(meshpath);
    std::string objstring( (std::istreambuf_iterator<char>(ifs) ),
                        (std::istreambuf_iterator<char>()    ) );
    
    MeshPtr mesh = MeshPtr(new Mesh());
    mesh->LoadFromString(objstring);
    
    //add to map
    _meshes[meshname] = mesh;
    
    return mesh;
}
