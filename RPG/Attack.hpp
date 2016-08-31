//
//  Attack.hpp
//  RPG
//
//  Created by Brooks Withrow on 7/6/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef Attack_hpp
#define Attack_hpp
#include "Types.hpp"
#include <string>

class Attack {
public:
    Attack();
    Attack(std::string aName, int aDamage, DamageType aType);
    std::string getName();
    int getDamage();
    DamageType getType();

private:
    std::string name;
    int damage;
    DamageType type;
};

#endif /* Attack_hpp */
