//
//  MenuManager.h
//  RPG
//
//  Created by Brooks Withrow on 7/14/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef MenuManager_h
#define MenuManager_h

#include <stdio.h>
#include <SDL2/SDL.h>
#include "BattleMenu.h"
#include "AttackMenu.h"
#include "BattleInfo.h"
#include "Window.h"

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
    BattleInfo* info;
};


#endif /* MenuManager_h */
