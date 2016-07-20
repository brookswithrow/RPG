//
//  TargetMenu.hpp
//  RPG
//
//  Created by Brooks Withrow on 7/17/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef TargetMenu_hpp
#define TargetMenu_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Menu.hpp"
#include "BattleInfo.hpp"
#include "Text.hpp"

class TargetMenu : public Menu {
public:
    TargetMenu();
    TargetMenu(BattleInfo* aInfo, SDL_Renderer* aRenderer);
    void init(BattleInfo* aInfo, SDL_Renderer* aRenderer);
    void init();
    void moveCursor(int direction);
    int select(BattleInfo *info);
    void updateText();
    void clearText();
    void setAttack(Attack* anAttack);
private:
    Attack* attack;
    BattleInfo* info;
    PartyMember* actor;
    EnemyParty* targets;
    std::vector<Attack> attacks;
    int current = 0;
    static int attackTarget(BattleInfo* info, int pos);
};

#endif /* TargetMenu_hpp */
