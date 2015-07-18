/*
Project: Xoria
File: mapobject.h
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

#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <string>
#include <libtcod.hpp>

/// Building blocks of a map
/// Abstract base class for tiles, entities, items, etc.
class MapObject {
protected:
    MapObject(const std::string& name,
              const std::string& description,
              int glyph,
              const TCODColor& fore)
        : name_{name}, description_{description}, glyph_{glyph}, fore_{fore}
    { }

    struct Coord;

    std::string name_;
    std::string description_;
    int glyph_;
    TCODColor fore_;
};

/// Set of (x, y) coordinates on a map.
struct MapObject::Coord {
    int x;
    int y;

    // TODO: overload operators
    // bool operator==(const Coord& lhs, const Coord& rhs);
};

#endif // MAPOBJECT_H
