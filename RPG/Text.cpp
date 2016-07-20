//
//  Text.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/7/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//


#include "Text.hpp"

Text::Text() {
    
}

Text::Text(std::string string, int aX, int aY, SDL_Renderer* aRenderer) {
    text = string;
    color = {0, 0, 0};
    renderer = aRenderer;
    x = aX;
    y = aY;
}

Text::Text(std::string string, SDL_Color aColor, SDL_Renderer* aRenderer, int aX, int aY) {
    text = string;
    color = aColor;
    renderer = aRenderer;
    x = aX;
    y = aY;
}

void Text::update() {
    makeTexture();
    render();
}

void Text::makeTexture() {
    //font = TTF_OpenFont("lazy.ttf", 14);
    textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    w = textSurface->w;
    h = textSurface->h;
}

void Text::render() {
    SDL_Rect renderQuad = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
}

void Text::updateText(std::string newString) {
    text = newString;
    //update();
}

void Text::updateColor(SDL_Color aColor) {
    color = aColor;
    //update();
}

void Text::updatePosition(int aX, int aY) {
    x = aX;
    y = aY;
    //update();
}

void Text::clear() {
    SDL_DestroyTexture(texture);
}