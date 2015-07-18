/*
Project: Xoria
File: player.h
Author: Joel McFadden
Created: July 18, 2015
Last Modified: July 18, 2015

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

#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

/// Player Character
/// Entity controlled by user.
class Player : public Entity {
public:
    Player(const Coord& pos,
           const std::string& name  = Default::playerName,
           int health               = Default::playerHealth,
           int damage               = Default::playerDamage,
           int armour               = Default::playerArmour,
           int accuracy             = Default::playerAccuracy)
       : Entity{pos,
                name,
                Default::playerDescription,
                '@',
                Default::playerColor,
                health,
                health,
                damage,
                armour,
                accuracy}
    { }

    int energy() const { return energy_; }
    /* returns the number of energy tokens the player is carrying */

private:
    // non-inventory quantities
    int energy_;
};

#endif // PLAYER_H
