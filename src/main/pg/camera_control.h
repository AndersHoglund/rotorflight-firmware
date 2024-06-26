/*
 * This file is part of Rotorflight.
 *
 * Rotorflight is free software. You can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Rotorflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include "types.h"
#include "platform.h"

#include "drivers/io.h"

#include "pg/pg.h"

typedef enum {
    CAMERA_CONTROL_KEY_ENTER,
    CAMERA_CONTROL_KEY_LEFT,
    CAMERA_CONTROL_KEY_UP,
    CAMERA_CONTROL_KEY_RIGHT,
    CAMERA_CONTROL_KEY_DOWN,
    CAMERA_CONTROL_KEYS_COUNT
} cameraControlKey_e;

typedef enum {
    CAMERA_CONTROL_MODE_HARDWARE_PWM,
    CAMERA_CONTROL_MODE_SOFTWARE_PWM,
    CAMERA_CONTROL_MODE_DAC,
    CAMERA_CONTROL_MODES_COUNT
} cameraControlMode_e;

typedef struct {
    uint8_t     mode;

    // measured in 10 mV steps
    uint16_t    refVoltage;
    uint16_t    keyDelayMs;

    // measured 100 Ohm steps
    uint16_t    internalResistance;

    ioTag_t     ioTag;
    uint8_t     inverted;

    uint16_t    buttonResistanceValues[CAMERA_CONTROL_KEYS_COUNT]; // resistance in 100ohm steps
} cameraControlConfig_t;

PG_DECLARE(cameraControlConfig_t, cameraControlConfig);
