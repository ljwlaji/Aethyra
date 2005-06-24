/*
 *  The Mana World
 *  Copyright 2004 The Mana World Development Team
 *
 *  This file is part of The Mana World.
 *
 *  The Mana World is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  The Mana World is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with The Mana World; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 */

#include "resource.h"
#include "resourcemanager.h"

#include <cassert>

Resource::Resource():
    mRefCount(0)
{
}

Resource::~Resource()
{
}

void
Resource::setIdPath(const std::string &idPath)
{
    mIdPath = idPath;
}

void
Resource::incRef()
{
    mRefCount++;
}

bool
Resource::decRef()
{
    // Reference may not already have reached zero
    assert(mRefCount != 0);

    mRefCount--;

    if (mRefCount == 0) {
        // Make sure resource manager won't refer to deleted resource
        ResourceManager *resman = ResourceManager::getInstance();
        resman->release(mIdPath);
        delete this;
        return true;
    }
    else {
        return false;
    }
}
