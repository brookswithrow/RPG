//
//  Types.hpp
//  RPG
//
//  Created by Brooks Withrow on 7/6/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef Types_hpp
#define Types_hpp

enum DamageType {
    none = -1,
    pierce = 0,
    slash = 1,
    crush = 2,
    fire = 3,
    water = 4,
    ice = 5,
    lightning = 6
};

enum SkillType {
    attack = 0,
    heal = 1,
    attbuff = 2,
    defbuff = 3,
    spdbuff = 4,
    attdbf = 5,
    defdbf = 6,
    spddbf = 7
};

#endif /* Types_hpp */
