#include <Arduino.h>

#include "wapp_bot.h"
#include "led.h"
#include "takt.h"

void
setup(void)
{
    Serial.begin(SERIAL_BAUD);
    init_wapp_bot();
    init_led();
    init_takt();
}

void
loop(void)
{
    char buff[100];
    static int num = 0;

    if(takt_state())
    {
        set_led();
        sprintf(buff,"Hello form ESP32 %2d\n", ++num );
        if( send_wapp(buff) )
            Serial.println("Message sent");
        else
            Serial.println("Error sending");
        clear_led();
    }
    delay(100);
}

