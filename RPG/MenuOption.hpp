//
//  MenuOption.hpp
//  RPG
//
//  Created by Brooks Withrow on 7/14/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef MenuOption_hpp
#define MenuOption_hpp

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include "BattleInfo.hpp"
#include "Text.hpp"

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

#endif /* MenuOption_hpp */
