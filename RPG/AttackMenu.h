//
//  AttackMenu.h
//  RPG
//
//  Created by Brooks Withrow on 7/14/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef AttackMenu_h
#define AttackMenu_h

#include <stdio.h>
#include <string>
#include <vector>
#include "Menu.h"
#include "BattleInfo.h"
#include "Text.h"

class AttackMenu : public Menu {
public:
    AttackMenu();
    AttackMenu(BattleInfo* aInfo, SDL_Renderer* aRenderer);
    void init(BattleInfo* aInfo, SDL_Renderer* aRenderer);
    void init();
    void setInfo(BattleInfo* info);
    void moveCursor(int direction);
    int select(BattleInfo* info);
    void updateText();
    
private:
    BattleInfo* info;
    PartyMember* actor;
    Enemy* target;
    std::vector<Attack> attacks;
    int current = 0;
    static int attack(BattleInfo* info, int pos);
};

#endif /* AttackMenu_h */
