/**
 * @file pod.cpp
 *
 * LED representation of a Liteguider pod.
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

#include "pod.h"

#include <FastLED.h>


namespace
{
    template <typename T>
    T mid_point(T begin, T end)
    {
        return begin + (end - begin) / 2;
    }
}

namespace liteguider
{
    pod::pod()
        : begin_{}
        , end_{}
        , has_sensor_{}
    {
    }

    pod::~pod()
    {
    }

    bool pod::layout(CRGB * begin, CRGB * end, bool has_sensor)
    {
        if (begin >= end) {
            Serial.println("Incorrect pod layout.");
            return false;
        }

        this->begin_ = begin;
        this->end_   = end;
        this->has_sensor_ = has_sensor;

        auto const center = mid_point(begin, end);

        // Activate the sensor LED.
        if (has_sensor)
                *center = CRGB::Red;

        return true;
    }

    bool pod::sensor_tripped(CRGB * led) const
    {
        return led == mid_point(this->begin_, this->end_);
    }

    void pod::activate()
    {
        auto const center = mid_point(this->begin_, this->end_);

        for (auto led = this->begin_; led != this->end_; ++led) {
            // Activate all non-sensor LEDs.
            if (!this->has_sensor_ || led != center)
                *led = CRGB::Yellow;
        }
    }

    void pod::deactivate()
    {
        auto const center = mid_point(this->begin_, this->end_);

        for (auto led = this->begin_; led != this->end_; ++led) {
            // Deactivate all non-sensor LEDs.
            if (!this->has_sensor_ || led != center) {
                // led->nscale8(250);
                *led = CRGB::Black;
            }
        }
    }
}


/*
  Local Variables:
  mode: c++
  c-basic-offset: 4
  indent-tabs-mode: nil
  End:
*/
