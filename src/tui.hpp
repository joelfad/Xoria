/*
Project: Xoria
File: tui.hpp
Author: Joel McFadden
Created: July 13, 2015
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

#ifndef TUI_H
#define TUI_H

#include "constants.hpp"

class Game;

/// Text-based User Interface.
/// Abstract base class for user input, game logic, and display.
class Tui {
public:
    Tui(Game& game, int width = Settings::consoleWidth, int height = Settings::consoleHeight)
        : console_{width, height}, game_{game}, width_{width}, height_{height}, xPos{0}, yPos{0}, isOpen_{true} { }

    void waitForKeyPress();
    /* get user input */

    virtual void processNextEvent() = 0;
    /* respond to user input */

    virtual void render() = 0;
    /* update the display */

    void close();
    /* signal for game to destroy instance */

    bool isOpen() const;

protected:
    TCODConsole console_;
    Game& game_;
    int width_;
    int height_;
    int xPos;       // x-offset relative to root console (0, 0)
    int yPos;       // y-offset relative to root console (0, 0)
    TCOD_key_t lastKeyPressed_;
    bool isOpen_;
};

#endif // TUI_H
