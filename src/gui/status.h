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

#ifdef WIN32
#pragma warning(disable:4312)
#endif

#ifndef _STATS_H
#define _STATS_H

#include "../main.h"
#include "gui.h"
#include "window.h"
#include "progressbar.h"
#include <allegro.h>

/**
 * The player status dialog.
 *
 * \ingroup GUI
 */
class StatusWindow : public Window {
    public:
        StatusWindow(gcn::Container *parent);
        ~StatusWindow();

        /**
         * Updates this dialog with values from PLAYER_INFO *char_info
         */
        void update();

    private:
        gcn::Label *hp, *sp, *gp;
        ProgressBar *healthBar, *manaBar;
};

#endif
