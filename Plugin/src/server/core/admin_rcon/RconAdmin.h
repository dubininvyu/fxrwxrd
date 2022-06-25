//
// Created by dubininvyu on 18.06.2022.
//


#pragma once

class Player;

class RconAdmin {
private:
protected:
    Player* player;
public:
    RconAdmin(Player* player);
    ~RconAdmin();
};

