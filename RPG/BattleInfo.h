//
//  BattleInfo.h
//  RPG
//
//  Created by Brooks Withrow on 7/14/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef BattleInfo_h
#define BattleInfo_h

#include <stdio.h>
#include <vector>
#include <SDL2/SDL.h>
#include "Party.h"
#include "PartyMember.h"
#include "Enemy.h"

class BattleInfo {
public:
    BattleInfo(Party* aParty, Enemy* aTarget);
    PartyMember* getCurrentActor();
    Enemy* getTarget();
    int getTurn();
    void nextTurn();
    bool victory();
    void updateText(SDL_Renderer* renderer);
private:
    Party* party;
    PartyMember* current;
    int turn;
    Enemy* target;
};

#endif /* BattleInfo_h */
