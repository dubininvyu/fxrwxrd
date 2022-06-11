//
// Created by dubininvyu on 07.05.2022.
//

#include "AdminAuthorizationService.h"

#include "dialogs.h"
#include "services.h"
#include "repositories.h"

AdminAuthorizationService::AdminAuthorizationService(Player* player) :
    PlayerService(player), adminRepository(player, Repository::MODE_NOPE) {
}

AdminAuthorizationService::~AdminAuthorizationService() {

}

bool AdminAuthorizationService::beginAuthorization() {

    // show authorization dialog
    // ...

    endAuthorization();
    return true;
}

bool AdminAuthorizationService::endAuthorization() {
    bool result;

    // admin data
    result = adminRepository.loadAdmin();

    if (!result) {
        //player.getSystem()->getAuthenticationSystem()->end(PlayerAuthenticationSystem::ERROR_UNKNOWN);
        return false;
    }

    // set authorization status
    player->getAdmin()->setAuthorized(true);

    // end authorization
    //player.getSystem()->getAuthenticationSystem()->endAdminAuthorization();
    return true;
}