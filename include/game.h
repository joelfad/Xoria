/*
Project: Xoria
File: game.h
Author: Joel McFadden
Created: June 19, 2015
Last Modified: July 15, 2015

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

#include <vector>
#include <memory>
#include <libtcod.hpp>
#include "playscreen.h"

class World;

/// Manages the game state and TUI stack.
/// Initializes, runs, and terminates the game.
class Game {
public:
    Game();
    /* initialize */

    void run();

    bool isRunning();

    using TUIStack = std::vector<std::unique_ptr<Tui>>;
    // conceptual "stack" implemented with std::vector for iterators

private:
    World world_;       // collection of maps
    TUIStack consoles_; // text-based user interface stack

    void renderConsoles();
    /* render TUI stack on root console */
};

#endif // GAME_H