  //
//  MenuManager.c
//  RPG
//
//  Created by Brooks Withrow on 7/14/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include "MenuManager.hpp"

MenuManager::MenuManager(BattleInfo* aInfo, Window* aWindow) {
    info = aInfo;
    window = aWindow;
    renderer = window->renderer;
    aMenu = AttackMenu(info, window->renderer);
    bMenu = BattleMenu(info, window->renderer);
    tMenu = TargetMenu(info, window->renderer);
    menu = &bMenu;
}

void MenuManager::gameLoop() {
    info->updateAllText(renderer);
    menu->updateText();
    window->update();
    while (!info->victory()) {
        while (SDL_WaitEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                window->clear();
                if (event.key.keysym.sym == SDLK_DOWN) {
                    menu->moveCursor(1);
                } else if (event.key.keysym.sym == SDLK_UP) {
                    menu->moveCursor(-1);
                } else if (event.key.keysym.sym == SDLK_SPACE) {
                    if (menu->select(info)) {
                        if (state == 0) {
                            menu = &aMenu;
                            menu->init();
                            state = 1;
                        } else if (state == 1) {
                            menu = &tMenu;
                            menu->init();
                            state = 2;
                        } else {
                            info->nextTurn();
                            menu = &bMenu;
                            state = 0;
                        }
                    }
                }
                menu->updateText();
                if (state == 2) {
                    info->updatePartyText(renderer);
                } else {
                    info->updateAllText(renderer);
                }
                window->update();
            }
        }
    }
}