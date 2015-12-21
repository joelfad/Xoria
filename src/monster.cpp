/*
Project: Xoria
File: monster.cpp
Author: Joel McFadden
Created: July 21, 2015
Last Modified: December 21, 2015

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

#include "monster.hpp"

Monster::Monster(const Coord &pos, const Monster& m)
    : Entity{pos,
             m.name_,
             m.description_,
             m.glyph_,
             m.fore_,
             m.health_,
             m.maxHealth_,
             m.damage_,
             m.armour_,
             m.accuracy_}, friendly_{m.friendly_}
{
}

bool Monster::isFriendly() const
{
    return friendly_;
}

void Monster::move(int dx, int dy)
{
    pos_.offset(dx, dy);
}
