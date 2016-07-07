//
//  Window.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/7/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include "Window.h"

void Window::init() {
    window = SDL_CreateWindow("RPG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
}

void Window::clear() {
    SDL_SetRenderDrawColor( renderer, 0xF0, 0xF0, 0xFF, 0xFF );
    SDL_RenderClear( renderer );
}

void Window::update() {
    SDL_RenderPresent(renderer);
}