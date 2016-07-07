//
//  Attack.h
//  RPG
//
//  Created by Brooks Withrow on 7/6/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef Attack_h
#define Attack_h
#include "Types.h"
#include <string>

class Attack {
public:
    Attack(std::string aName, int aDamage, Type aType);
    std::string getName();
    int getDamage();
    Type getType();

private:
    std::string name;
    int damage;
    Type type;
};

#endif /* Attack_h */
