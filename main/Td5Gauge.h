/*
 * This file is part of the Td5Gauge Firmware (https://github.com/k0sci3j/Td5Gauge).
 * Copyright (c) 2022 Michal Kosciowski BinOwl.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * 	Td5Gauge.h
 *  Created on: 20.01.2022
 *  Author: BinOwl
 *
 */

#ifndef TD5GAUGE_H_
#define TD5GAUGE_H_

#include "Arduino.h"
#include "KLine.h"
#include "RunMillis.h"
#include "LCDBigFont.h"
#include "Effortless_SPIFFS.h"

#define LCD_BKL 33
#define PWM1_CH    0
#define PWM1_RES   8
#define PWM1_F  1000

#define BUTTON_PLUS 19
#define BUTTON_MINUS 22

#define LCD_RS 13
#define LCD_E 12
#define LCD_D4 14
#define LCD_D5 27
#define LCD_D6 26
#define LCD_D7 25

#define FILE_MENU_POS "/0.cfg"
#define FILE_SPEED_MULTIPLIER "/1.cfg"
#define FILE_LCD_BACKLIGHT "/2.cfg"
#define FILE_AUTO_OFF "/3.cfg"
#define FILE_RESET "/4.cfg"
#define FILE_TEMP_AL_SET "/5.cfg"

enum MenuFunction {
  FUNC_FUEL_CONSUMPTION_LH = 0,
  FUNC_FUEL_CONSUMPTION_L100KM = 1,
  FUNC_FUEL_DEMAND = 2,
  FUNC_IDLE_FUEL = 3,
  FUNC_INJECTED_FUEL = 4,
  FUNC_SPEED = 5,
  FUNC_FUEL_TEMP = 6,
  FUNC_AIR_TEMP = 7,
  FUNC_COOLANT_TEMP = 8,
  FUNC_RPM = 9,
  FUNC_VOLTAGE = 10,
  FUNC_MAF_SENSOR = 11,
  FUNC_AAP_SENSOR = 12,
  FUNC_PRESS1_SENSOR = 13,
  FUNC_PRESS2_SENSOR = 14,
  FUNC_PRESS3_SENSOR = 15,
  FUNC_TURBO_CHARGE = 16,
  FUNC_WASTEGATE_MOD = 17,
  FUNC_INJ_BALANCE = 18,
  FUNC_THROTTLE = 19,
  NUM_FUNCS = 20
};

eSPIFFS fileSystem;
KLine *kline;
RunMillis *keepAliveRunner;
RunMillis *takeValueRunner;
RunMillis *currFuelRunner;
RunMillis *tempCheckRunner;
RunMillis *screenBlinkRunner;
LCDBigFont *lcd;

uint curr_func = 0;
uint run_kline = true;

uint speed_multiplier = 0;
uint lcd_backlight = 5;
uint auto_off = 0;
uint reset_state = 0;
uint temp_alarm_set = 1;
uint temp_alarm = 95;


#endif /* TD5GAUGE_H_ */