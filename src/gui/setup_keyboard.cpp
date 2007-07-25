/*
 *  The Mana World
 *  Copyright 2007 The Mana World Development Team
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

#include "setup_keyboard.h"

#include <guichan/widgets/label.hpp>
#include <guichan/listmodel.hpp>

#include "button.h"
#include "listbox.h"
#include "ok_dialog.h"
#include "scrollarea.h"

#include "../configuration.h"
#include "../keyboardconfig.h"

#include "../utils/tostring.h"

#include <SDL_keyboard.h>

/**
 * The list model for key function list.
 *
 * \ingroup Interface
 */
class KeyListModel : public gcn::ListModel
{
    public:
        /**
         * Returns the number of elements in container.
         */
        int getNumberOfElements() { return keyboard.KEY_TOTAL; }

        /**
         * Returns element from container.
         */
        std::string getElementAt(int i) { return mKeyFunctions[i]; }

        /**
         * Sets element from container.
         */
        void setElementAt(int i, std::string caption)
        {
            mKeyFunctions[i] = caption;
        }

    private:
        std::string mKeyFunctions[keyboard.KEY_TOTAL];
};

Setup_Keyboard::Setup_Keyboard():
    mKeyListModel(new KeyListModel()),
    mKeyList(new ListBox(mKeyListModel))
{
    keyboard.setSetupKeyboard(this);
    setOpaque(false);

    refreshKeys();

    mKeyList->setDimension(gcn::Rectangle(0, 0, 180, 140));
    mKeyList->addActionListener(this);
    mKeyList->setSelected(-1);

    ScrollArea *scrollArea = new ScrollArea(mKeyList);
    scrollArea->setDimension(gcn::Rectangle(10, 10, 180, 140));
    add(scrollArea);

    mAssignKeyButton = new Button("Assign", "assign", this);
    mAssignKeyButton->setPosition(145, 155);
    mAssignKeyButton->addActionListener(this);
    mAssignKeyButton->setEnabled(false);
    add(mAssignKeyButton);

    mMakeDefaultButton = new Button("Default", "makeDefault", this);
    mMakeDefaultButton->setPosition(10, 155);
    mMakeDefaultButton->addActionListener(this);
    add(mMakeDefaultButton);
}

Setup_Keyboard::~Setup_Keyboard()
{
    delete mKeyList;
    delete mKeyListModel;

    delete mAssignKeyButton;
    delete mMakeDefaultButton;
}

void Setup_Keyboard::apply()
{
    if (keyboard.hasConflicts())
    {
        new OkDialog("Key Conflict(s) Detected.",
            "Resolve them, or gameplay may result in strange behaviour.");
    }
    keyboard.setEnabled(true);
    keyboard.store();
}

void Setup_Keyboard::cancel()
{
    keyboard.retrieve();
    keyboard.setEnabled(true);
    refreshKeys();
}

void Setup_Keyboard::action(const gcn::ActionEvent &event)
{
    if (event.getSource() == mKeyList)
    {
        mAssignKeyButton->setEnabled(true);
    }
    else if (event.getId() == "assign")
    {
        int i(mKeyList->getSelected());
        mAssignKeyButton->setEnabled(false);
        keyboard.setEnabled(false);
        keyboard.setNewKeyIndex(i);
        mKeyListModel->setElementAt(i, keyboard.getKeyCaption(i) + ": ?");
    }
    else if (event.getId() == "makeDefault")
    {
        keyboard.makeDefault();
        refreshKeys();
    }
}

void Setup_Keyboard::refreshAssignedKey(int index)
{
    std::string caption;
    char *temp = SDL_GetKeyName(
        (SDLKey) keyboard.getKeyValue(index));
    caption = keyboard.getKeyCaption(index) + ": " + toString(temp);
    mKeyListModel->setElementAt(index, caption);
}

void Setup_Keyboard::newKeyCallback(int index)
{
    refreshAssignedKey(index);
    mAssignKeyButton->setEnabled(true);
}

void Setup_Keyboard::refreshKeys()
{
    for(int i = 0; i < keyboard.KEY_TOTAL; i++)
    {
        refreshAssignedKey(i);
    }
}
