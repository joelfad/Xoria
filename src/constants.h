/*
Project: Xoria
File: constants.h
Author: Joel McFadden
Created: June 19, 2015
Last Modified: June 23, 2015

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

#include <libtcod/libtcod.hpp>
#include "tile.h"

namespace TileSet {
    const Tile GRASS{"Grass", "green vegetation", '.', TCODColor::darkestChartreuse, TCODColor::black};
    const Tile WALL{"Wall", "rock wall", '#', TCODColor::lightPink, TCODColor::black};
}


#endif // CONSTANTS

