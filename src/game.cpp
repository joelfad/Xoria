/*
Project: Xoria
File: game.cpp
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

#include "game.h"

Game::Game() : world_{1}
{
    // specify the font file, set to antialiased greyscale
    TCODConsole::setCustomFont("fonts/terminal16x16_gs_ro.png", TCOD_FONT_LAYOUT_ASCII_INROW | TCOD_FONT_TYPE_GREYSCALE);

    // initialize root console window
    TCODConsole::initRoot(Settings::consoleWidth, Settings::consoleHeight, "Xoria");

    // build TUI stack
    consoles_.push_back(std::make_unique<PlayScreen>(world_));
}

void Game::run()
{
    while (isRunning()) {
        // update display
        renderConsoles();

        // wait for user input
        consoles_.back()->waitForKeyPress();

        // respond to input
        consoles_.back()->processNextEvent();

        // destroy top console if no longer open
        if (!consoles_.back()->isOpen())
            consoles_.pop_back();
    }
}

bool Game::isRunning()
{
    return (!consoles_.empty() && !TCODConsole::root->isWindowClosed());
}

void Game::renderConsoles()
{
    // render TUI stack (from the bottom up)
    for (auto& it : consoles_)
        it->render();

    // push frame to root console
    TCODConsole::root->flush();
}
