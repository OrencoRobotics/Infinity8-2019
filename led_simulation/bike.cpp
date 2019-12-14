/**
 * @file bike.cpp
 *
 * LED representation of a bicycle.
 *
 * Copyright (C) 2019  Ossama Othman
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "bike.h"


namespace liteguider
{
    bike::bike()
        : old_color_{}
        , old_location_{}
    {
    }

    void bike::location(CRGB * led)
    {
        if (this->old_location_)
            *this->old_location_ = this->old_color_;

        this->old_color_    = *led;
        this->old_location_ = led;

        *led = CRGB::Blue;
    }
}


/*
  Local Variables:
  mode: c++
  c-basic-offset: 4
  indent-tabs-mode: nil
  End:
*/
