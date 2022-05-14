#pragma tabsize 0
#pragma semicolon false

main() {
    return;
}

native cppOnGameModeInit();
public OnGameModeInit()
	return cppOnGameModeInit();

native cppOnGameModeExit();
public OnGameModeExit()
	return cppOnGameModeExit();

native cppOnPlayerConnect(playerid);
public OnPlayerConnect(playerid)
	return cppOnPlayerConnect(playerid);

native cppOnPlayerDisconnect(playerid, reason);
public OnPlayerDisconnect(playerid, reason)
	return cppOnPlayerDisconnect(playerid, reason);

native cppOnPlayerSpawn(playerid);
public OnPlayerSpawn(playerid)
	return cppOnPlayerSpawn(playerid);

native cppOnPlayerDeath(playerid, killerid, reason);
public OnPlayerDeath(playerid, killerid, reason)
	return cppOnPlayerDeath(playerid, killerid, reason);

native cppOnVehicleSpawn(vehicleid);
public OnVehicleSpawn(vehicleid)
	return cppOnVehicleSpawn(vehicleid);

native cppOnVehicleDeath(vehicleid, killerid);
public OnVehicleDeath(vehicleid, killerid)
	return cppOnVehicleDeath(vehicleid, killerid);

native cppOnPlayerText(playerid, text[]);
public OnPlayerText(playerid, text[])
	return cppOnPlayerText(playerid, text);

native cppOnPlayerCommandText(playerid, cmdtext[]);
public OnPlayerCommandText(playerid, cmdtext[])
	return cppOnPlayerCommandText(playerid, cmdtext);

native cppOnPlayerRequestClass(playerid, classid);
public OnPlayerRequestClass(playerid, classid)
	return cppOnPlayerRequestClass(playerid, classid);

native cppOnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
	return cppOnPlayerEnterVehicle(playerid, vehicleid, ispassenger);

native cppOnPlayerExitVehicle(playerid, vehicleid);
public OnPlayerExitVehicle(playerid, vehicleid)
	return cppOnPlayerExitVehicle(playerid, vehicleid);

native cppOnPlayerStateChange(playerid, newstate, oldstate);
public OnPlayerStateChange(playerid, newstate, oldstate)
	return cppOnPlayerStateChange(playerid, newstate, oldstate);

native cppOnPlayerEnterCheckpoint(playerid);
public OnPlayerEnterCheckpoint(playerid)
	return cppOnPlayerEnterCheckpoint(playerid);

native cppOnPlayerLeaveCheckpoint(playerid);
public OnPlayerLeaveCheckpoint(playerid)
	return cppOnPlayerLeaveCheckpoint(playerid);

native cppOnPlayerEnterRaceCheckpoint(playerid);
public OnPlayerEnterRaceCheckpoint(playerid)
	return cppOnPlayerEnterRaceCheckpoint(playerid);

native cppOnPlayerLeaveRaceCheckpoint(playerid);
public OnPlayerLeaveRaceCheckpoint(playerid)
	return cppOnPlayerLeaveRaceCheckpoint(playerid);

native cppOnRconCommand(cmd[]);
public OnRconCommand(cmd[])
	return cppOnRconCommand(cmd);

native cppOnPlayerRequestSpawn(playerid);
public OnPlayerRequestSpawn(playerid)
	return cppOnPlayerRequestSpawn(playerid);

native cppOnObjectMoved(objectid);
public OnObjectMoved(objectid)
	return cppOnObjectMoved(objectid);

native cppOnPlayerObjectMoved(playerid, objectid);
public OnPlayerObjectMoved(playerid, objectid)
	return cppOnPlayerObjectMoved(playerid, objectid);

native cppOnPlayerPickUpPickup(playerid, pickupid);
public OnPlayerPickUpPickup(playerid, pickupid)
	return cppOnPlayerPickUpPickup(playerid, pickupid);

native cppOnVehicleMod(playerid, vehicleid, componentid);
public OnVehicleMod(playerid, vehicleid, componentid)
	return cppOnVehicleMod(playerid, vehicleid, componentid);

native cppOnEnterExitModShop(playerid, enterexit, interiorid);
public OnEnterExitModShop(playerid, enterexit, interiorid)
	return cppOnEnterExitModShop(playerid, enterexit, interiorid);

native cppOnVehiclePaintjob(playerid, vehicleid, paintjobid);
public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
	return cppOnVehiclePaintjob(playerid, vehicleid, paintjobid);

native cppOnVehicleRespray(playerid, vehicleid, color1, color2);
public OnVehicleRespray(playerid, vehicleid, color1, color2)
	return cppOnVehicleRespray(playerid, vehicleid, color1, color2);

native cppOnVehicleDamageStatusUpdate(vehicleid, playerid);
public OnVehicleDamageStatusUpdate(vehicleid, playerid)
	return cppOnVehicleDamageStatusUpdate(vehicleid, playerid);

native cppOnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, new_x, new_y, new_z, vel_x, vel_y, vel_z);
public OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, new_x, new_y, new_z, vel_x, vel_y, vel_z)
	return cppOnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, new_x, new_y, new_z, vel_x, vel_y, vel_z);

native cppOnPlayerSelectedMenuRow(playerid, row);
public OnPlayerSelectedMenuRow(playerid, row)
	return cppOnPlayerSelectedMenuRow(playerid, row);

