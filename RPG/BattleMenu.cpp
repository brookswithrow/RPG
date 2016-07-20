//
//  BattleMenu.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/7/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include "BattleMenu.hpp"

BattleMenu::BattleMenu() {
    
}

BattleMenu::BattleMenu(BattleInfo* aInfo, SDL_Renderer* aRenderer) {
    init(aInfo, aRenderer);
}

void BattleMenu::init(BattleInfo* aInfo, SDL_Renderer* aRenderer) {
    info = aInfo;
    renderer = aRenderer;
    init();
}

void BattleMenu::init() {
    int (*func)(BattleInfo *, int);
    func = &BattleMenu::returnPos;
    MenuOption attack = MenuOption("Attack", 0, func, renderer);
    MenuOption doNothing = MenuOption("Do Nothing", 1, func, renderer);
    options.push_back(attack);
    options.push_back(doNothing);
    current = 0;
    SDL_Color black = {0, 0, 0};
    SDL_Color red = {255, 0, 0};
    for (int i = 0; i < numOptions; i++) {
        SDL_Color color = i == current ? red : black;
        options[i].changeColor(color);
        options[i].renderText();
    }
}

void BattleMenu::moveCursor(int direction) {
    SDL_Color black = {0, 0, 0};
    SDL_Color red = {255, 0, 0};
    options[current].changeColor(black);
    options[current].renderText();
    if (direction == -1) {
        current--;
        if (current == -1) {
            current = numOptions - 1;
        }
    } else {
        current++;
        if (current == numOptions) {
            current = 0;
        }
    }
    options[current].changeColor(red);
    options[current].renderText();
}

int BattleMenu::select(BattleInfo* info) {
    if (current == 0) {
        return true;
    }
    return false;
}

int BattleMenu::returnPos(BattleInfo* info, int pos) {
    return 0;
}

void BattleMenu::updateText() {
    for (int i = 0; i < numOptions; i++) {
        options[i].renderText();
    }
}
