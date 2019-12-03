/**
 * @file config.h
 *
 * Liteguider Arduino based simulation configuration header.
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

#ifndef LITEGUIDER_CONFIG_H
#define LITEGUIDER_CONFIG_H

#include <stdint.h>


namespace liteguider
{
    /// Number of LEDs in the LED strip.
    constexpr int NUM_LEDS = 81;

    /// Arduino pin to which the LED strip data line is connected.
    constexpr uint8_t DATA_PIN = 7;

    /// Global brightness scale.
    constexpr uint8_t BRIGHTNESS = 84;

    /// Number of LEDs in a Liteguider pod.
    constexpr int POD_WIDTH = 3;

    /// Number of LEDs between Liteguider pods.
    constexpr int POD_SPACING = 5;
}


#endif  // LITEGUIDER_CONFIG_H

/*
  Local Variables:
  mode: c++
  c-basic-offset: 4
  indent-tabs-mode: nil
  End:
*/
