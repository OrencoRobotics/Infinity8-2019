/**
 * @file controller.cpp
 *
 * Lightguider controller.
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

#ifndef LITEGUIDER_CONTROLLER_H
#define LITEGUIDER_CONTROLLER_H

#include "config.h"

#include <FastLED.h>


namespace liteguider
{
    /**
     * @class controller
     *
     * @brief Controller that determines when light LEDs.
     */
    class controller
    {
    public:

        /// Constructor.
        controller();

        ~controller();

    private:

        CRGB leds_[NUM_LEDS];

        /// Maximum number of pods on a given LED strip.
        constexpt int NUM_PODS =
            (NUM_LEDS + POD_SPACING) / (POD_WIDTH + POD_SPACING);

        pod pods_[NUM_PODS];

        bike bike_;
    };
}


#endif  // LITEGUIDER_CONTROLLER_H
/*
  Local Variables:
  mode: c++
  c-basic-offset: 4
  indent-tabs-mode: nil
  End:
*/
