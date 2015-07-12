/*
Project: Xoria
File: game.cpp
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

#include "game.h"

Game::Game() : playerX_{2}, playerY_{0}, running_{true}, map_{80, 48}
{
    // specify the font file, set to antialiased greyscale
    TCODConsole::setCustomFont("fonts/terminal16x16_gs_ro.png", TCOD_FONT_LAYOUT_ASCII_INROW | TCOD_FONT_TYPE_GREYSCALE);

    // initialize root console window
    TCODConsole::initRoot(80, 48, "Xoria");
}

void Game::render()
{
    // clear console
    TCODConsole::root->clear();

    // draw map
    map_.render();

    // TEST
    TCODConsole::root->putChar(playerX_, playerY_, '@');
    TCODConsole::root->setCharForeground(playerX_, playerY_, TCODColor::lightAzure);

    // apply updates
    TCODConsole::root->flush();
}

void Game::processNextEvent()
{
    // get keypress (blocking)
    TCOD_key_t key;
    TCODSystem::waitForEvent(TCOD_EVENT_KEY_PRESS, &key, nullptr, true);

    //
    switch (key.vk) {
    case TCODK_UP:
        playerY_--;
        break;
    case TCODK_DOWN:
        playerY_++;
        break;
    case TCODK_LEFT:
        playerX_--;
        break;
    case TCODK_RIGHT:
        playerX_++;
        break;
    default:
        break;
    }

    if (key.c) {
        switch (key.c) {
        case 'Q':
            running_ = false;
            break;
        default:
            break;
        }
    }
}
