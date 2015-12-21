/*
Project: Xoria
File: game.hpp
Author: Joel McFadden
Created: June 19, 2015
Last Modified: July 26, 2015

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
#include <libtcod/libtcod.hpp>
#include "tui.hpp"
#include "world.hpp"

/// Manages the game state and TUI stack.
/// Initializes, runs, and terminates the game.
class Game {
public:
    Game();
    /* initialize */

    void run();

    bool isRunning();

    Map& currentMap();

    using TuiStack = std::vector<std::unique_ptr<Tui>>;
    // conceptual "stack" implemented with std::vector for iterators

    template <class T>
    void openNew();
    /* add Tui to top of Tui stack */

private:
    World world_;       // collection of maps
    TuiStack consoles_; // text-based user interface stack

    void closeConsoleCheck();
    /* remove top console if closed */

    void renderConsoles();
    /* render Tui stack on root console */
};

#endif // GAME_H
