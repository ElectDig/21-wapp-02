/*
 *  takt.cpp
 */

#include <Arduino.h>

#include "takt.h"

void
init_takt(void)
{
    pinMode(TAKT, INPUT_PULLDOWN );
}

int
takt_state(void)
{
    return digitalRead(TAKT);
}


