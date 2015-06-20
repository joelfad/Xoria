/*
 * Project: Xoria
 * File Name: map.cpp
 * Author: Joel McFadden
 * Created: June 19, 2015
 * Last Modified: June 20, 2015
 *
 * Description: A simple sci-fi roguelike.
 *
 * Copyright (C) Joel McFadden 2015
 * License:
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "map.h"

Map::Map(int _width, int _height) : width{_width}, height{_height}, tiles{(std::vector<const Tile*>::size_type) (_width * _height), nullptr}
{
    for (auto& t : tiles)
        t = &TileSet::GRASS;

    tiles[34] = &TileSet::WALL;
}

void Map::render()
{
    for (int i = 0; i < width * height; i++)
        tiles.at(i)->render(i % width, i / width);

}
