//
//  TileHandler.cpp
//  GameEngineX
//
//  Created by George Hanna on 17/09/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "TileHandlerComponent.hpp"

namespace Beams {
    
    void TileHandlerComponent::Initialize()
    {
    }
    
    void TileHandlerComponent::Update(Timer *timer)
    {
        std::vector<int> beamsdone;
        //for all beams
        //if moving = false
        //check which tile is last
        //perform beam adjustment by each tile
        for (int i = 0; i<beams.size(); i++) {
            if(!beams[i]->moving)
            {
                glm::vec2 beamend = glm::vec2(beams[i]->endpos.x, beams[i]->endpos.y);
                for (int j = 0; j<tiles.size(); j++) {
                    glm::vec2 tilepos = glm::vec2(tiles[j]->_parent->_transformation._position.x, tiles[j]->_parent->_transformation._position.y);

                    if(beamend == tilepos)
                    {
                        if(tiles[j]->tiletype == Tiletype::empty)
                            SendBeam(tiles[j], beams[i]->movementdir);
                        else if(tiles[j]->tiletype == Tiletype::reflectbeam)
                            SendBeam(tiles[j], glm::vec2(beams[i]->movementdir.y, beams[i]->movementdir.x));
                        else if(tiles[j]->tiletype == Tiletype::reflectbeamswitch)
                            SendBeam(tiles[j], glm::vec2(-beams[i]->movementdir.y, -beams[i]->movementdir.x));
                        
                    }
                }
                beamsdone.push_back(i);
            }
        }
        
        for (int i = 0; i<beamsdone.size(); i++) {
            beams.erase(beams.begin() + beamsdone[i]);
        }
        
        //if all end tiles have beams inside
        //end level
        //else restart
        
    }
    
    void TileHandlerComponent::SendBeam(TileComponentPtr fromtile, glm::vec2 direction)
    {
        Entity* beament = new Entity();
        BeamComponentPtr beam = BeamComponentPtr(new BeamComponent());
        beam->movementdir = direction;
        beam->moving = true;
        beam->timetodestination = 0.5;
        beament->_transformation._position = fromtile->_parent->_transformation._position;
        beament->_transformation._position.z = 1;
        beament->AddComponent(beam);
        _parent->AddEntity(beament);
        beams.push_back(beam);
    }
    
    void TileHandlerComponent::SendBeamsFromStart()
    {
        int nrtiles = _parent->_entities.size();
        for (int i = 0; i<nrtiles; i++) {
            TileComponentPtr tile = std::static_pointer_cast<TileComponent>(_parent->_entities[i]->_components[TileComponent::GetType_s()]);
            if(tile == nullptr)
                continue;
            if(tile->tiletype == Tiletype::startbeam)
            {
                SendBeam(tile, {1,0});
            }
        }
    }
    
    void TileHandlerComponent::CreateTileBoardFromFile(std::string filepath)
    {
        std::ifstream ifs(filepath);
        std::string boardstring( (std::istreambuf_iterator<char>(ifs) ),
                                (std::istreambuf_iterator<char>()    ) );
        
        
        std::vector<std::string> lines = StringHelpers::split(boardstring, '\n');
        rows = lines.size();
        columns = lines[0].size();
        
        
        for (int i = 0; i<rows; i++) {
            
            for (int j=0; j<columns; j++) {
                
                Entity* tile = new Entity();
                TileComponentPtr tilecomponent = TileComponentPtr(new TileComponent());
                if(lines[i][j] == '-')
                    tilecomponent->tiletype = Tiletype::empty;
                else if(lines[i][j] == 's')
                    tilecomponent->tiletype = Tiletype::startbeam;
                else if(lines[i][j] == 'e')
                    tilecomponent->tiletype = Tiletype::endbeam;
                else if(lines[i][j] == '/')
                    tilecomponent->tiletype = Tiletype::reflectbeam;
                else if(lines[i][j] == '\\')
                    tilecomponent->tiletype = Tiletype::reflectbeamswitch;
                
                tile->AddComponent(tilecomponent);
                
                tile->_transformation._position.x = j+0.5f;
                tile->_transformation._position.y = rows - i + 2;
                
                _parent->AddEntity(tile);
                
                tiles.push_back(tilecomponent);
            }
        }        
    }
    
}