/*
Project: Xoria
File: entity.h
Author: Joel McFadden
Created: July 17, 2015
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

#ifndef ENTITY_H
#define ENTITY_H

#include "mapobject.h"

/// Beings that interact with the game environment.
/// Abstract base class for creatures, npcs, and player.
class Entity : public MapObject {
public:
    int health()    const { return health_; }
    int maxHealth() const { return maxHealth_; }
    int damage()    const { return damage_; }
    int armour()    const { return armour_; }
    int accuracy()  const { return accuracy_; }

protected:
    Entity(const std::string& name,
           const std::string& description,
           int glyph,
           const TCODColor& fore,
           const TCODColor& back,
           const Coord& pos,
           int health,
           int maxHealth,
           int damage,
           int armour,
           int accuracy)
       : MapObject{name, description, glyph, fore, back},
         pos_{pos}, health_{health}, maxHealth_{maxHealth}, damage_{damage}, armour_{armour}, accuracy_{accuracy} { }

    Coord pos_;
    int health_;
    int maxHealth_;
    int damage_;
    int armour_;
    int accuracy_;
    // TODO: add item storage
};

#endif // ENTITY_H
