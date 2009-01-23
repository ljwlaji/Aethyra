/*
 *  The Mana World
 *  Copyright (C) 2004  The Mana World Development Team
 *
 *  This file is part of The Mana World.
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

#ifndef _TMW_BUTTON_H
#define _TMW_BUTTON_H

#include <iosfwd>

#include <guichan/widgets/button.hpp>

#include "../guichanfwd.h"

class ImageRect;

/**
 * Button widget. Same as the Guichan button but with custom look.
 *
 * \ingroup GUI
 */
class Button : public gcn::Button {
    public:
        /**
         * Default constructor.
         */
        Button();

        /**
         * Constructor, sets the caption of the button to the given string and
         * adds the given action listener.
         */
        Button(const std::string& caption, const std::string &actionEventId,
                gcn::ActionListener *listener);

        /**
         * Destructor.
         */
        ~Button();

        /**
         * Draws the button.
         */
        void draw(gcn::Graphics* graphics);

        /**
         * Enable/Disable highlighting
         */
        void setLogged(bool enable)
        { mIsLogged = enable; }

    private:
        void init();

        static ImageRect button[4];    /**< Button state graphics */
        static int mInstances;         /**< Number of button instances */
        bool mIsLogged;                /**< Makes the button appear pressed all the time */
};

#endif
