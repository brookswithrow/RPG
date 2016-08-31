//
//  TargetMenu.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/17/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include "TargetMenu.hpp"

TargetMenu::TargetMenu() {
    
}

TargetMenu::TargetMenu(BattleInfo* aInfo, SDL_Renderer* aRenderer) {
    init(aInfo, aRenderer);
}

void TargetMenu::init(BattleInfo* aInfo, SDL_Renderer* aRenderer) {
    info = aInfo;
    renderer = aRenderer;
    init();
}

void TargetMenu::init() {
    actor = info->getCurrentActor();
    targets = info->getTargets();
    attacks = actor->getAttacks();
    numOptions = 3;
    current = 0;
    options.clear();
    int (*func)(BattleInfo *, int);
    func = &TargetMenu::attackTarget;
    for (int i = 0; i < numOptions; i++) {
        Enemy* enemy = targets->getEnemy(i);
        MenuOption option = MenuOption(enemy->getName(), i, func, renderer);
        options.push_back(option);
    }
    targets->displayTarget(renderer, current);
}
void TargetMenu::moveCursor(int direction) {
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
    targets->displayTarget(renderer, current);
}

int TargetMenu::select(BattleInfo* info) {
    return options[current].select(info, current);
}

int TargetMenu::attackTarget(BattleInfo* info, int pos) {
    //PartyMember* current = info->getCurrentActor();
    Enemy* target = info->getTargets()->getEnemy(pos);
    // SP cost here
    target->takeDamage(*info->getAttack());
    return 1;
}

void TargetMenu::updateText() {
    targets->displayTarget(renderer, current);
}
