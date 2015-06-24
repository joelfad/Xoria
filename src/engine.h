/*
Project: Xoria
File: engine.h
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

#ifndef ENGINE_H
#define ENGINE_H

#include <libtcod/libtcod.hpp>
#include "map.h"

class Engine
{
public:
    Engine();
    /* initializes the root console window */

    void render();
    /* updates the root console */

    void process_next_event();
    /* wait for user input and execute corresponding command */

    bool is_running() { return running; }


private:
    int player_x;
    int player_y;
    bool running;
    Map map;
};

#endif // ENGINE_H
