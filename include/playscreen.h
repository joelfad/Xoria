/*
Project: Xoria
File: playscreen.h
Author: Joel McFadden
Created: July 13, 2015
Last Modified: July 22, 2015

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

#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include "tui.h"

/// Gameplay Screen.
/// The primary interface where users will spend most of their time.
class PlayScreen : public Tui {
public:
    PlayScreen(World& world, int width = Settings::consoleWidth, int height = Settings::consoleHeight);

    virtual std::unique_ptr<Tui> processNextEvent() override;
    /* respond to user input */

    virtual void render() override;
    /* update the display */

private:
    std::unique_ptr<Tui> processPlayerEvent();
    /* player's turn */

    void processMonsterEvents();
    /* monsters' turns */
};

#endif // PLAYSCREEN_H
