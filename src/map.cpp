/*
Project: Xoria
File: map.cpp
Author: Joel McFadden
Created: June 19, 2015
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

#include "map.hpp"

Map::Map(int width, int height)
    : width_{width}, height_{height}, tiles_(width * height, nullptr), tileProps_(width * height, 0)
{
    // create a default map filled with grass and one wall
    for (int x = 0; x < width_; x++)
        for (int y = 0; y < height_; y++)
            setTile(x, y, TileSet::dirtGround);

    // TEMP: test tiles

    setTile(34, 0, TileSet::rockWall);
    setTile(34, 2, TileSet::metalWall);
    setTile(34, 4, TileSet::shrub);
    setTile(34, 6, TileSet::minerals);
    setTile(34, 8, TileSet::iceWall);

    setTile(36, 0, TileSet::dirtWall);  
    setTile(36, 2, TileSet::doorClosed);
    setTile(36, 4, TileSet::lava);
    setTile(36, 6, TileSet::waterDeep);
    setTile(36, 8, TileSet::waterShallow);

    setTile(38, 0, TileSet::doorOpen);
    setTile(38, 2, TileSet::tree);
    setTile(38, 4, TileSet::rockGround);
    setTile(38, 6, TileSet::grass);
    setTile(38, 8, TileSet::iceGround);

    setTile(40, 0, TileSet::mud);
    setTile(40, 2, TileSet::rubble);
    setTile(40, 4, TileSet::chasm);
    setTile(40, 6, TileSet::airlock);
    setTile(40, 8, TileSet::portal);

    setTile(42, 0, TileSet::descend);
    setTile(42, 2, TileSet::ascend);
    setTile(42, 4, TileSet::elevator);
    setTile(42, 6, TileSet::fieldUpOn);
    setTile(42, 8, TileSet::fieldRightOn);

    setTile(44, 0, TileSet::fieldDownOn);
    setTile(44, 2, TileSet::fieldLeftOn);
    setTile(44, 4, TileSet::fieldUpOff);
    setTile(44, 6, TileSet::fieldDownOff);
    setTile(44, 8, TileSet::fieldLeftOff);

    setTile(46, 0, TileSet::fieldRightOff);
    setTile(46, 2, TileSet::switchOff);
    setTile(46, 4, TileSet::switchOn);

    // TODO: set method to add entity to map and set tile flag hasEntity

    entities_.push_front(std::make_unique<Player>(Coord(5, 3)));
    entities_.push_back(std::make_unique<Monster>(Coord(20, 10), MonsterSet::spaceSlug));
    entities_.push_back(std::make_unique<Monster>(Coord(16, 14), MonsterSet::spaceSlug));
}

void Map::render(TCODConsole* activeConsole) const
{
    // render tiles
    for (int i = 0; i < width_ * height_; i++)
        tiles_.at(i)->render(activeConsole, i % width_, i / width_);

    // render entities
    for (auto& e : entities_)
        e->render(activeConsole);
}

Properties& Map::getProps(int x, int y)
{
    if (x < 0 || x >= width_ || y < 0 || y >= height_)
        return Properties::null();
    else
        return tileProps_.at(x + y * width_);
}

Properties& Map::getProps(const Coord &c)
{
    if (c.x < 0 || c.x >= width_ || c.y < 0 || c.y >= height_)
        return Properties::null();
    else
        return tileProps_.at(c.x + c.y * width_);
}

Entity& Map::getPlayer()
{
    return *entities_.front();
}

Map::EntityList::iterator Map::beginMonsters()
{
    return ++entities_.begin();
}

Map::EntityList::iterator Map::endMonsters()
{
    return entities_.end();
}

void Map::setTile(int x, int y, const Tile& tile, bool clearProps)
{
    tiles_.at(x + y * width_) = &tile;

    if (clearProps)
        tileProps_.at(x + y * width_) = tile.getDefaultProps();
}

void Map::addPlayer(const Coord& location)
{
    entities_.push_front(std::make_unique<Player>(location));
    getProps(location).setOn(TileFlag::hasEntity);
}

void Map::addMonster(const Coord& location, const Monster& monsterType)
{
    entities_.push_front(std::make_unique<Monster>(location, monsterType));
    getProps(location).setOn(TileFlag::hasEntity);
}
