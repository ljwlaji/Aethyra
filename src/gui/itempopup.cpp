/*
 *  The Mana World
 *  Copyright (C) 2008  The Legend of Mazzeroth Development Team
 *  Copyright (C) 2008  The Mana World Development Team
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
 */

#include "itempopup.h"
#include <guichan/widgets/label.hpp>
#include "widgets/layout.h"

#include "gui.h"

#include "../resources/image.h"
#include "../resources/resourcemanager.h"
#include "../resources/iteminfo.h"
#include "../utils/gettext.h"
#include "../utils/strprintf.h"


ItemPopup::ItemPopup()
{
    setResizable(false);
    setCaption("");
    setTitleBarHeight(0);
    loadSkin("graphics/gui/gui.xml");

    // Item Name
    mItemName = new gcn::Label("Label");
    mItemName->setFont(gui->getFont());
    mItemName->setPosition(2, 2);
    mItemName->setWidth(getWidth() - 4);

    // Item Description
    mItemDesc = new TextBox();
    mItemDesc->setEditable(false);
    mItemDesc->setMinWidth(170);
    mItemDescScroll = new ScrollArea(mItemDesc);

    mItemDescScroll->setHorizontalScrollPolicy(gcn::ScrollArea::SHOW_NEVER);
    mItemDescScroll->setVerticalScrollPolicy(gcn::ScrollArea::SHOW_NEVER);
    mItemDescScroll->setDimension(gcn::Rectangle(0, 0, 196, 14));
    mItemDescScroll->setOpaque(false);
    mItemDescScroll->setPosition(2, 15);

    // Item Effect
    mItemEffect = new TextBox();
    mItemEffect->setEditable(false);
    mItemEffect->setMinWidth(170);
    mItemEffectScroll = new ScrollArea(mItemEffect);

    mItemEffectScroll->setHorizontalScrollPolicy(gcn::ScrollArea::SHOW_NEVER);
    mItemEffectScroll->setVerticalScrollPolicy(gcn::ScrollArea::SHOW_NEVER);
    mItemEffectScroll->setDimension(gcn::Rectangle(0, 0, 196, 14));
    mItemEffectScroll->setOpaque(false);
    mItemEffectScroll->setPosition(2, 35);

    add(mItemName);
    add(mItemDescScroll);
    add(mItemEffectScroll);

    setLocationRelativeTo(getParent());

    // LEEOR / TODO: This causes an exception error.
    //moveToBottom(getParent());

    mItemDesc->setTextWrapped( "" );
    mItemEffect->setTextWrapped( "" );
}

void ItemPopup::setItem(const ItemInfo &item)
{
    const gcn::Rectangle &area = getChildrenArea();
    const int width = area.width;

    mItemDesc->setMinWidth(width - 30);
    mItemEffect->setMinWidth(width - 30);

    mItemName->setCaption(item.getName());
    mItemDesc->setTextWrapped(item.getDescription());
    mItemEffect->setTextWrapped(item.getEffect());

    int numRowsDesc = mItemDesc->getNumberOfRows();
    int numRowsEffect = mItemEffect->getNumberOfRows();

    if(item.getEffect() == "")
    {
        setContentSize(200, (numRowsDesc * 14) + 30);
    } else {
        setContentSize(200, (numRowsDesc * 14) + (numRowsEffect * 14) + 30);
    }

    mItemDescScroll->setDimension(gcn::Rectangle(2, 0, 196, numRowsDesc * 14));

    mItemEffectScroll->setDimension(gcn::Rectangle(2, 0, 196, numRowsEffect * 14));

    mItemDescScroll->setPosition(2, 20);
    mItemEffectScroll->setPosition(2, (numRowsDesc * 15) + 25);
}

unsigned int ItemPopup::getNumRows()
{
    return mItemDesc->getNumberOfRows(), mItemEffect->getNumberOfRows();
}
