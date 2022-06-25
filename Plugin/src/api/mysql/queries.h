//
// Created by dubininvyu on 09.05.2022.
//

#pragma once

#include <string>

using namespace std;

string MYSQL_QUERY_GET_CONFIG_RCON = "SELECT DISTINCT (data ->> '$.rcon.weburl') AS `weburl`, (data ->> '$.rcon.gravity') AS `gravity`, (data ->> '$.rcon.mapname') AS `mapname`,	(data ->> '$.rcon.weather') AS `weather`, (data ->> '$.rcon.hostname') AS `hostname`,	(data ->> '$.rcon.language') AS `language`,	(data ->> '$.rcon.password') AS `password`,	(data ->> '$.rcon.ackslimit') AS `ackslimit`,	(data ->> '$.rcon.worldtime') AS `worldtime`,	(data ->> '$.rcon.gamemodetext') AS `gamemodetext`,	(data ->> '$.rcon.messageslimit') AS `messageslimit`,	(data ->> '$.rcon.playertimeout') AS `playertimeout`,	(data ->> '$.rcon.rcon_password') AS `rcon_password`,	(data ->> '$.rcon.messageholelimit') AS `messageholelimit` FROM `configs` WHERE `type` = 'rcon' LIMIT 1";