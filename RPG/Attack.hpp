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
    Attack(std::string aName, int aDamage, Type aType);
    std::string getName();
    int getDamage();
    Type getType();

private:
    std::string name;
    int damage;
    Type type;
};

#endif /* Attack_hpp */
