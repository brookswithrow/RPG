//
//  PartyMemberA.hpp
//  RPG
//
//  Created by Brooks Withrow on 7/7/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef Party_hpp
#define Party_hpp

#include <stdio.h>
#include <vector>
#include "PartyMember.hpp"
#include "Types.hpp"
#include "Text.hpp"

class Party {
public:
    Party();
    void initPartyMemberA();
    void initPartyMemberB();
    void initPartyMemberC();
    void displayPartyStats(SDL_Renderer* renderer, int current);
    PartyMember* getPartyMemberA();
    PartyMember* getPartyMemberB();
    PartyMember* getPartyMemberC();
    PartyMember* getPartyMember(int num);
    
private:
    PartyMember A;
    PartyMember B;
    PartyMember C;
};

#endif /* Party_hpp */
