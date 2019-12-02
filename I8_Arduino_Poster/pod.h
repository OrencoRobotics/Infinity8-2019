/**
 * @file pod.h
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

#ifndef LITEGUIDER_POD_H
#define LITEGUIDER_POD_H


struct CRGB;

namespace liteguider
{
    /**
     * @class pod
     *
     * @brief LED representation of a Liteguider pod.
     */
    class pod
    {
    public:

        /// Constructor.
        pod();

        /// Destructor.
        ~pod();

        /// Set pod layout.
        void layout(CRGB * begin, CRBG * end, bool has_sensor);

    private:

        int sensor_led_;

    };
}


#endif // LITEGUIDER_POD_H

/*
  Local Variables:
  mode: c++
  c-basic-offset: 4
  indent-tabs-mode: nil
  End:
*/
