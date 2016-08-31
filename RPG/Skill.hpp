//
//  Skill.hpp
//  RPG
//
//  Created by Brooks Withrow on 7/20/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef Skill_hpp
#define Skill_hpp

#include <stdio.h>
#include <string>
#include "Types.hpp"

class Skill {
public:
    Skill();
    Skill(std::string aName, int aValue, SkillType aSkillType, DamageType aDmgType, bool aMultitarget);
    std::string getName();
    int getValue();
    DamageType getDamageType();
    SkillType getSkillType();
    bool isMultitarget();
    
private:
    std::string name;
    // Value holds different things depending on skill type.
    // Attacks: damage
    // Heals: % of health restored
    // Buffs/Debuffs: # stages raised/lowered
    int value;
    SkillType skillType;
    DamageType dmgType;
    // False when single target, true when multitarget
    bool multitarget;
};

#endif /* Skill_hpp */
