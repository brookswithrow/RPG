//
//  Enemy.cpp
//  RPG
//
//  Created by Brooks Withrow on 7/6/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#include <stdio.h>
#include "Enemy.h"

Enemy::Enemy(std::string aName, int aMaxHP, int aNumAttacks, Attack* aAttacks, int* aAffinities) {
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

Attack* Enemy::getAttacks() {
    return attacks;
}

int Enemy::getAffinity(Type type) {
    int index = (int)type;
    return affinities[index];
}

bool Enemy::isDead() {
    return dead;
}

void Enemy::takeDamage(Attack* attack) {
    int mult = getAffinity(attack->getType());
    hp -= mult * attack->getDamage();
    if (hp <= 0) {
        dead = true;
    }
}

void Enemy::heal(int health) {
    hp = health + hp > maxHP ? maxHP : health + hp;
}