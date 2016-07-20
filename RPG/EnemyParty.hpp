//
//  EnemyParty.hpp
//  RPG
//
//  Created by Brooks Withrow on 7/17/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef EnemyParty_hpp
#define EnemyParty_hpp

#include <stdio.h>
#include <vector>
#include "Enemy.hpp"
#include "Types.hpp"
#include "Text.hpp"

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

#endif /* EnemyParty_hpp */
