//
//  MenuOption.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/14/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include "MenuOption.hpp"

MenuOption::MenuOption(std::string aName, int aPos, int (*aAction)(BattleInfo*, int), SDL_Renderer* renderer) {
    name = aName;
    pos = aPos;
    text = Text(name, 50, 50*pos, renderer);
    action = aAction;
}

int MenuOption::select(BattleInfo *info, int pos) {
    return action(info, pos);
}

void MenuOption::changeColor(SDL_Color color) {
    text.updateColor(color);
}

void MenuOption::renderText() {
    text.update();
    text.clear();
}