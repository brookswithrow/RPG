//
//  BattleInfo.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/14/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include "BattleInfo.hpp"

BattleInfo::BattleInfo(Party* aParty, EnemyParty* aTarget) {
    party = aParty;
    targets = aTarget;
    turn = 0;
    current = party->getPartyMember(turn);
}

PartyMember* BattleInfo::getCurrentActor() {
    return current;
}

Enemy* BattleInfo::getTarget() {
    return targets->getEnemy(turn);
}

EnemyParty* BattleInfo::getTargets() {
    return targets;
}

int BattleInfo::getTurn() {
    return turn;
}

void BattleInfo::nextTurn() {
    turn++;
    if (turn == 3) {
        for (int i = 0; i < 3; i ++) {
            PartyMember* victim = party->getPartyMember(i);
            std::vector<Attack> attacks = targets->getEnemy(i)->getAttacks();
            victim->takeDamage(&attacks[0]);
        }
        turn = 0;
    }
    current = party->getPartyMember(turn);
}

bool BattleInfo::victory() {
    return targets->isDead();
}

void BattleInfo::updateAllText(SDL_Renderer* renderer) {
    party->displayPartyStats(renderer, turn);
    targets->displayPartyStats(renderer);
}

void BattleInfo::updatePartyText(SDL_Renderer* renderer) {
    party->displayPartyStats(renderer, turn);
}

void BattleInfo::setAttack(Attack* anAttack) {
    attack = anAttack;
}

Attack* BattleInfo::getAttack() {
    return attack;
}