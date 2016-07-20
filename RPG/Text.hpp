//
//  Text.hpp
//  RPG
//
//  Created by Brooks Withrow on 7/7/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef Text_hpp
#define Text_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include <string>

class Text {
public:
    Text();
    Text(std::string string, int aX, int aY, SDL_Renderer* aRenderer);
    Text(std::string string, SDL_Color aColor, SDL_Renderer* aRenderer, int aX, int aY);
    void update();
    void updateText(std::string newString);
    void updateColor(SDL_Color aColor);
    void updatePosition(int aX, int aY);
    void clear();

private:
    void render();
    void makeTexture();
    std::string text;
    SDL_Color color;
    TTF_Font* font = TTF_OpenFont("constantine.ttf", 14);
    SDL_Surface* textSurface;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    int x;
    int y;
    int w;
    int h;
};


#endif /* Text_hpp */
