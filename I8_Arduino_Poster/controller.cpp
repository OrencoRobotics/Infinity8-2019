/**
 * @file controller.cpp
 *
 * Liteguider controller.
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

#include "controller.h"
#include "config.h"

#include <iterator>  // For std::size()


namespace liteguider
{
#if 0
    template <typename T, std::size_t N>
    constexpr std::size_t size(T const (&array)[N]) noexcept
    {
        return N;
    }
#endif  // 0

    controller::controller()
        : leds_{}
        , pods_{}
        , bike_{}
    {
        // This assumes we are using an WS2812B (NEOPIXEL) LED strip.
        FastLED.addLeds<WS2812B,
                        liteguider::DATA_PIN,
                        RGB>(this->leds_, std::size(this->leds_));

        FastLED.setBrightness(liteguider::BRIGHTNESS);

        // Lay out the pods.
        auto & begin = this->leds_;
        auto & end   = begin + POD_WIDTH;
        bool has_sensor = true;

        for (auto & pod : this->pods_) {
            pod.layout(begin, end, has_sensor);

            begin = end   + POD_SPACING;
            end   = begin + POD_WIDTH;
            has_sensor = !has_sensor;  // Alternate sensor pods.
        }
    }

    controller::~controller()
    {
        // Reset LED strip color to black.
        for (auto & led : this->leds_)
            led = CRGB::Black;
    }
}


/*
  Local Variables:
  mode: c++
  c-basic-offset: 4
  indent-tabs-mode: nil
  End:
*/
