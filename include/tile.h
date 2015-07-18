/*
Project: Xoria
File: tile.h
Author: Joel McFadden
Created: June 19, 2015
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

#ifndef TILE_H
#define TILE_H

#include "mapobject.h"

/// Discrete element of game environment
class Tile : public MapObject {
public:
    Tile(const std::string& name,
         const std::string& description,
         int glyph,
         const TCODColor& fore,
         const TCODColor& back)
        : MapObject{name, description, glyph, fore}, back_{back}
    { }

    void render(TCODConsole* activeConsole, int x, int y) const;
    /* draw tile to active console */

private:
    TCODColor back_;
};

#endif // TILE_H
