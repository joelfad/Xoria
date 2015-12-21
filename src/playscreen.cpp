/*
Project: Xoria
File: playscreen.cpp
Author: Joel McFadden
Created: July 13, 2015
Last Modified: December 21, 2015

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

#include "playscreen.hpp"

PlayScreen::PlayScreen(Game& game, int width, int height)
    : Tui{game, width, height}
{
}

void PlayScreen::processNextEvent()
{
    if (!playerTurn())
        return; // player has not made a turn, skip monsters

    monsterTurns();
}

void PlayScreen::render()
{
    // clear screen
    console_.clear();

    // draw map
    game_.currentMap().render(&console_);

    // blit to root console
    TCODConsole::blit(&console_, 0, 0, 0, 0, TCODConsole::root, 0, 0);
}

bool PlayScreen::playerTurn()
{
    Entity& player = game_.currentMap().getPlayer();

    // move player
    if (lastKeyPressed_.vk == TCODK_CHAR) {
        switch (lastKeyPressed_.c) {
        case 'Q':                   // quit game
            close();
            // fallthrough
        default:
            return false;
        }
    }
    else {
        switch (lastKeyPressed_.vk) {
        case TCODK_UP:
            tryMove(player,  0, -1); // move up
            break;
        case TCODK_DOWN:
            tryMove(player,  0,  1); // move down
            break;
        case TCODK_LEFT:
            tryMove(player, -1,  0); // move left
            break;
        case TCODK_RIGHT:
            tryMove(player,  1,  0); // move right
            break;
        case TCODK_SPACE:
            break;                   // skip turn
        default:
            return false;
        }
    }

    // player has made a turn
    return true;
}

void PlayScreen::monsterTurns()
{
    // iterate through monsters
    for (auto it = game_.currentMap().beginMonsters(); it != game_.currentMap().endMonsters(); ++it) {

        // move randomly
        switch (Utility::randInt(0, 4)) {
        case 1:
            tryMove(**it,  0, -1); // move up
            break;
        case 2:
            tryMove(**it,  0,  1); // move down
            break;
        case 3:
            tryMove(**it, -1,  0); // move left
            break;
        case 4:
            tryMove(**it,  1,  0); // move right
            break;
        default:
            break;                 // skip turn
        }
    }
}

void PlayScreen::tryMove(Entity& entity, int dx, int dy)
{
    Properties& thisTile = game_.currentMap().getProps(entity.getPos());
    Properties& nextTile = game_.currentMap().getProps(entity.getPos().x + dx, entity.getPos().y + dy);

    if (nextTile.get(TileFlag::canWalk) && !nextTile.get(TileFlag::hasEntity)) {
        entity.move(dx, dy);
        thisTile.setOff(TileFlag::hasEntity);
        nextTile.setOn( TileFlag::hasEntity);
    }
}
