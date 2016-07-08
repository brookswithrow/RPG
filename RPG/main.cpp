//
//  main.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/6/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Window.h"
#include "Text.h"
#include "Enemy.h"
#include "BattleMenu.h"
#include "Party.h"

int main(int argc, const char * argv[]) {
    Window window;
    BattleMenu menu;
    window.init();
    Party party = Party();
    PartyMember dps = party.getPartyMemberA();
    PartyMember tank = party.getPartyMemberB();
    PartyMember mage = party.getPartyMemberC();
    Attack attack = Attack("Hit", 5, pierce);
    float noaffinities[7] = {1, 1, 1, 1, 1, 1, 1};
    Enemy enemy = Enemy("Bad Guy", 10, 1, &attack, noaffinities);
    SDL_Color color = {0, 0, 0};
    SDL_Event event;
    window.clear();
    menu.init(window.renderer);
    party.displayPartyStats(window.renderer);
    Text enemyHealth = Text::Text("Enemy health: " + std::to_string(enemy.getHP()), color, window.renderer, 320, 250);
    window.update();
    while (!enemy.isDead()) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                window.clear();
                if (event.key.keysym.sym == SDLK_DOWN) {
                    menu.moveCursor(-1);
                } else if (event.key.keysym.sym == SDLK_UP) {
                    menu.moveCursor(1);
                } else if (event.key.keysym.sym == SDLK_SPACE) {
                    menu.select(&dps, &enemy);
                    dps.takeDamage(&attack);
                }
                party.displayPartyStats(window.renderer);
                enemyHealth.updateText("Enemy health: " + std::to_string(enemy.getHP()));
                window.update();
            }
        }
    }
    SDL_Delay(3000);
    SDL_DestroyWindow(window.window);
    SDL_Quit();
    return 0;
}
