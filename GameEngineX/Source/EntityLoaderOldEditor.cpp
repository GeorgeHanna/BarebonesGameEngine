//
//  EntityLoaderOldEditor.cpp
//  GameEngineX
//
//  Created by George Hanna on 18/07/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "EntityLoaderOldEditor.hpp"



//string split helpers
//-------------------------
static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
static std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
//string split helpers end
//------------------


Entity* LoadGame()
{
    Entity* ret = new Entity();
    
    //else load new
    std::string path = Resources::GetRootPath();
    path  = path + "/ExportTest/ExportTest.mtl";
    std::ifstream ifs(path);
    std::string gameinfo( (std::istreambuf_iterator<char>(ifs) ),
                          (std::istreambuf_iterator<char>()    ) );
    
    std::vector<ActorInfo> actorinfos;
    std::vector<std::string> splitstringline = split(gameinfo, '\n');
    
    int i = 0;
    for (i = 0; i < splitstringline.size(); i+=3) {
        std::vector<std::string> splitstringspace = split(splitstringline[i], ' ');
        
        if(splitstringspace[0] == "actor" || splitstringspace[0] == "polygon" )
            break;
        
        ActorInfo actorinfo;
        actorinfo.id = splitstringspace[1].substr(0,splitstringspace[1].length()-1);
        splitstringspace = split(splitstringline[i+1], ' ');
        actorinfo.texturename = splitstringspace[1].substr(0,splitstringspace[1].length()-1);
        actorinfos.push_back(actorinfo);
    }
    
    for (; i < splitstringline.size(); i++) {
        std::vector<std::string> splitstringspace = split(splitstringline[i], ' ');
        
        for (int j = 0; j < actorinfos.size(); j++) {
            if(actorinfos[j].id == splitstringspace[1])
            {
                std::string texturename = actorinfos[j].texturename;
                std::string meshname = "testplane.obj";
                //if ground
                if(splitstringspace[0] == "polygon")
                {
                    std::string meshname = splitstringspace[2].substr(0,splitstringspace[2].length()-1);
                    ret->AddEntity(LoadGround(texturename + "," + meshname));
                }
                else
                {
                    std::string posx = splitstringspace[2];
                    std::string posy = splitstringspace[3];
                    std::string width = splitstringspace[4];
                    std::string height = splitstringspace[5];
                    
                    if(actorinfos[j].texturename == "frog.png")
                    {
                        ret->AddEntity(LoadKindler(texturename));
                    }
                    else if(actorinfos[j].texturename == "autumntree.png")
                    {
                        ret->AddEntity(LoadSprite(texturename + "," + meshname + "," + posx + "," + posy + "," + width + "," + height));
                    }
                }
            }
        }
    }
    
    /*
     newmtl 0
     map_Ka gray.png
     map_normal normalDefault.png
     newmtl 1
     map_Ka autumntree.png
     map_normal normalDefault.png
     newmtl 2
     map_Ka frog.png
     map_normal normalDefault.png
     actor 1 15.7421 8.062 60 58.4874 0
     actor 2 -131.612 47.3605 77.6048 14.5725 0
     polygon 0 ExportTest0.obj
     polygon 0 ExportTest1.obj
     polygon 0 ExportTest2.obj
     
     */
    return ret;
}
Entity* LoadKindler(const std::string& kindlerinfo)
{
    Entity* ret = new Entity();
    
    return ret;
}
Entity* LoadSwingingMushrooms(const std::string& mushroominfo)
{
    Entity* ret = new Entity();
    
    return ret;
}
Entity* LoadGround(const std::string& groundinfo)
{
    Entity* ret = new Entity();
    SpriteRenderComponentPtr sprite = SpriteRenderComponentPtr (new SpriteRenderComponent());
    PhysicsBody2DEdgeShapeComponentPtr physics = PhysicsBody2DEdgeShapeComponentPtr(new PhysicsBody2DEdgeShapeComponent());
    std::vector<std::string> groundarguments = split(groundinfo, ',');
    std::string texturename = groundarguments[0];
    std::string meshname = groundarguments[1];
    
    sprite->_meshname = meshname;
    sprite->_texturename = texturename;
    
    physics->_meshname = meshname;
    
    ret->AddComponent(sprite);
    ret->AddComponent(physics);
    //Get bbox pos
    //---------------------------
    std::string path = Resources::GetRootPath();
    path  = path + "/ExportTest/" + meshname;
    std::ifstream ifs(path);
    std::string meshinfo( (std::istreambuf_iterator<char>(ifs) ),
                         (std::istreambuf_iterator<char>()    ) );
    std::vector<std::string> bbox;
    std::vector<std::string> splitstringline = split(meshinfo, '\n');
    for (int i = 0; i<splitstringline.size(); i++) {
        std::string line = splitstringline[i];
        std::vector<std::string> splitline = split(line, ' ');
        if(splitline[0] == "bbox")
            bbox = splitline;
    }
    float bboxposx = std::stof(bbox[1]);
    float bboxposy = std::stof(bbox[2]);
    float bboxw = std::stof(bbox[3]);
    float bboxh = std::stof(bbox[4]);

    ret->_transformation._position.x = (bboxposx + bboxw/2) * 0.001;
    ret->_transformation._position.y = (bboxposy + bboxh/2) * 0.001;
    
    //----------------------------
    
    return ret;
}
Entity* LoadSprite(const std::string& spriteinfo)
{
    Entity* ret = new Entity();
    SpriteRenderComponentPtr sprite = SpriteRenderComponentPtr (new SpriteRenderComponent());

    std::vector<std::string> spritearguments = split(spriteinfo, ',');
    
    float posx = std::stof(spritearguments[2]);
    float posy = std::stof(spritearguments[3]);
    float width = std::stof(spritearguments[4]);
    float height = std::stof(spritearguments[5]);
    
    sprite->_texturename = spritearguments[0];
    sprite->_meshname = "testplane.obj";
    
    ret->AddComponent(sprite);
    
    ret->_transformation._position.x = (posx + width/2) * 0.001;
    ret->_transformation._position.y = (posy + height/2) * 0.001;
    ret->_transformation._scale = glm::vec3(width*0.001,height*0.001,1);
    
    return ret;
}
Entity* LoadAnimation(const std::string& animationinfo)
{
    Entity* ret = new Entity();
    
    return ret;
}