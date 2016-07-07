//
//  PartyMember.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/6/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include <stdio.h>
#include "PartyMember.h"

PartyMember::PartyMember(std::string aName, int aMaxHP, int aMaxSP, int aNumAttacks, Attack* aAttacks, int* aAffinities) {
    name = aName;
    maxHP = aMaxHP;
    hp = aMaxHP;
    maxSP = aMaxSP;
    sp = aMaxSP;
    numAttacks = aNumAttacks;
    attacks = aAttacks;
    affinities = aAffinities;
}

std::string PartyMember::getName() {
    return name;
}

int PartyMember::getHP() {
    return hp;
}

int PartyMember::getMaxHP() {
    return maxHP;
}

int PartyMember::getSP() {
    return sp;
}

int PartyMember::getMaxSP() {
    return maxSP;
}

int PartyMember::getNumAttacks() {
    return numAttacks;
}

Attack* PartyMember::getAttacks() {
    return attacks;
}

int PartyMember::getAffinity(Type type) {
    int index = (int)type;
    return affinities[index];
}

bool PartyMember::isDead() {
    return dead;
}

void PartyMember::takeDamage(Attack* attack) {
    int mult = getAffinity(attack->getType());
    hp -= mult * attack->getDamage();
    if (hp <= 0) {
        dead = true;
    }
}

void PartyMember::heal(int health) {
    hp = health + hp > maxHP ? maxHP : health + hp;
}