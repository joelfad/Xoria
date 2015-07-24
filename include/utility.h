/*
Project: Xoria
File: utility.h
Author: Joel McFadden
Created: July 22, 2015
Last Modified: July 23, 2015

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

#ifndef UTILITY_H
#define UTILITY_H

#include <random>

namespace Utility {

extern uint16_t seed;
extern std::mt19937 RNG;

void init(uint16_t setSeed = 0);
/* seed may be specified using setSeed (optional) */

int randInt(int min, int max);
/* gets a random integer between min and max (inclusive) */

int rollD(int numSides);
/* rolls a numSides sided dice */
















}

#endif // UTILITY_H
