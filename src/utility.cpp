/*
Project: Xoria
File: utility.cpp
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

#include "utility.h"

uint16_t Utility::seed;
std::mt19937 Utility::RNG;

void Utility::init(uint16_t setSeed)
{
    /* Initialize RNG */

    // generate new seed if not provided
    if (setSeed == 0) {
        std::random_device rd;
        std::uniform_int_distribution<int> seedDist(1, UINT16_MAX);
        std::mt19937 generateNewSeed(rd());
        seed = seedDist(generateNewSeed);
    }
    // otherwise, set seed to provided value
    else {
        seed = setSeed;
    }

    // seed the random number generator
    RNG.seed(seed);
}

int Utility::randInt(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(RNG);
}

int Utility::rollD(int numSides)
{
    return randInt(1, numSides);
}
