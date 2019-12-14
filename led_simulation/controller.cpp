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

namespace liteguider
{
    template <typename T, size_t N>
    constexpr size_t size(T const (&array)[N]) noexcept
    {
        return N;
    }

    controller::controller()
        : leds_{}
        , pods_{}
        , bike_{}
    {
        // This assumes we are using an WS2812B (NEOPIXEL) LED strip.
        FastLED.addLeds<WS2812B,
                        liteguider::DATA_PIN,
                        GRB>(this->leds_, liteguider::size(this->leds_));

        FastLED.setBrightness(liteguider::BRIGHTNESS);

        // Lay out the pods.
        auto begin = this->leds_;
        auto end   = begin + POD_WIDTH;
        bool has_sensor = true;

        for (auto & pod : this->pods_) {
            if (!pod.layout(begin, end, has_sensor))
                return;

            begin = end   + POD_SPACING;
            end   = begin + POD_WIDTH;
            has_sensor = !has_sensor;  // Alternate sensor pods.
        }

        // FastLED.show();
    }

    controller::~controller()
    {
        // Reset LED strip color to black.
        for (auto & led : this->leds_)
            led = CRGB::Black;
    }

    void controller::ride_bike()
    {
        auto const begin = this->leds_;
        auto const end   = begin + liteguider::size(this->leds_);

        for (auto led = begin; led != end; ++led) {
            this->bike_.location(led);

            pod * const p = led_to_pod(led);

            if (p) {
                if (p->sensor_tripped(led)) {
                    // Activate pods ahead of bike.
                    constexpr int pod_ahead       = 2;
                    constexpr int pod_activations = 2;

                    pod * const pbegin = p + pod_ahead;
                    pod * const pend   =
                        min(pbegin + pod_activations,
                            this->pods_
                            + liteguider::size(this->pods_));

                    for (pod * a = pbegin; a < pend; ++a)
                        a->activate();
                }

                // Deactivate pod behind bike.
                constexpr int pod_behind = 1;
                pod * const b = p - 1;
                if (b > this->pods_)
                    b->deactivate();
            }

            FastLED.show();
            delay(700);
        }
    }

    pod * controller::led_to_pod(CRGB * led) const
    {
        pod * p = nullptr;

        if (led < this->leds_)
            return p;

        ptrdiff_t led_num = led - this->leds_;
        ptrdiff_t offset  = led_num / (POD_WIDTH + POD_SPACING);

        if (led_num < ((offset + 1) * (POD_WIDTH + POD_SPACING)
                       - POD_SPACING))
            p = this->pods_ + offset;

        return p;
    }
}



/*
  Local Variables:
  mode: c++
  c-basic-offset: 4
  indent-tabs-mode: nil
  End:
*/
