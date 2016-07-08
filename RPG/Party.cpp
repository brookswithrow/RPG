//
//  PartyMemberA.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/7/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include "Party.h"

Party::Party() {
    initPartyMemberA();
    initPartyMemberB();
    initPartyMemberC();
}

void Party::initPartyMemberA() {
    float affinities[7] = {1, 1, 1, 1, 1, 1, 1};
    Attack *attacks = new Attack[3];
    attacks[0] = Attack("Punch", 8, pierce);
    attacks[1] = Attack("Fire", 12, fire);
    attacks[2] = Attack("Sword", 14, slash);
    
    A = PartyMember("DPS", 50, 40, 3, attacks, affinities);
}

void Party::initPartyMemberB() {
    float affinities[7] = {0.5, 0.5, 0.5, 1, 1, 1, 1};
    Attack *attacks = new Attack[2];
    attacks[0] = Attack("Crush", 16, crush);
    attacks[1] = Attack("Water", 8, water);
    
    B = PartyMember("Tank", 50, 40, 2, attacks, affinities);
}

void Party::initPartyMemberC() {
    float affinities[7] = {1.5, 1.5, 1.5, 1, 1, 1, 1};
    Attack *attacks = new Attack[2];
    attacks[0] = Attack("Arrow", 6, pierce);
    attacks[1] = Attack("Lightning", 18, lightning);
    
    C = PartyMember("Mage", 50, 40, 2, attacks, affinities);
}

void Party::displayPartyStats(SDL_Renderer *renderer) {
    SDL_Color black = {0, 0, 0};
    Text healthA = Text(A.getName() + " health: " + std::to_string(A.getHP()), black, renderer, 160, 100);
    healthA.render();
    Text healthB = Text(B.getName() + " health: " + std::to_string(B.getHP()), black, renderer, 350, 100);
    healthB.render();
    Text healthC = Text(C.getName() + " health: " + std::to_string(C.getHP()), black, renderer, 540, 100);
    healthC.render();
}

PartyMember Party::getPartyMemberA() {
    return A;
}
PartyMember Party::getPartyMemberB() {
    return B;
}
PartyMember Party::getPartyMemberC() {
    return C;
}