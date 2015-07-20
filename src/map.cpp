/*
Project: Xoria
File: map.cpp
Author: Joel McFadden
Created: June 19, 2015
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

#include "map.h"

Map::Map(int width, int height)
    : width_{width}, height_{height}, tiles_{width * height, nullptr}
{
    // create a default map filled with grass and one wall
    for (auto& t : tiles_)
        t = &TileSet::grass;

    tiles_.at(34) = &TileSet::wall;

    entities_.push_front(std::make_unique<Player>(Coord(5, 3)));
}

void Map::render(TCODConsole* activeConsole) const
{
    // render tiles
    for (int i = 0; i < width_ * height_; i++)
        tiles_.at(i)->render(activeConsole, i % width_, i / width_);

    // render entities
    for (auto& e : entities_)
        e->render(activeConsole);
}

Entity& Map::getPlayer()
{
    return *entities_.front();
}
