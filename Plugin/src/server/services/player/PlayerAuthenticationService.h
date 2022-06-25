//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "Player.h"
#include "services.h"
#include "languages.h"
#include "repositories.h"

class Player;

class PlayerAuthenticationService : public PlayerService {
private:
protected:
    PlayerRepository playerRepository;
public:
    /*
     * constructors & destructors
     */
    PlayerAuthenticationService(Player* player);
    virtual ~PlayerAuthenticationService();

    /*
     * methods
     * for checking registration
     */
    bool isRegistered();
    bool isRegisteredByPassword(const string& password) const;

    /*
     * methods
     * for initialization
     */
    void initLocale();
};

