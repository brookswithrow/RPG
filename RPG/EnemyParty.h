//
//  EnemyParty.h
//  RPG
//
//  Created by Brooks Withrow on 7/17/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef EnemyParty_h
#define EnemyParty_h

#include <stdio.h>
#include <vector>
#include "Enemy.h"
#include "Types.h"
#include "Text.h"

class EnemyParty {
public:
    EnemyParty();
    void initEnemyA();
    void initEnemyB();
    void initEnemyC();
    void displayPartyStats(SDL_Renderer* renderer);
    void displayTarget(SDL_Renderer* renderer, int target);
    Enemy* getEnemyA();
    Enemy* getEnemyB();
    Enemy* getEnemyC();
    Enemy* getEnemy(int num);
    bool isDead();
    
private:
    Enemy A;
    Enemy B;
    Enemy C;
};

#endif /* EnemyParty_h */
