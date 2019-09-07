/* Copyright 2018 Alex Peters
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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
#pragma once

#include "quantum.h"

// This a shortcut to help you visually see your layout.

/* LAYOUT_all
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0A │0B │0C │0D │0E │ │0F │    ISO Enter
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┤      ┌─────┐
 * │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │1A │1B │1C │1D   │ │1E │      │2C   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┘   ┌──┴┐    │
 * │20    │21 │22 │23 │24 │25 │26 │27 │28 │29 │2A │2B │2C      │         │1D │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┬─┴─┐       └───┴────┘
 * │30  │31 │32 │33 │34 │35 │36 │37 │38 │39 │3A │3B │3C  │3D │3E │
 * ├────┴┬──┴─┬─┴──┬┴───┴───┴─┬─┴───┴───┴┬──┴─┬─┴──┬┴────┼───┼───┼───┐
 * │40   │41  │42  │43        │44        │45  │46  │47   │48 │49 │4A │
 * └─────┴────┴────┴──────────┴──────────┴────┴────┴─────┴───┴───┴───┘
 * 2u Backspace      = k0D
 * ISO #             = k1D
 * 2.25u Right Shift = k3C
 * 6.25u Space       = k44
 */
#define LAYOUT_all( \
    k00,      k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E,   k0F, \
    k10,      k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D,        k1E, \
    k20,      k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B,      k2C, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, \
    k40, k41, k42,           k43, k44,           k45, k46, k47,      k48, k49, k4A \
) { \
    {  k00,  k01,  k02,  k03,  k04,  k05,  k06,  k07,  k08,  k09,  k0A,  k0B,    k0C,    k0D,    k0E,    k0F    }, \
    {  k10,  k11,  k12,  k13,  k14,  k15,  k16,  k17,  k18,  k19,  k1A,  k1B,    k1C,    k1D,    k1E,    KC_NO  }, \
    {  k20,  k21,  k22,  k23,  k24,  k25,  k26,  k27,  k28,  k29,  k2A,  k2B,    k2C,    KC_NO,  KC_NO,  KC_NO  }, \
    {  k30,  k31,  k32,  k33,  k34,  k35,  k36,  k37,  k38,  k39,  k3A,  k3B,    k3C,    k3D,    k3E,    KC_NO  }, \
    {  k40,  k41,  k42,  k43,  k44,  k45,  k46,  k47,  k48,  k49,  k4A,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO  } \
}

#define LAYOUT_66_ansi( \
    k00,      k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D,   k0F, \
    k10,      k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D,   k1E, \
    k20,      k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B,      k2C, \
    k30,      k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C,      k3E, \
    k40, k41, k42,                k44,           k45, k46, k47,      k48, k49, k4A \
) { \
    {  k00,  k01,    k02,  k03,    k04,  k05,  k06,  k07,  k08,  k09,  k0A,  k0B,    k0C,    k0D,    KC_NO,  k0F    }, \
    {  k10,  k11,    k12,  k13,    k14,  k15,  k16,  k17,  k18,  k19,  k1A,  k1B,    k1C,    k1D,    k1E,    KC_NO  }, \
    {  k20,  k21,    k22,  k23,    k24,  k25,  k26,  k27,  k28,  k29,  k2A,  k2B,    k2C,    KC_NO,  KC_NO,  KC_NO  }, \
    {  k30,  KC_NO,  k32,  k33,    k34,  k35,  k36,  k37,  k38,  k39,  k3A,  k3B,    k3C,    KC_NO,  k3E,    KC_NO  }, \
    {  k40,  k41,    k42,  KC_NO,  k44,  k45,  k46,  k47,  k48,  k49,  k4A,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO  } \
}

#define LAYOUT_66_iso( \
    k00,      k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D,   k0F, \
    k10,      k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C,        k1E, \
    k20,      k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k1D, k2C, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C,      k3E, \
    k40, k41, k42,                k44,           k45, k46, k47,      k48, k49, k4A \
) { \
    {  k00,  k01,  k02,  k03,    k04,  k05,  k06,  k07,  k08,  k09,  k0A,  k0B,    k0C,    k0D,    KC_NO,  k0F    }, \
    {  k10,  k11,  k12,  k13,    k14,  k15,  k16,  k17,  k18,  k19,  k1A,  k1B,    k1C,    k1D,    k1E,    KC_NO  }, \
    {  k20,  k21,  k22,  k23,    k24,  k25,  k26,  k27,  k28,  k29,  k2A,  k2B,    k2C,    KC_NO,  KC_NO,  KC_NO  }, \
    {  k30,  k31,  k32,  k33,    k34,  k35,  k36,  k37,  k38,  k39,  k3A,  k3B,    k3C,    KC_NO,  k3E,    KC_NO  }, \
    {  k40,  k41,  k42,  KC_NO,  k44,  k45,  k46,  k47,  k48,  k49,  k4A,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO  } \
}
