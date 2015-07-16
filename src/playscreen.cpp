/*
Project: Xoria
File: playscreen.cpp
Author: Joel McFadden
Created: July 13, 2015
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

#include "playscreen.h"

PlayScreen::PlayScreen(World& world, int width, int height)
    : Tui{world, width, height}
{
}

std::unique_ptr<Tui> PlayScreen::processNextEvent()
{
    int& playerX = world_.currentMap().playerX_; // TEMP
    int& playerY = world_.currentMap().playerY_; // TEMP

    // move player
    switch (lastKeyPressed_.vk) {
    case TCODK_UP:
        playerY--;
        break;
    case TCODK_DOWN:
        playerY++;
        break;
    case TCODK_LEFT:
        playerX--;
        break;
    case TCODK_RIGHT:
        playerX++;
        break;
    default:
        break;
    }

    // quit game
    if (lastKeyPressed_.c) {
        switch (lastKeyPressed_.c) {
        case 'Q':
            close();
            break;
        default:
            break;
        }
    }

    return nullptr;
}

void PlayScreen::render()
{
    // clear screen
    console_.clear();

    // draw map
    world_.currentMap().render(&console_);

    // draw player
    // TODO: move Player to its own class
    int playerX = world_.currentMap().playerX_; // TEMP
    int playerY = world_.currentMap().playerY_; // TEMP

    console_.putChar(playerX, playerY, '@');
    console_.setCharForeground(playerX, playerY, TCODColor::lightAzure);

    // blit to root console
    TCODConsole::blit(&console_, 0, 0, 0, 0, TCODConsole::root, 0, 0);
}
