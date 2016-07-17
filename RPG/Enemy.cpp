//
//  Enemy.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/6/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include <stdio.h>
#include "Enemy.h"

Enemy::Enemy() {
    name = "";
    maxHP = 0;
    hp = 0;
    numAttacks = 0;
    attacks = {};
    affinities = {};
}

Enemy::Enemy(std::string aName, int aMaxHP, int aNumAttacks, std::vector<Attack> aAttacks, std::vector<float> aAffinities) {
    name = aName;
    maxHP = aMaxHP;
    hp = aMaxHP;
    numAttacks = aNumAttacks;
    attacks = aAttacks;
    affinities = aAffinities;
}

std::string Enemy::getName() {
    return name;
}

int Enemy::getHP() {
    return hp;
}

int Enemy::getMaxHP() {
    return maxHP;
}

int Enemy::getNumAttacks() {
    return numAttacks;
}

std::vector<Attack> Enemy::getAttacks() {
    return attacks;
}

float Enemy::getAffinity(Type type) {
    int index = (int)type;
    return affinities[index];
}

bool Enemy::isDead() {
    return dead;
}

void Enemy::takeDamage(Attack attack) {
    float  mult = getAffinity(attack.getType());
    hp -= mult * attack.getDamage();
    if (hp <= 0) {
        hp = 0;
        dead = true;
    }
}

void Enemy::heal(int health) {
    hp = health + hp > maxHP ? maxHP : health + hp;
}