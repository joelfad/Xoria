/*
 * Project: Xoria
 * File Name: tile.h
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

#ifndef TILE_H
#define TILE_H

#include <libtcod/libtcod.hpp>
#include <string>


class Tile
{
public:
    Tile(const std::string& _name, const std::string& _description, int _glyph, const TCODColor& _fore, const TCODColor& _back)
        : name{_name}, description{_description}, glyph{_glyph}, fore{_fore}, back{_back} {}

    void render(int x, int y) const;
    /* draw tile to root console */

private:
    std::string name;
    std::string description;
    int glyph;
    TCODColor fore;
    TCODColor back;
};

#endif // TILE_H
