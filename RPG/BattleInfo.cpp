//
//  BattleInfo.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/14/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include "BattleInfo.h"

BattleInfo::BattleInfo(Party* aParty, Enemy* aTarget) {
    party = aParty;
    target = aTarget;
    turn = 0;
    current = party->getPartyMember(turn);
}

PartyMember* BattleInfo::getCurrentActor() {
    return current;
}

Enemy* BattleInfo::getTarget() {
    return target;
}

int BattleInfo::getTurn() {
    return turn;
}

void BattleInfo::nextTurn() {
    turn++;
    if (turn == 3) {
        PartyMember* victim = party->getPartyMember(0);
        std::vector<Attack> attacks = target->getAttacks();
        victim->takeDamage(&attacks[0]);
        turn = 0;
    }
    current = party->getPartyMember(turn);
}

bool BattleInfo::victory() {
    return target->isDead();
}

void BattleInfo::updateText(SDL_Renderer* renderer) {
    party->displayPartyStats(renderer);
    SDL_Color color = {0, 0, 0};
    Text enemyHealth = Text::Text("Enemy health: " + std::to_string(target->getHP()), color, renderer, 320, 250);
    enemyHealth.update();
}