native cppOnPlayerExitedMenu(playerid);
public OnPlayerExitedMenu(playerid)
	return cppOnPlayerExitedMenu(playerid);

native cppOnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid);
public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
	return cppOnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid);

native cppOnPlayerKeyStateChange(playerid, newkeys, oldkeys);
public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
	return cppOnPlayerKeyStateChange(playerid, newkeys, oldkeys);

native cppOnRconLoginAttempt(ip[], password[], success);
public OnRconLoginAttempt(ip[], password[], success)
	return cppOnRconLoginAttempt(ip, password, success);

native cppOnPlayerUpdate(playerid);
public OnPlayerUpdate(playerid)
	return cppOnPlayerUpdate(playerid);

native cppOnPlayerStreamIn(playerid, forplayerid);
public OnPlayerStreamIn(playerid, forplayerid)
	return cppOnPlayerStreamIn(playerid, forplayerid);

native cppOnPlayerStreamOut(playerid, forplayerid);
public OnPlayerStreamOut(playerid, forplayerid)
	return cppOnPlayerStreamOut(playerid, forplayerid);

native cppOnVehicleStreamIn(vehicleid, forplayerid);
public OnVehicleStreamIn(vehicleid, forplayerid)
	return cppOnVehicleStreamIn(vehicleid, forplayerid);

native cppOnVehicleStreamOut(vehicleid, forplayerid);
public OnVehicleStreamOut(vehicleid, forplayerid)
	return cppOnVehicleStreamOut(vehicleid, forplayerid);

native cppOnActorStreamIn(actorid, forplayerid);
public OnActorStreamIn(actorid, forplayerid)
	return cppOnActorStreamIn(actorid, forplayerid);

native cppOnActorStreamOut(actorid, forplayerid);
public OnActorStreamOut(actorid, forplayerid)
	return cppOnActorStreamOut(actorid, forplayerid);

native cppOnDialogResponse(playerid, dialogid, response, listitem, inputtext[128]);
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[128])
	return cppOnDialogResponse(playerid, dialogid, response, listitem, inputtext);

native cppOnPlayerTakeDamage(playerid, issuerid, amount, weaponid, bodypart);
public OnPlayerTakeDamage(playerid, issuerid, amount, weaponid, bodypart)
	return cppOnPlayerTakeDamage(playerid, issuerid, amount, weaponid, bodypart);

native cppOnPlayerGiveDamage(playerid, damagedid, amount, weaponid, bodypart);
public OnPlayerGiveDamage(playerid, damagedid, amount, weaponid, bodypart)
	return cppOnPlayerGiveDamage(playerid, damagedid, amount, weaponid, bodypart);

native cppOnPlayerClickMap(playerid, fX, fY, fZ);
public OnPlayerClickMap(playerid, fX, fY, fZ)
	return cppOnPlayerClickMap(playerid, fX, fY, fZ);

native cppOnPlayerClickTextDraw(playerid, clickedid);
public OnPlayerClickTextDraw(playerid, clickedid)
	return cppOnPlayerClickTextDraw(playerid, clickedid);

native cppOnPlayerClickPlayerTextDraw(playerid, textid);
public OnPlayerClickPlayerTextDraw(playerid, textid)
	return cppOnPlayerClickPlayerTextDraw(playerid, textid);

native cppOnIncomingConnection(playerid, ip_address[], port);
public OnIncomingConnection(playerid, ip_address[], port)
	return cppOnIncomingConnection(playerid, ip_address, port);

native cppOnTrailerUpdate(playerid, vehicleid);
public OnTrailerUpdate(playerid, vehicleid)
	return cppOnTrailerUpdate(playerid, vehicleid);

native cppOnVehicleSirenStateChange(playerid, vehicleid, newstate);
public OnVehicleSirenStateChange(playerid, vehicleid, newstate)
	return cppOnVehicleSirenStateChange(playerid, vehicleid, newstate);

native cppOnPlayerClickPlayer(playerid, clickedplayerid, source);
public OnPlayerClickPlayer(playerid, clickedplayerid, source)
	return cppOnPlayerClickPlayer(playerid, clickedplayerid, source);

native cppOnPlayerEditObject(playerid, playerobject, objectid, response, fX, fY, fZ, fRotX, fRotY, fRotZ);
public OnPlayerEditObject(playerid, playerobject, objectid, response, fX, fY, fZ, fRotX, fRotY, fRotZ)
	return cppOnPlayerEditObject(playerid, playerobject, objectid, response, fX, fY, fZ, fRotX, fRotY, fRotZ);

native cppOnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ);
public OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ)
	return cppOnPlayerEditAttachedObject(playerid, response, index, modelid, boneid,fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ);

native cppOnPlayerSelectObject(playerid, type, objectid, modelid, fX, fY, fZ);
public OnPlayerSelectObject(playerid, type, objectid, modelid, fX, fY, fZ)
	return cppOnPlayerSelectObject(playerid, type, objectid, modelid, fX, fY, fZ);

native cppOnPlayerWeaponShot(playerid, weaponid, hittype, hitid, fX, fY, fZ);
public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, fX, fY, fZ)
	return cppOnPlayerWeaponShot(playerid, weaponid, hittype, hitid, fX, fY, fZ);
