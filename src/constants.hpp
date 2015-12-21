/*
Project: Xoria
File: constants.hpp
Author: Joel McFadden
Created: June 19, 2015
Last Modified: July 31, 2015

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

#include "tile.hpp"
#include "monster.hpp"

namespace Settings {
    const int consoleWidth = 80;
    const int consoleHeight = 48;
}

namespace Default {
    const std::string playerName = "Explorer";
    const std::string playerDescription = "A fearless hero, lost on an alien world...";
    const TCODColor playerColor = TCODColor::white;
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
    hasEvent    = 0x1000,       // 12

    walkUnder   = 0x2000,       // 13
    allowItems  = 0x3000        // 14

 // MAX_FLAG    = 0x8000'0000   // 31
};

namespace TileSet {
    const Tile grass            {"Grass",           "a patch of alien grass",
                                 '"',  TCODColor::darkestSea,       TCODColor::black,           0x300d};
    const Tile rockWall         {"Rock Wall",       "a rock wall",
                                 0xb1, TCODColor::grey,             TCODColor::black,           0x0000};
    const Tile dirtWall         {"Dirt Wall",       "a dirt wall",
                                 0xb2, TCODColor::darkSepia,        TCODColor::black,           0x0010};
    const Tile iceWall          {"Ice Wall",        "a frozen wall",
                                 0xb0, TCODColor::desaturatedAzure, TCODColor::black,           0x0010};
    const Tile metalWall        {"Metal Wall",      "a metal wall",
                                 '#',  TCODColor::darkGrey,         TCODColor::darkestGrey,     0x0000};
    const Tile doorClosed       {"Closed Door",     "a closed door",
                                 '+',  TCODColor::lightGrey,        TCODColor::darkerGrey,      0x0028};
    const Tile doorOpen         {"Open Door",       "an open door",
                                 '_',  TCODColor::lightGrey,        TCODColor::darkerGrey,      0x002d};
    const Tile tree             {"Tree",            "a lush subterranean tree",
                                 'T',  TCODColor::darkGreen,        TCODColor::black,           0x500d};
    const Tile shrub            {"Shrub",           "a hardy cave shrub",
                                 '&',  TCODColor::darkerGreen,      TCODColor::black,           0x300d};
    const Tile waterShallow     {"Shallow Water",   "tranquil sparkling water",
                                 '~',  TCODColor::azure,            TCODColor::darkerAzure,     0x000e};
    const Tile waterDeep        {"Deep Water",      "the effervescent deep",
                                 '~',  TCODColor::darkAzure,        TCODColor::darkestAzure,    0x000e};
    const Tile lava             {"Lava",            "fiery magma from the molten core",
                                 '~',  TCODColor::lighterOrange,    TCODColor::flame,           0x100e};
    const Tile mud              {"Mud",             "sticky mud",
                                 0xf9, TCODColor::sepia,            TCODColor::darkestSepia,    0x300d};
    const Tile dirtGround       {"Dirt",            "the dusty ground",
                                 '.',  TCODColor::darkerSepia,      TCODColor::black,           0x300d};
    const Tile rockGround       {"Rock",            "the rocky ground",
                                 '.',  TCODColor::darkerGrey,       TCODColor::black,           0x300d};
    const Tile iceGround        {"Ice",             "the icy ground",
                                 '.',  TCODColor::darkestSky,       TCODColor::black,           0x300d};
    const Tile rubble           {"Rubble",          "rocky debris",
                                 ',',  TCODColor::darkGrey,         TCODColor::black,           0x300d};
    const Tile minerals         {"Minerals",        "some luminous crystals",
                                 ',',  TCODColor::sky,              TCODColor::black,           0x0000};
    const Tile chasm            {"Chasm",           "a fissure into the black depths",
                                 0x7c, TCODColor::darkestBlue,      TCODColor::black,           0x080d};
    const Tile airlock          {"Open Airlock",    "automatic airlock",
                                 0x07, TCODColor::lightGrey,        TCODColor::darkerGrey,      0x102d};
    const Tile portal           {"Portal",          "an interdimensional portal",
                                 0xea, TCODColor::lighterViolet,    TCODColor::black,           0x080d};
    const Tile descend          {"Descend",         "access to lower levels",
                                 '>',  TCODColor::lightestYellow,   TCODColor::black,           0x080d};
    const Tile ascend           {"Ascend",          "access to upper levels",
                                 '<',  TCODColor::lightestYellow,   TCODColor::black,           0x080d};
    const Tile elevator         {"Elevator",        "a transport between levels",
                                 0x12, TCODColor::lightestYellow,   TCODColor::darkerGrey,      0x180d};
    const Tile fieldUpOn        {"Forcefield Up",   "a guiding forcefield",
                                 0x18, TCODColor::lighterBlue,      TCODColor::black,           0x100d};
    const Tile fieldDownOn      {"Forcefield Up",   "a guiding forcefield",
                                 0x19, TCODColor::lighterBlue,      TCODColor::black,           0x100d};
    const Tile fieldRightOn     {"Forcefield Up",   "a guiding forcefield",
                                 0x1a, TCODColor::lighterBlue,      TCODColor::black,           0x100d};
    const Tile fieldLeftOn      {"Forcefield Up",   "a guiding forcefield",
                                 0x1b, TCODColor::lighterBlue,      TCODColor::black,           0x100d};
    const Tile fieldUpOff       {"Forcefield Up",   "a guiding forcefield",
                                 0x18, TCODColor::darkerGrey,       TCODColor::black,           0x100d};
    const Tile fieldDownOff     {"Forcefield Up",   "a guiding forcefield",
                                 0x19, TCODColor::darkerGrey,       TCODColor::black,           0x100d};
    const Tile fieldRightOff    {"Forcefield Up",   "a guiding forcefield",
                                 0x1a, TCODColor::darkerGrey,       TCODColor::black,           0x100d};
    const Tile fieldLeftOff     {"Forcefield Up",   "a guiding forcefield",
                                 0x1b, TCODColor::darkerGrey,       TCODColor::black,           0x100d};
    const Tile switchOn         {"Switch On",       "an activated switch",
                                 0x1c, TCODColor::lightestGrey,     TCODColor::black,           0x100d};
    const Tile switchOff        {"Switch Off",      "a disengaged switch",
                                 0x1c, TCODColor::darkerGrey,       TCODColor::black,           0x100d};
}

namespace MonsterSet {
    const Monster spaceSlug{"Space Slug", "harmless alien gastropod", 's', TCODColor::lightGreen, 1, 2, 1, 0, 1, true};
}

#endif // CONSTANTS
