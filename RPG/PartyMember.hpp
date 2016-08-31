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
    PartyMember(std::string aName, int aMaxHP, int aMaxSP, int aAttack, int aDefense, int aMagic, int aResistance, int aNumAttacks, std::vector<Attack> aAttacks, std::vector<float> aAffinities);
    std::string getName();
    int getHP();
    int getMaxHP();
    int getSP();
    int getMaxSP();
    int getAttack();
    int getDefense();
    int getMagic();
    int getResistance();
    int getCurrAtt();
    int getCurrDef();
    int getCurrMag();
    int getCurrRes();
    void buffAttack(int buff);
    void buffDefense(int buff);
    void debuffAttack(int debuff);
    void debuffDefense(int debuff);
    void resetStats();
    void updateStats();
    int getNumAttacks();
    std::vector<Attack> getAttacks();
    float getAffinity(DamageType type);
    bool isDead();
    void takeDamage(Attack* attack);
    void heal(int health);
    
private:
    std::string name;
    int hp;
    int maxHP;
    int sp;
    int maxSP;
    int attack;
    int currAtt;
    int defense;
    int currDef;
    int magic;
    int currMag;
    int resistance;
    int currRes;
    int numAttacks;
    std::vector<Attack> attacks;
    std::vector<float> affinities;
    bool dead;
};


#endif /* PartyMember_hpp */
