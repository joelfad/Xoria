/*
Project: Xoria
File: map.h
Author: Joel McFadden
Created: June 19, 2015
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

#ifndef MAP_H
#define MAP_H

#include <vector>
#include "constants.h"

class Map {
public:
    Map(int width = Settings::consoleWidth, int height = Settings::consoleHeight);

    void render() const;
    /* draw map tiles on root console */

private:
    int width_;
    int height_;
    std::vector<const Tile*> tiles_;

public:
    int playerX_;   // TEMP
    int playerY_;   // TEMP
};

#endif // MAP_H
