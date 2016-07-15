//
//  MenuOption
//  RPG
//
//  Created by Brooks Withrow on 7/14/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef MenuOption_h
#define MenuOption_h

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include "BattleInfo.h"
#include "Text.h"

class MenuOption {
public:
    MenuOption(std::string aName, int aPos, int (*aAction)(BattleInfo*, int), SDL_Renderer* renderer);
    int select(BattleInfo* info, int pos);
    void changeColor(SDL_Color color);
    void renderText();
private:
    int (*action)(BattleInfo*, int);
    std::string name;
    Text text;
    int pos;
};

#endif /* MenuOption_h */
