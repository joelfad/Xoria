/*
Project: Xoria
File: world.hpp
Author: Joel McFadden
Created: July 12, 2015
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

#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>
#include "map.hpp"

/// Collection of Maps.
/// Generates and stores game maps.
class World {
public:
    World(const int numMaps);
    /* generates default maps */

    Map& currentMap() const;
    /* provides access to the current map */

    static void makeCave(Map& map);
    /* turns a default map into a cave map */

    using MapVector = std::vector<std::unique_ptr<Map>>;

private:
    MapVector maps_;
    MapVector::size_type currentMapNo_;
};

#endif // WORLD_H
