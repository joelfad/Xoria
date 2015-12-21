/*
Project: Xoria
File: coord.cpp
Author: Joel McFadden
Created: July 19, 2015
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

#include "coord.hpp"

void Coord::set(int newX, int newY)
{
    x = newX;
    y = newY;
}

void Coord::offset(int dx, int dy)
{
    x += dx;
    y += dy;
}

double Coord::distance(const Coord& c1, const Coord& c2)
{
    int dx = c1.x - c2.x;
    int dy = c1.y - c2.y;

    return sqrt((dx * dx) + (dy * dy));
}

bool Coord::operator==(const Coord& rhs) const
{
    return (x == rhs.x) && (y == rhs.y);
}

bool Coord::operator!=(const Coord& rhs) const
{
    return !Coord::operator ==(rhs);
}
