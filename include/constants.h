/*
Project: Xoria
File: constants.h
Author: Joel McFadden
Created: June 19, 2015
Last Modified: July 28, 2015

Description:
    A simple sci-fi roguelike.

Copyright (C) 2015 Joel McFadden

Usage Agreement:
    This file is part of Xoria.

    Xoria is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Xoria is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Xoria.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONSTANTS
#define CONSTANTS

#include "tile.h"
#include "monster.h"

namespace Settings {
    const int consoleWidth = 80;
    const int consoleHeight = 48;
}

namespace Default {
    const std::string playerName = "Explorer";
    const std::string playerDescription = "A fearless hero, lost on an alien world...";
    const TCODColor playerColor = TCODColor::lightAzure;
    const int playerHealth = 10;
    const int playerDamage = 1;
    const int playerArmour = 0;
    const int playerAccuracy = 1;
}

enum class TileFlag : uint_fast32_t {
    canWalk     = 0x0001,       // 0
    canSwim     = 0x0002,       // 1
    canFly      = 0x0004,       // 2
    canBreathe  = 0x0008,       // 3
    canDig      = 0x0010,       // 4
    canOpen     = 0x0020,       // 5
    canPush     = 0x0040,       // 6

    visible     = 0x0080,       // 7
    discovered  = 0x0100,       // 8

    hasEntity   = 0x0200,       // 9
    hasItem     = 0x0400,       // 10
    hasPortal   = 0x0800,       // 11
    hasEvent    = 0x1000        // 12

 // MAX_FLAG    = 0x8000'0000   // 31
};

namespace TileSet {
    const Tile grass{"Grass", "green vegetation", '.', TCODColor::darkestChartreuse, TCODColor::black, 0x0005};
    const Tile wall{"Wall", "rock wall", '#', TCODColor::lightPink, TCODColor::black, 0x0000};
}

namespace MonsterSet {
    const Monster spaceSlug{"Space Slug", "harmless alien gastropod", 's', TCODColor::lightGreen, 1, 2, 1, 0, 1, true};
}

#endif // CONSTANTS
