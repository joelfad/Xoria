/*
Project: Xoria
File: entity.cpp
Author: Joel McFadden
Created: July 17, 2015
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

#include "entity.hpp"

const Coord& Entity::getPos() const
{
    return pos_;
}

int Entity::getHealth() const
{
    return health_;
}

int Entity::getMaxHealth() const
{
    return maxHealth_;
}

int Entity::getDamage() const
{
    return damage_;
}

int Entity::getArmour() const
{
    return armour_;
}

int Entity::getAccuracy() const
{
    return accuracy_;
}

void Entity::render(TCODConsole* activeConsole) const
{
    activeConsole->putChar(pos_.x, pos_.y, glyph_);
    activeConsole->setCharForeground(pos_.x, pos_.y, fore_);
}
