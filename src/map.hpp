/*
Project: Xoria
File: map.hpp
Author: Joel McFadden
Created: June 19, 2015
Last Modified: July 28, 2015

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

#ifndef MAP_H
#define MAP_H

#include <vector>
#include <list>
#include <memory>
#include "properties.hpp"
#include "utility.hpp"
#include "player.hpp"
#include "monster.hpp"

/// Setting of the game.
/// Environment where creatures, tiles, and items interact.
class Map {
public:
    Map(int width = Settings::consoleWidth, int height = Settings::consoleHeight);

    void render(TCODConsole* activeConsole) const;
    /* draw map objects on active console */

    Properties& getProps(int x, int y);
    /* access a tile's properties */

    Properties& getProps(const Coord& c);
    /* access a tile's properties */

    using EntityList = std::list<std::unique_ptr<Entity>>;

    Entity& getPlayer();

    EntityList::iterator beginMonsters();

    EntityList::iterator endMonsters();

private:
    int width_;
    int height_;
    std::vector<const Tile*> tiles_;
    std::vector<Properties>  tileProps_;
    EntityList entities_;                       // list of entities on the map

    void setTile(int x, int y, const Tile& tile, bool clearProps = true);
    /* sets tile using default properties unless clearProp is false */

    void addPlayer(const Coord& location);

    void addMonster(const Coord& location, const Monster& monsterType);
};

#endif // MAP_H
