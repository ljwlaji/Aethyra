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

#ifndef SKILL_H
#define SKILL_H

#include <vector>

#include <guichan/selectionlistener.hpp>

#include "../../bindings/guichan/widgets/window.h"

struct SKILL {
    short id, lv, sp;
};

class Table;
class ScrollArea;
class SkillTableModel;

/**
 * The skill dialog.
 *
 * \ingroup Interface
 */
class SkillDialog : public Window, public gcn::SelectionListener
{
    public:
        /**
         * Constructor.
         */
        SkillDialog();

        /**
         * Destructor.
         */
        ~SkillDialog();

        void action(const gcn::ActionEvent &event);

        void valueChanged(const gcn::SelectionEvent &event);

        void widgetShown(const gcn::Event& event);

        void update();

        int getNumberOfElements();

        bool hasSkill(int id);
        void addSkill(int id, int lv, int sp);
        void setSkill(int id, int lv, int sp);
        void cleanList();

        const std::vector<SKILL*>& getSkills(void) const { return mSkillList; }

        /**
         * Focuses on the table on gaining focus.
         */
        void requestFocus();

        void fontChanged();
    private:
        Table *mTable;
        ScrollArea *mSkillScrollArea;
        SkillTableModel *mTableModel;
        gcn::Label *mPointsLabel;
        gcn::Button *mIncButton;
        gcn::Button *mUseButton;

        std::vector<SKILL*> mSkillList;
};

extern SkillDialog *skillDialog;

#endif
