/*
Project: Xoria
File: properties.h
Author: Joel McFadden
Created: July 27, 2015
Last Modified: July 29, 2015

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

#ifndef PROPERTIES_H
#define PROPERTIES_H

#include "constants.h"

/// Tile Properties
/// Set of flags describing the state of a map tile.
class Properties {
public:
    Properties(uint_fast32_t flagField) : flagField_{flagField}
    { }

    // get
    bool get(TileFlag flag)          const;

    uint_fast32_t get()              const;

    bool allOn(uint_fast32_t flags)  const;

    bool allOff(uint_fast32_t flags) const;

    bool anyOn(uint_fast32_t flags)  const;

    bool anyOff(uint_fast32_t flags) const;

    // set
    void set(uint_fast32_t flagField);

    void setOn(TileFlag flag);

    void setOn(uint_fast32_t flags);

    void setOff(TileFlag flag);

    void setOff(uint_fast32_t flags);

    void toggle(TileFlag flag);

    void toggle(uint_fast32_t flags);

    void zero();

    // compare
    bool operator==(const Properties& rhs) const;

    bool operator!=(const Properties& rhs) const;

    static Properties& null();

private:
    uint_fast32_t flagField_;
    static Properties null_;    // out of bounds
};

uint_fast32_t operator|(TileFlag lhs, TileFlag rhs);

uint_fast32_t operator|(uint_fast32_t lhs, TileFlag rhs);

#endif // PROPERTIES_H
