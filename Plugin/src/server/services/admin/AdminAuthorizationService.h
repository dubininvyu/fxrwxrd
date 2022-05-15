//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "Player.h"

#include "services.h"
#include "repositories.h"

class AdminAuthorizationService : public PlayerService {
private:
protected:
    AdminRepository adminRepository;
public:
    AdminAuthorizationService(Player& player);
    virtual ~AdminAuthorizationService();

    bool beginAuthorization();
    bool endAuthorization();
};

