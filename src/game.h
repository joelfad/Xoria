/*
Project: Xoria
File: game.h
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

#ifndef GAME_H
#define GAME_H

#include <libtcod/libtcod.hpp>
#include "world.h"

class Game {
public:
    Game();
    /* initializes the root console window */

    void render() const;
    /* updates the root console */

    void processNextEvent();
    /* wait for user input and execute corresponding command */

    bool isRunning() const { return running_; }

private:
    int playerX_;
    int playerY_;
    bool running_;
    World world_;
};

#endif // GAME_H
