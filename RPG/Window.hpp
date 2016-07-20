//
//  Window.hpp
//  RPG
//
//  Created by Brooks Withrow on 7/7/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>

class Window {
public:
    void init();
    void clear();
    void update();
    SDL_Window* window;
    SDL_Renderer* renderer;
private:
    int width = 800;
    int height = 600;
};


#endif /* Window_hpp */
