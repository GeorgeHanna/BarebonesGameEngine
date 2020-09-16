//
//  Game.cpp
//  GameEngineX
//
//  Created by George Hanna on 20/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "Game.hpp"

namespace Game {



    Game::Game()
    {
        _maincamera = CameraPtr(new Camera());
        _maintimer = new Timer();
    }
    
    void Game::Initialize()
    {
        
        InputHandler::Initialize();
        TransformationMatrixStack::Initialize();
        _maincamera->Initialize();
        _maintimer->Initialize();
        
        Beams::BeamsGame beamsgame;
        
        _game.AddEntity(beamsgame.CreateGame(_maincamera->_screenwidth,_maincamera->_screenheight));
        
        _game.AddComponent(_maincamera);
        _game.Start();
        TransformationMatrixStack::Push(_maincamera->_projection);
        TransformationMatrixStack::Push(_maincamera->_view);
    }

    void Game::Update(float elapsedtime)
    {
        _maintimer->UpdateTimer(elapsedtime);
        _game.Update(_maintimer);
    }
    void Game::Draw()
    {
        _game.Draw();
    }

}
