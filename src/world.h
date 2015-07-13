/*
Project: Xoria
File: world.h
Author: Joel McFadden
Created: July 12, 2015
Last Modified: July 12, 2015

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
#include "map.h"

class World
{
public:
    World(const int numMaps);
    /* generate default maps */

    static void makeCave(Map& map);
    /* turn a default map into a cave map */

    std::weak_ptr<Map> currentMap() { return currentMap_; }

    using MapVector = std::vector<std::shared_ptr<Map>>;

private:
    MapVector maps_;
    std::weak_ptr<Map> currentMap_;
};

#endif // WORLD_H
