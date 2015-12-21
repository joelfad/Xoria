/*
Project: Xoria
File: monster.hpp
Author: Joel McFadden
Created: July 21, 2015
Last Modified: July 25, 2015

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

#ifndef MONSTER_H
#define MONSTER_H

#include "entity.hpp"

/// Creature inhabiting game world
/// Entity not controlled by user.
class Monster : public Entity {
public:
    Monster(const std::string& name,
            const std::string& description,
            int glyph,
            const TCODColor& color,
            int initialHealth,
            int maxHealth,
            int damage,
            int armour,
            int accuracy,
            bool friendly)
        : Entity{Coord(-1, -1),
                 name,
                 description,
                 glyph,
                 color,
                 initialHealth,
                 maxHealth,
                 damage,
                 armour,
                 accuracy}, friendly_{friendly}
    { }

    Monster(const Coord& pos, const Monster& other);

    bool isFriendly() const;
    /* returns true if creature is non-hostile */

    virtual void move(int dx, int dy) override;

private:
    bool friendly_;
};

#endif // MONSTER_H
