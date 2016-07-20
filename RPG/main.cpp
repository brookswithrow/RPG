//
//  main.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/6/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include "Window.hpp"
#include "Text.hpp"
#include "EnemyParty.hpp"
#include "MenuManager.hpp"
#include "Party.hpp"

int main(int argc, const char * argv[]) {
    Window window;
    window.init();
    Party party = Party();
    EnemyParty enemy = EnemyParty();
    BattleInfo info = BattleInfo(&party, &enemy);
    MenuManager menu = MenuManager(&info, &window);
    window.clear();
    menu.gameLoop();
    
    SDL_Delay(3000);
    SDL_DestroyWindow(window.window);
    SDL_Quit();
    return 0;
}
