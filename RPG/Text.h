//
//  Text.h
//  RPG
//
//  Created by Brooks Withrow on 7/7/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef Text_h
#define Text_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include <string>

class Text {
public:
    Text();
    Text(std::string string, SDL_Color aColor, SDL_Renderer* aRenderer, int aX, int aY);
    void render();
    void updateText(std::string newString);
    void updateColor(SDL_Color aColor);
    void updatePosition(int aX, int aY);

private:
    void update();
    void makeTexture();
    std::string text;
    SDL_Color color;
    TTF_Font* font = TTF_OpenFont("lazy.ttf", 14);
    SDL_Surface* textSurface;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    int x;
    int y;
    int w;
    int h;
};


#endif /* Text_h */
