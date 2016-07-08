//
//  Enemy.h
//  RPG
//
//  Created by Brooks Withrow on 7/6/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef Enemy_h
#define Enemy_h
#include <string>
#include "Attack.h"

class Enemy {
public:
    Enemy(std::string aName, int aMaxHP, int aNumAttacks, Attack* aAttacks, float* aAffinities);
    std::string getName();
    int getHP();
    int getMaxHP();
    int getNumAttacks();
    Attack* getAttacks();
    float getAffinity(Type type);
    bool isDead();
    void takeDamage(Attack attack);
    void heal(int health);
    
private:
    std::string name;
    int maxHP;
    int hp;
    int numAttacks;
    Attack* attacks;
    float* affinities;
    bool dead;
};

#endif /* Enemy_h */
