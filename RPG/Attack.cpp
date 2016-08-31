//
//  Attack.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/6/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include <stdio.h>
#include "Attack.hpp"

Attack::Attack() {
    name = "";
    damage = 0;
    type = none;
}

Attack::Attack(std::string aName, int aDamage, DamageType aType) {
    name = aName;
    damage = aDamage;
    type = aType;
}

std::string Attack::getName() {
    return name;
}


int Attack::getDamage() {
    return damage;
}


DamageType Attack::getType() {
    return type;
}