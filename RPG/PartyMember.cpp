//
//  PartyMember.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/6/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include <stdio.h>
#include "PartyMember.hpp"

PartyMember::PartyMember() {
    name = "";
    maxHP = 0;
    hp = 0;
    maxSP = 0;
    sp = 0;
    numAttacks = 0;
    attacks = {};
    affinities = {};
}

PartyMember::PartyMember(std::string aName, int aMaxHP, int aMaxSP, int aAttack, int aDefense, int aMagic, int aResistance, int aNumAttacks, std::vector<Attack> aAttacks, std::vector<float> aAffinities) {
    name = aName;
    maxHP = aMaxHP;
    hp = aMaxHP;
    maxSP = aMaxSP;
    attack = aAttack;
    currAtt = aAttack;
    defense = aDefense;
    currDef = aDefense;
    magic = aMagic;
    currMag = aMagic;
    resistance = aResistance;
    currRes = aResistance;
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

int PartyMember::getAttack() {
    return attack;
}

int PartyMember::getDefense() {
    return defense;
}

int PartyMember::getMagic() {
    return magic;
}

int PartyMember::getResistance() {
    return resistance;
}

int PartyMember::getCurrAtt() {
    return currAtt;
}

int PartyMember::getCurrDef() {
    return currDef;
}

int PartyMember::getCurrMag() {
    return currMag;
}

int PartyMember::getCurrRes() {
    return currRes;
}

void PartyMember::buffAttack(int buff) {
    currAtt += buff;
    currMag += buff;
}

void PartyMember::buffDefense(int buff) {
    currDef += buff;
    currRes += buff;
}

void PartyMember::debuffAttack(int debuff) {
    currAtt -= debuff;
    currMag -= debuff;
}

void PartyMember::debuffDefense(int debuff) {
    currDef -= debuff;
    currRes -= debuff;
}

void PartyMember::resetStats() {
    currAtt = attack;
    currDef = defense;
    currMag = magic;
    currRes = resistance;
}

void PartyMember::updateStats() {
    if (currAtt - attack > 0) {
        currAtt--;
        currMag--;
    } else if (currAtt - attack < 0) {
        currAtt++;
        currMag++;
    }
    if (currDef - defense > 0) {
        currDef--;
        currRes--;
    } else if (currDef - defense < 0) {
        currDef++;
        currRes++;
    }
}

int PartyMember::getNumAttacks() {
    return numAttacks;
}

std::vector<Attack> PartyMember::getAttacks() {
    return attacks;
}

float PartyMember::getAffinity(DamageType type) {
    int index = (int)type;
    return affinities[index];
}

bool PartyMember::isDead() {
    return dead;
}

void PartyMember::takeDamage(Attack* attack) {
    float mult = getAffinity(attack->getType());
    hp -= mult * attack->getDamage();
    if (hp <= 0) {
        dead = true;
    }
}

void PartyMember::heal(int health) {
    hp = health + hp > maxHP ? maxHP : health + hp;
}