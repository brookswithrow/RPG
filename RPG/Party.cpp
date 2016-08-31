//
//  PartyMemberA.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/7/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include "Party.hpp"

Party::Party() {
    initPartyMemberA();
    initPartyMemberB();
    initPartyMemberC();
}

void Party::initPartyMemberA() {
    std::vector<float> affinities = {1, 1, 1, 1, 1, 1, 1};
    std::vector<Attack> attacks;
    attacks.push_back(Attack("Punch", 2, pierce));
    attacks.push_back(Attack("Fire", 4, fire));
    attacks.push_back(Attack("Sword", 6, slash));
    
    A = PartyMember("A", 50, 40, 10, 10, 10, 10, 3, attacks, affinities);
}

void Party::initPartyMemberB() {
    std::vector<float> affinities = {0.5, 0.5, 0.5, 1, 1, 1, 1};
    std::vector<Attack> attacks;
    attacks.push_back(Attack("Crush", 8, crush));
    attacks.push_back(Attack("Water", 2, water));
    
    B = PartyMember("B", 50, 40, 20, 5, 20, 5, 2, attacks, affinities);
}

void Party::initPartyMemberC() {
    std::vector<float> affinities = {1.5, 1.5, 1.5, 1, 1, 1, 1};
    std::vector<Attack> attacks;
    attacks.push_back(Attack("Arrow", 1, pierce));
    attacks.push_back(Attack("Lightning", 9, lightning));
    
    C = PartyMember("C", 50, 40, 5, 20, 5, 20, 2, attacks, affinities);
}

void Party::displayPartyStats(SDL_Renderer *renderer, int current) {
    SDL_Color black = {0, 0, 0};
    SDL_Color red = {255, 0, 0};
    Text healthA;
    Text healthB;
    Text healthC;
    if (current == 0) {
        healthA = Text(A.getName() + " health: " + std::to_string(A.getHP()), red, renderer, 160, 100);
        healthB = Text(B.getName() + " health: " + std::to_string(B.getHP()), black, renderer, 350, 100);
        healthC = Text(C.getName() + " health: " + std::to_string(C.getHP()), black, renderer, 540, 100);
    } else if (current == 1) {
        healthA = Text(A.getName() + " health: " + std::to_string(A.getHP()), black, renderer, 160, 100);
        healthB = Text(B.getName() + " health: " + std::to_string(B.getHP()), red, renderer, 350, 100);
        healthC = Text(C.getName() + " health: " + std::to_string(C.getHP()), black, renderer, 540, 100);
    } else if (current == 2) {
        healthA = Text(A.getName() + " health: " + std::to_string(A.getHP()), black, renderer, 160, 100);
        healthB = Text(B.getName() + " health: " + std::to_string(B.getHP()), black, renderer, 350, 100);
        healthC = Text(C.getName() + " health: " + std::to_string(C.getHP()), red, renderer, 540, 100);
    } else {
        healthA = Text(A.getName() + " health: " + std::to_string(A.getHP()), black, renderer, 160, 100);
        healthB = Text(B.getName() + " health: " + std::to_string(B.getHP()), black, renderer, 350, 100);
        healthC = Text(C.getName() + " health: " + std::to_string(C.getHP()), black, renderer, 540, 100);
    }
    healthA.update();
    healthB.update();
    healthC.update();
    healthA.clear();
    healthB.clear();
    healthC.clear();
}

PartyMember* Party::getPartyMemberA() {
    return &A;
}
PartyMember* Party::getPartyMemberB() {
    return &B;
}
PartyMember* Party::getPartyMemberC() {
    return &C;
}
PartyMember* Party::getPartyMember(int num) {
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