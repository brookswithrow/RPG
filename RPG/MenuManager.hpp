//
//  MenuManager.hpp
//  RPG
//
//  Created by Brooks Withrow on 7/14/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef MenuManager_hpp
#define MenuManager_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "BattleMenu.hpp"
#include "AttackMenu.hpp"
#include "BattleInfo.hpp"
#include "TargetMenu.hpp"
#include "Window.hpp"

class MenuManager {
public:
    MenuManager(BattleInfo* aInfo, Window* aWindow);
    void gameLoop();
private:
    int state = 0;
    SDL_Event event;
    Window* window;
    SDL_Renderer* renderer;
    Menu* menu;
    BattleMenu bMenu;
    AttackMenu aMenu;
    TargetMenu tMenu;
    BattleInfo* info;
};


#endif /* MenuManager_hpp */
