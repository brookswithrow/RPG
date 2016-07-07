//
//  BattleMenu.h
//  RPG
//
//  Created by Brooks Withrow on 7/7/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef BattleMenu_h
#define BattleMenu_h

#include <stdio.h>
#include <string>
#include "Text.h"
#include "Enemy.h"
#include "PartyMember.h"
#include "Attack.h"

enum battleOptions {
    attack = 0,
    nothing = 1
};

class BattleMenu {
    
public:
    void init(SDL_Renderer *aRenderer);
    void moveCursor(int direction);
    void select(PartyMember* actor, Enemy* target);
    
private:
    SDL_Renderer *renderer;
    int numOptions = 2;
    std::string optionText[2] = {"Attack", "Do Nothing"};
    Text *options = new Text[2];
    int current;
    void attack(PartyMember* attacker, Enemy* target);
    void doNothing();
};

#endif /* BattleMenu_h */
