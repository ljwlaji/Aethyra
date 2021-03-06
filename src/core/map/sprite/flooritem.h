/*
 *  Aethyra
 *  Copyright (C) 2004  The Mana World Development Team
 *
 *  This file is part of Aethyra based on original code
 *  from The Mana World.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef FLOORITEM_H
#define FLOORITEM_H

#include <list>

#include "sprite.h"

#include "../map.h"

class Graphics;
class Image;
class Item;

typedef std::list<Sprite*> Sprites;

/**
 * An item lying on the floor.
 */
class FloorItem : public Sprite
{
    public:
        /**
         * Constructor.
         */
        FloorItem(const int id, const int itemId, const int x, const int y,
                  Map *map);

        /**
         * Destructor.
         */
        ~FloorItem();

        /**
         * Returns instance id of this item.
         */
        const int getId() const { return mId; }

        /**
         * Returns the item id.
         */
        const int getItemId() const;

        /**
         * Returns the item object. Useful for adding an item link for the floor
         * item to chat.
         */
        Item* getItem() const;

        /**
         * Returns the x coordinate.
         */
        const int getX() const { return mX; }

        /**
         * Returns the y coordinate.
         */
        const int getY() const { return mY; }

        /**
         * Returns the pixel y coordinate.
         *
         * @see Sprite::getPixelY()
         */
        const int getPixelY() const { return mY * mMap->getTileHeight(); }

        /**
         * Draws this floor item to the given graphics context.
         *
         * @see Sprite::draw(Graphics, int, int)
         */
        void draw(Graphics *graphics, const int offsetX,
                  const int offsetY) const;

    private:
        int mId;
        int mX, mY;
        Item *mItem;
        Sprites::iterator mSpriteIterator;
        Map *mMap;
};

#endif
