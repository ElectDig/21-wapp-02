/*
 *  wapp_bot.cpp
 */

#include <Arduino.h>

#include <HTTPClient.h>
#include <UrlEncode.h>
#include <WiFi.h>

#include "wifi_ruts.h"
#include "wapp_bot.h"

#if 0
String phoneNumber = "+5491154769326";
String apiKey = "9459256";
#else
String phoneNumber = DIAL;
String apiKey = API;
#endif

void
init_wapp_bot(void)
{
}

int
send_wapp(const char text[])
{
    int result;
    String message = text; 

    wifi_connect();
    // Data to send with HTTP POST
    String url =
        "https://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);
    HTTPClient http;
    http.begin(url);

    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    // Send HTTP POST request
    int httpResponseCode = http.POST(url);
    if (httpResponseCode == 200)
        result = 1;
    else
    {
        Serial.printf("%s: HTTP resonse code %d\n", __FUNCTION__, httpResponseCode);
        result = 0;
    }

    // Free resources
    http.end();
    wifi_disconnect();
    return result;
}

