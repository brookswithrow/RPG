//
//  BattleMenu.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/7/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include "BattleMenu.h"

void BattleMenu::init(SDL_Renderer *aRenderer) {
    renderer = aRenderer;
    SDL_Color black = {0, 0, 0};
    SDL_Color red = {255, 0, 0};
    for (int i = 0; i < numOptions; i++) {
        options[i] = Text();
        SDL_Color color = i == current ? red : black;
        std::string optiontext = optionText[i];
        Text text = Text::Text(optiontext, color, renderer, 50, 50*(i+1));
        options[i] = text;
    }
}

void BattleMenu::moveCursor(int direction) {
    SDL_Color black = {0, 0, 0};
    SDL_Color red = {255, 0, 0};
    options[current].updateColor(black);
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
    options[current].updateColor(red);
}

void BattleMenu::select(PartyMember* actor, Enemy* target) {
    switch (current) {
        case 0:
            attack(actor, target);
        case 1:
            doNothing();
    }
    for (int i = 0; i < numOptions; i++) {
        options[i].render();
    }
}

void BattleMenu::attack(PartyMember* attacker, Enemy* target) {
    Attack* attack = attacker->getAttacks();
    target->takeDamage(attack[0]);
}

void BattleMenu::doNothing() {
    
}
