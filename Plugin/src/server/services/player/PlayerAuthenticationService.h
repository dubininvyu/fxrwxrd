//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "PlayerService.h"
#include "PlayerRepository.h"

class Player;

class PlayerAuthenticationService : public PlayerService {
public:
    enum AuthenticationStage {
        STAGE_NULL = 0,

        STAGE_PLAYER_AUTHENTICATION,
        STAGE_ADMIN_AUTHENTICATION,

        STAGE_COUNT
    };

    enum AuthenticationError {
        ERROR_NONE = 0,
        ERROR_WRONG_PASSWORD, // to much attempts
        ERROR_TIMEOUT,
        ERROR_UNKNOWN,
    };
private:
protected:
    PlayerRepository playerRepository;
public:
    PlayerAuthenticationService(Player& player);
    virtual ~PlayerAuthenticationService();


    void begin(); // start from beginning
    void execute(); // execute current stage
    void end(AuthenticationError error = ERROR_NONE); // stop with(out) error

    void setStage(AuthenticationStage stage);
    void nextStage();

    // =====
    void beginPlayerAuthentication();
    void endPlayerAuthentication();

    void beginPlayerAuthorization();
    void endPlayerAuthorization();

    void beginPlayerRegistration();
    void endPlayerRegistration();

    void beginAdminAuthentication();
    void endAdminAuthentication();

    void beginAdminAuthorization();
    void endAdminAuthorization();
};

