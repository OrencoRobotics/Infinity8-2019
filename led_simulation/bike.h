/**
 * @file bike.h
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

#ifndef LITEGUIDER_BIKE_H
#define LITEGUIDER_BIKE_H

#include <FastLED.h>


namespace liteguider
{
    /**
     * @class bike
     *
     * @brief LED representation of a bicycle.
     */
    class bike
    {
    public:

        bike();

        /**
         * @brief Set location of bike on LED strip.
         *
         * @param[in] led Location of bike on LED strip.
         */
        void location(CRGB * led);

    private:

        CRGB old_color_;
        CRGB * old_location_;

    };
}


#endif  // LITEGUIDER_BIKE_H

/*
  Local Variables:
  mode: c++
  c-basic-offset: 4
  indent-tabs-mode: nil
  End:
*/
