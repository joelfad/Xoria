/*
Project: Xoria
File: coord.hpp
Author: Joel McFadden
Created: July 19, 2015
Last Modified: July 20, 2015

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

#ifndef COORD_H
#define COORD_H

#include <cmath>

/// Set of (x, y) map coordinates.
struct Coord {
    int x;
    int y;

    Coord(int x = 0, int y = 0) : x{x}, y{y}
    { }

    void set(int newX, int newY);
    /* changes coordinates to (newX, newY) */

    void offset(int dx, int dy);
    /* changes coordinates to (x+dx, y+dy) */

    static double distance(const Coord& c1, const Coord& c2);
    /* computes the distance between two map coordinates */

    bool operator==(const Coord& rhs) const;
    /* compares two sets of map coordinates for equality */

    bool operator!=(const Coord& rhs) const;
    /* compares two sets of map coordinates for inequality */
};

#endif // COORD_H
