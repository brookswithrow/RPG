//
//  PartyMember.hpp
//  RPG
//
//  Created by Brooks Withrow on 7/6/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef PartyMember_hpp
#define PartyMember_hpp
#include <string>
#include <vector>
#include "Attack.hpp"

class PartyMember {
public:
    PartyMember();
    PartyMember(std::string aName, int aMaxHP, int aMaxSP, int aNumAttacks, std::vector<Attack> aAttacks, std::vector<float> aAffinities);
    std::string getName();
    int getHP();
    int getMaxHP();
    int getSP();
    int getMaxSP();
    int getNumAttacks();
    std::vector<Attack> getAttacks();
    float getAffinity(Type type);
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
    std::vector<Attack> attacks;
    std::vector<float> affinities;
    bool dead;
};


#endif /* PartyMember_hpp */
