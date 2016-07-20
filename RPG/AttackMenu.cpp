//
//  AttackMenu.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/14/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include "AttackMenu.hpp"

AttackMenu::AttackMenu() {
    
}

AttackMenu::AttackMenu(BattleInfo* aInfo, SDL_Renderer* aRenderer) {
    init(aInfo, aRenderer);
}

void AttackMenu::init(BattleInfo* aInfo, SDL_Renderer* aRenderer) {
    info = aInfo;
    renderer = aRenderer;
    init();
}

void AttackMenu::init() {
    actor = info->getCurrentActor();
    target = info->getTarget();
    attacks = actor->getAttacks();
    numOptions = actor->getNumAttacks();
    current = 0;
    options.clear();
    int (*func)(BattleInfo *, int);
    func = &AttackMenu::attack;
    for (int i = 0; i < numOptions; i++) {
        Attack attack = attacks[i];
        MenuOption option = MenuOption(attack.getName(), i, func, renderer);
        options.push_back(option);
    }
    SDL_Color black = {0, 0, 0};
    SDL_Color red = {255, 0, 0};
    for (int i = 0; i < numOptions; i++) {
        SDL_Color color = i == current ? red : black;
        options[i].changeColor(color);
        options[i].renderText();
    }
}
void AttackMenu::moveCursor(int direction) {
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

int AttackMenu::select(BattleInfo* info) {
    return options[current].select(info, current);
}

int AttackMenu::attack(BattleInfo* info, int pos) {
    PartyMember* current = info->getCurrentActor();
    std::vector<Attack> attacks = current->getAttacks();
    info->setAttack(&attacks[pos]);
    return 1;
}

void AttackMenu::updateText() {
    for (int i = 0; i < numOptions; i++) {
        options[i].renderText();
    }
}

