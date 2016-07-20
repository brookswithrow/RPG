//
//  Menu.hpp
//  RPG
//
//  Created by Brooks Withrow on 7/14/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp
#include <SDL2/SDL.h>
#include <vector>
#include "MenuOption.hpp"

class Menu {
public:
    virtual void init(BattleInfo* aInfo, SDL_Renderer* aRenderer) = 0;
    virtual void init() = 0;
    virtual void moveCursor(int direction) = 0;
    virtual int select(BattleInfo *info) = 0;
    virtual void updateText() = 0;
protected:
    SDL_Renderer* renderer;
    int numOptions;
    std::vector<MenuOption> options;
    BattleInfo* info;
    int current;
};

#endif /* Menu_hpp */
