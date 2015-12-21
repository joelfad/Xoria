/*
Project: Xoria
File: Properties
Author: Joel McFadden
Created: July 27, 2015
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

#include "properties.hpp"

bool Properties::get(TileFlag flag) const
{
    return flagField_ & static_cast<uint_fast32_t>(flag);
}

uint_fast32_t Properties::get() const
{
    return flagField_;
}

bool Properties::allOn(uint_fast32_t flags) const
{
    return !(flags ^ (flagField_ & flags));
}

bool Properties::allOff(uint_fast32_t flags) const
{
    return !(flagField_ & flags);
}

bool Properties::anyOn(uint_fast32_t flags) const
{
    return flagField_ & flags;
}

bool Properties::anyOff(uint_fast32_t flags) const
{
    return flags ^ (flagField_ & flags);
}

void Properties::set(uint_fast32_t flagField)
{
    flagField_ = flagField;
}

void Properties::setOn(TileFlag flag)
{
    flagField_ |= static_cast<uint_fast32_t>(flag);
}

void Properties::setOn(uint_fast32_t flags)
{
    flagField_ |= flags;
}

void Properties::setOff(TileFlag flag)
{
    flagField_ &= ~static_cast<uint_fast32_t>(flag);
}

void Properties::setOff(uint_fast32_t flags)
{
    flagField_ &= ~flags;
}

void Properties::toggle(TileFlag flag)
{
    flagField_ ^= (flagField_ & static_cast<uint_fast32_t>(flag));
}

void Properties::toggle(uint_fast32_t flags)
{
    flagField_ = ((flagField_ & flags) ^ flags) | (flagField_ & ~flags);
}

void Properties::zero()
{
    flagField_ = 0;
}

bool Properties::operator==(const Properties& rhs) const
{
    return flagField_ == rhs.flagField_;
}

bool Properties::operator!=(const Properties& rhs) const
{
    return flagField_ != rhs.flagField_;
}

uint_fast32_t operator|(TileFlag lhs, TileFlag rhs)
{
    return static_cast<uint_fast32_t>(lhs) | static_cast<uint_fast32_t>(rhs);
}

uint_fast32_t operator|(uint_fast32_t lhs, TileFlag rhs)
{
    return lhs | static_cast<uint_fast32_t>(rhs);
}

Properties& Properties::null()
{
    null_.zero();
    return null_;
}

Properties Properties::null_{0};
