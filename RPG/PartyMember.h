//
//  PartyMember.
//  RPG
//
//  Created by Brooks Withrow on 7/6/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef PartyMember_h
#define PartyMember_h
#include <string>
#include "Attack.h"

class PartyMember {
public:
    PartyMember(std::string aName, int aMaxHP, int aMaxSP, int aNumAttacks, Attack* aAttacks, int* aAffinities);
    std::string getName();
    int getHP();
    int getMaxHP();
    int getSP();
    int getMaxSP();
    int getNumAttacks();
    Attack* getAttacks();
    int getAffinity(Type type);
    bool isDead();
    void takeDamage(Attack* attack);
    void heal(int health);
    
private:
    std::string name;
    int hp;
    int maxHP;
    int sp;
    int maxSP;
    int numAttacks;
    Attack* attacks;
    int* affinities;
    bool dead;
};


#endif /* PartyMember_h */
