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
#include "PartyMember.h"
#include "Enemy.h"
#include "BattleMenu.h"

int main(int argc, const char * argv[]) {
    Window window;
    BattleMenu menu;
    window.init();
    Attack myAttack = Attack(std::string("Hit"), 5, pierce);
    int noAffinities[7] = { 1, 1, 1, 1, 1, 1, 1 };
    PartyMember me = PartyMember("Me", 50, 30, 1, &myAttack, noAffinities);
    Enemy enemy = Enemy("Bad Guy", 10, 1, &myAttack, noAffinities);
    SDL_Color color = {0, 0, 0};
    TTF_Font* font = TTF_OpenFont("lazy.ttf", 28);
    SDL_Event event;
    window.clear();
    menu.init(window.renderer);
    Text myHealth = Text("My health: " + std::to_string(me.getHP()), color, font, window.renderer, 320, 100);
    Text enemyHealth = Text::Text("Enemy health: " + std::to_string(enemy.getHP()), color, font, window.renderer, 320, 250);
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
                    menu.select(&me, &enemy);
                    me.takeDamage(&myAttack);
                }
                myHealth.updateText("My health: " + std::to_string(me.getHP()));
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
