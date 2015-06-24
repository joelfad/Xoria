/*
Project: Xoria
File: engine.cpp
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

#include "engine.h"

Engine::Engine() : player_x{2}, player_y{0}, running{true}, map{80, 48}
{
    // specify the font file, set to antialiased greyscale
    TCODConsole::setCustomFont("fonts/terminal16x16_gs_ro.png", TCOD_FONT_LAYOUT_ASCII_INROW | TCOD_FONT_TYPE_GREYSCALE);

    // initialize root console window
    TCODConsole::initRoot(80, 48, "Xoria");

    // display libtcod credits
    // TCODConsole::credits();
}

void Engine::render()
{
    // clear console
    TCODConsole::root->clear();

    // update console


    // draw map
    map.render();

    // draw creatures
    // @@@ TODO @@@


    // TEST
    TCODConsole::root->putChar(player_x, player_y, '@');
    TCODConsole::root->setCharForeground(player_x, player_y, TCODColor::lightAzure);



    // apply updates
    TCODConsole::root->flush();
}

void Engine::process_next_event()
{
    // get keypress (non-blocking)
    TCOD_key_t key;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, nullptr);

    //
    switch(key.vk) {
    case TCODK_UP:
        player_y--;
        break;
    case TCODK_DOWN:
        player_y++;
        break;
    case TCODK_LEFT:
        player_x--;
        break;
    case TCODK_RIGHT:
        player_x++;
        break;
    default:
        break;
    }

    if(key.c) {
        switch(key.c) {
        case 'Q':
            running = false;
            break;
        default:
            break;
        }
    }
}
