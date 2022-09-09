/** --------------------------------------------------------------------------
 * File: main.cpp
 * Created Date: 07-25-2022
 * Author: Thomas Ose
 * ---------------------------------------------------------------------------
 * Last Modified: Wednesday, 27th July 2022 11:31:05 am
 * Modified By: Thomas Ose (tmo@osemicro.com>)
 * ---------------------------------------------------------------------------
 * Copyright (c) 2016 - 2022 OMS(re)Models
 *
 *  This source file is subject of the GNU general public license 2,
 *  that is available at the world-wide-web at
 *  http://www.gnu.org/licenses/gpl.txt
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  copy of this software and associated documentation files.  The above
 *  copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 * ---------------------------------------------------------------------------
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	----------------------------------------------------------
 * 07-27-2022	tmo	Resolved led level for quarter brightness
 * 07-27-2022	tmo	Removed unused code
 * 07-27-2022	tmo	Rewrote control logic
 * --------------------------------------------------------------------------- */
#include "Arduino.h"

const int LED_1 = D0;
const int LED_2 = D1;
const int LED_3 = D2;
const int LED_4 = D3;

const int LEDM1 = D5;
const int LEDM2 = D6;
const int LEDM3 = D7;
const int LEDM4 = D10;
const int LEDC1 = D9;

const int L_OFF = 1023;
const int L_QUARTER = 768;
const int L_MID = 512;
const int L_3_QUARTER = 256;
const int L_HIGH = 0;

const int delayTime = 60;

void setup()
{
    analogWriteRange(1024);
    //analogWriteFreq(10khz);
    // set the PIN mode for all LED
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
    pinMode(LED_4, OUTPUT);
    pinMode(LEDC1, OUTPUT);
    pinMode(LEDM1, OUTPUT);
    pinMode(LEDM2, OUTPUT);
    pinMode(LEDM3, OUTPUT);
    pinMode(LEDM4, OUTPUT);
    //   Serial.begin(9600);
    //   Serial.println("ChrisLEDBar  version 3.5");
    // Make sue all LEDs are off before starting
    analogWrite(LED_1, L_OFF);
    analogWrite(LED_2, L_OFF);
    analogWrite(LED_3, L_OFF);
    analogWrite(LED_4, L_OFF);
    analogWrite(LEDC1, L_OFF);
    analogWrite(LEDM1, L_OFF);
    analogWrite(LEDM2, L_OFF);
    analogWrite(LEDM3, L_OFF);
    analogWrite(LEDM4, L_OFF);
}

void loop()
{
    // time slot 0
    analogWrite(LED_1, L_OFF);
    analogWrite(LED_2, L_OFF);
    analogWrite(LED_4, L_HIGH);
    analogWrite(LED_3, L_OFF);
    analogWrite(LEDC1, L_OFF);
    analogWrite(LEDM3, L_HIGH);
    delay(delayTime);

    // time slot 60
    analogWrite(LED_1, L_QUARTER);
    analogWrite(LED_4, L_3_QUARTER);
    analogWrite(LEDM3, L_3_QUARTER);
    analogWrite(LEDC1, L_QUARTER);
    delay(delayTime);

    // time slot 120
    analogWrite(LED_1, L_MID);
    analogWrite(LED_4, L_MID);
    analogWrite(LEDM3, L_OFF);
    analogWrite(LEDC1, L_MID);
    delay(delayTime);

    // time slot 180
    analogWrite(LED_1, L_3_QUARTER);
    analogWrite(LED_4, L_QUARTER);
    analogWrite(LEDC1, L_3_QUARTER);
    delay(delayTime);

    // time slot 240
    analogWrite(LED_1, L_HIGH);
    analogWrite(LED_2, L_OFF);
    analogWrite(LED_4, L_OFF);
    analogWrite(LEDC1, L_HIGH);
    delay(delayTime);

    // time slot 300
    analogWrite(LED_1, L_3_QUARTER);
    analogWrite(LED_2, L_QUARTER);
    analogWrite(LEDC1, L_3_QUARTER);
    delay(delayTime);

    // time slot 360
    analogWrite(LED_1, L_MID);
    analogWrite(LED_2, L_MID);
    analogWrite(LEDC1, L_MID);
    delay(delayTime);

    // time slot 420
    analogWrite(LED_1, L_QUARTER);
    analogWrite(LED_2, L_3_QUARTER);
    analogWrite(LEDM1, L_3_QUARTER);
    analogWrite(LEDM4, L_3_QUARTER);
    analogWrite(LEDC1, L_QUARTER);
    delay(delayTime);

    // time slot 480
    analogWrite(LED_1, L_OFF);
    analogWrite(LED_2, L_HIGH);
    analogWrite(LED_3, L_OFF);
    analogWrite(LEDC1, L_OFF);
    analogWrite(LEDM1, L_HIGH);
    analogWrite(LEDM4, L_HIGH);
    delay(delayTime);

    // time slot 540
    analogWrite(LED_2, L_3_QUARTER);
    analogWrite(LED_3, L_QUARTER);
    analogWrite(LEDM1, L_3_QUARTER);
    analogWrite(LEDM4, L_3_QUARTER);
    delay(delayTime);

    // time slot 600
    analogWrite(LED_2, L_MID);
    analogWrite(LED_3, L_MID);
    analogWrite(LEDM1, L_OFF);
    analogWrite(LEDM4, L_OFF);
    delay(delayTime);

    // time slot 660
    analogWrite(LED_2, L_QUARTER);
    analogWrite(LED_3, L_3_QUARTER);
    analogWrite(LEDM2, L_3_QUARTER);
    delay(delayTime);

    // time slot 720
    analogWrite(LED_2, L_OFF);
    analogWrite(LED_3, L_HIGH);
    analogWrite(LED_4, L_OFF);
    analogWrite(LEDM2, L_HIGH);
    delay(delayTime);

    // time slot 780
    analogWrite(LED_3, L_3_QUARTER);
    analogWrite(LED_4, L_QUARTER);
    analogWrite(LEDM2, L_3_QUARTER);
    delay(delayTime);

    // time slot 840
    analogWrite(LED_3, L_MID);
    analogWrite(LED_4, L_MID);
    analogWrite(LEDM2, L_OFF);
    delay(delayTime);

    // time slot 900
    analogWrite(LED_3, L_QUARTER);
    analogWrite(LED_4, L_3_QUARTER);
    analogWrite(LEDM3, L_3_QUARTER);
    delay(delayTime);
}