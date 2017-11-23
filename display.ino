/***********************************************************************
  Simple Arduino-Sketch to Display any integer upto 256 in Hex-Format
  on the 2-Char 595 Display
  
  Copyright (c) 2017 PLAY-ZONE GmbH http://www.play-zone.ch
  Permission is hereby granted, free of charge, to any person obtaining a
  copy of this software and associate documentation files (the "Software"),
  to deal in the Software without restriction, including without limitation
  the rights to use, copy, modify, merge, publish, distribute, sublicense,
  and/or sell copies of the Software, and to permit persons to whom the
  Software is furnished to do so, subject to the following conditions:
  The above copyright notice and this permission notice shall be included
  in all copies or substantial portions of the Software.
*************************************************************************/

// SDI
#define DATA 8

// SCLK
#define CLK 9

// LOAD
#define RCLK 7

void setup() {
    pinMode(DATA,OUTPUT);
    pinMode(CLK,OUTPUT);
    pinMode(RCLK, OUTPUT);
  
    digitalWrite(RCLK, HIGH);
}

int count = 0;
void loop() 
{
    displayHex(count);
    count++;
    delay(100);
}

int segments [16] = {~0b00111111, ~0b00000110, ~0b01011011, ~0b01001111, ~0b01100110, ~0b01101101, ~0b01111101, ~0b00000111, ~0b01111111, ~0b01100111, ~0b01110111, ~0b01111100, ~0b00111001, ~0b01011110, ~0b01111001, ~0b01110001};

void displayHex(int number) {
    digitalWrite(RCLK, LOW);
    shiftOut(DATA,CLK, MSBFIRST, segments[number%16]);   
    shiftOut(DATA,CLK, MSBFIRST, segments[(number>>4)%16]);
    digitalWrite(RCLK, HIGH);
}
