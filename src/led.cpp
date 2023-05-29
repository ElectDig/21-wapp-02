/*
 *  led.cpp
 */

#include <Arduino.h>

#include "led.h"


void
init_led(void)
{
    pinMode(LED,OUTPUT);
    digitalWrite(LED,LOW);
}

void
set_led(void)
{
    digitalWrite(LED,HIGH);
}

void
clear_led(void)
{
    digitalWrite(LED,LOW);
}

int
led_on(void)
{
    return digitalRead(LED);
}


