//
// Created by dubininvyu on 03.05.2022.
//

#include "EventHandler.h"
#include "PlayerEventHandler.h"
#include "ServerEventHandler.h"

/* player */
#include "PlayerConnectHandler.h"
#include "PlayerDisconnectHandler.h"
#include "PlayerIncomingConnectionHandler.h"
#include "PlayerRequestClassHandler.h"
#include "PlayerSpawnHandler.h"

/* main */
#include "PlayerTextHandler.h"
#include "PlayerCommandTextHandler.h"
#include "PlayerDialogResponseHandler.h"

/* server */
#include "ServerGameModeInitHandler.h"
#include "ServerGameModeExitHandler.h"

/* vehicle */
#include "VehicleDamageHandler.h"
#include "VehicleDeathHandler.h"
#include "VehiclePaintJobHandler.h"
#include "VehicleParamsUpdateHandler.h"
#include "VehicleResprayHandler.h"
#include "VehicleSirenStateChangeHandler.h"
#include "VehicleSpawnHandler.h"
#include "VehicleStreamInHandler.h"
#include "VehicleStreamOutHandler.h"
