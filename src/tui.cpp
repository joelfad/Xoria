/*
Project: Xoria
File: Tui.cpp
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

#include "tui.hpp"

void Tui::waitForKeyPress()
{
    // get keypress (blocking)
    TCODSystem::waitForEvent(TCOD_EVENT_KEY_PRESS, &lastKeyPressed_, nullptr, true);
}

void Tui::close()
{
    isOpen_ = false;
}

bool Tui::isOpen() const
{
    return isOpen_;
}
