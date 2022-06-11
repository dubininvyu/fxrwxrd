//
// Created by dubininvyu on 15.05.2022.
//


#pragma once

#include <string>

using namespace std;

class Player;

class PlayerPassword {
public:
    static const unsigned int MIN_LENGTH = 6;
    static const unsigned int MAX_LENGTH = 64;
private:
protected:
    Player* player;
    string password;
public:
    PlayerPassword(Player* player, const string& password = "");

    bool setPassword(const string& password, const bool reWrite = true);
    string getPassword() const;

    bool isValid();
    static bool isValid(const string& password);
};

