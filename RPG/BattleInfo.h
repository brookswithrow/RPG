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
#include "EnemyParty.h"

class BattleInfo {
public:
    BattleInfo(Party* aParty, EnemyParty* aTarget);
    PartyMember* getCurrentActor();
    Enemy* getTarget();
    EnemyParty* getTargets();
    int getTurn();
    void nextTurn();
    bool victory();
    void updateAllText(SDL_Renderer* renderer);
    void updatePartyText(SDL_Renderer* renderer);
    void setAttack(Attack* anAttack);
    Attack* getAttack();
private:
    Party* party;
    PartyMember* current;
    int turn;
    EnemyParty* targets;
    Attack* attack;
};

#endif /* BattleInfo_h */
