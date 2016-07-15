//
//  PartyMemberA.h
//  RPG
//
//  Created by Brooks Withrow on 7/7/16.
//  Copyright © 2016 Brooks Withrow. All rights reserved.
//

#ifndef Party_h
#define Party_h

#include <stdio.h>
#include <vector>
#include "PartyMember.h"
#include "Types.h"
#include "Text.h"

class Party {
public:
    Party();
    void initPartyMemberA();
    void initPartyMemberB();
    void initPartyMemberC();
    void displayPartyStats(SDL_Renderer* renderer);
    PartyMember* getPartyMemberA();
    PartyMember* getPartyMemberB();
    PartyMember* getPartyMemberC();
    PartyMember* getPartyMember(int num);
    
private:
    PartyMember A;
    PartyMember B;
    PartyMember C;
};

#endif /* Party_h */
