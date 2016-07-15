//
//  BattleMenu.h
//  RPG
//
//  Created by Brooks Withrow on 7/7/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef BattleMenu_h
#define BattleMenu_h

#include <stdio.h>
#include <string>
#include "Text.h"
#include "Enemy.h"
#include "PartyMember.h"
#include "Attack.h"
#include "Menu.h"

class BattleMenu : public Menu {
    
public:
    BattleMenu();
    BattleMenu(BattleInfo* aInfo, SDL_Renderer* aRenderer);
    void init(BattleInfo* aInfo, SDL_Renderer* aRenderer);
    void init();
    void moveCursor(int direction);
    int select(BattleInfo *info);
    void updateText();
    
private:
    int numOptions = 2;
    static int returnPos(BattleInfo* info, int pos);
    void doNothing();
};

#endif /* BattleMenu_h */
