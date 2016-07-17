//
//  EnemyParty.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/17/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include "EnemyParty.h"

EnemyParty::EnemyParty() {
    initEnemyA();
    initEnemyB();
    initEnemyC();
}

void EnemyParty::initEnemyA() {
    std::vector<float> affinities = {1, 1, 1, 1, 1, 1, 1};
    std::vector<Attack> attacks;
    attacks.push_back(Attack("Punch", 2, pierce));
    attacks.push_back(Attack("Claw", 3, slash));
    
    A = Enemy("Shadow", 30, 2, attacks, affinities);
}

void EnemyParty::initEnemyB() {
    std::vector<float> affinities = {0.5, 0.5, 0.5, 1, 1, 1, 1};
    std::vector<Attack> attacks;
    attacks.push_back(Attack("Spines", 2, pierce));
    attacks.push_back(Attack("Fire", 3, fire));
    
    B = Enemy("Spiny", 20, 2, attacks, affinities);
}

void EnemyParty::initEnemyC() {
    std::vector<float> affinities = {1.5, 1.5, 1.5, 1, 1, 1, 1};
    std::vector<Attack> attacks;
    attacks.push_back(Attack("Boulder", 5, crush));
    attacks.push_back(Attack("Ice", 2, ice));
    
    C = Enemy("Rock Guy", 50, 2, attacks, affinities);
}

void EnemyParty::displayPartyStats(SDL_Renderer *renderer) {
    SDL_Color black = {0, 0, 0};
    Text healthA = Text(A.getName() + " health: " + std::to_string(A.getHP()), black, renderer, 160, 500);
    healthA.update();
    Text healthB = Text(B.getName() + " health: " + std::to_string(B.getHP()), black, renderer, 350, 500);
    healthB.update();
    Text healthC = Text(C.getName() + " health: " + std::to_string(C.getHP()), black, renderer, 540, 500);
    healthC.update();
}

void EnemyParty::displayTarget(SDL_Renderer* renderer, int target) {
    SDL_Color black = {0, 0, 0};
    SDL_Color red = {255, 0, 0};
    Text healthA, healthB, healthC;
    if (target == 0) {
        healthA = Text(A.getName() + " health: " + std::to_string(A.getHP()), red, renderer, 160, 500);
        healthB = Text(B.getName() + " health: " + std::to_string(B.getHP()), black, renderer, 350, 500);
        healthC = Text(C.getName() + " health: " + std::to_string(C.getHP()), black, renderer, 540, 500);
    } else if (target == 1) {
        healthA = Text(A.getName() + " health: " + std::to_string(A.getHP()), black, renderer, 160, 500);
        healthB = Text(B.getName() + " health: " + std::to_string(B.getHP()), red, renderer, 350, 500);
        healthC = Text(C.getName() + " health: " + std::to_string(C.getHP()), black, renderer, 540, 500);
    } else {
        healthA = Text(A.getName() + " health: " + std::to_string(A.getHP()), black, renderer, 160, 500);
        healthB = Text(B.getName() + " health: " + std::to_string(B.getHP()), black, renderer, 350, 500);
        healthC = Text(C.getName() + " health: " + std::to_string(C.getHP()), red, renderer, 540, 500);
    }
    healthA.update();
    healthB.update();
    healthC.update();
}

Enemy* EnemyParty::getEnemyA() {
    return &A;
}
Enemy* EnemyParty::getEnemyB() {
    return &B;
}
Enemy* EnemyParty::getEnemyC() {
    return &C;
}
Enemy* EnemyParty::getEnemy(int num) {
    switch (num) {
        case 0:
            return &A;
        case 1:
            return &B;
        case 2:
            return &C;
    }
    return &A;
}

bool EnemyParty::isDead() {
    return A.isDead() && B.isDead() && C.isDead();
}