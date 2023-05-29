

![Austral Ingenieria](https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQooGo7vQn4t9-6Bt46qZF-UY4_QFpYOeh7kVWzwpr_lbLr5wka)

<!--
    Ésta es la forma de poner comentarios en MarkDown
-->

# Proyecto 21-wapp-02

  Sends message to Wapp at takt close switch

## Secciones

- [Objetivo](#objetivo)
- [Hardware](#hardware)
- [Conexiones](#conexiones)
- [Programa](#programa)
- [Constantes](#constantes)
- [Sobre Acceso a WiFi](#wifi)
- [Links](#links)


## Objetivo

  El objetivo primordial de este proyecto es demostrar la capacidad de enviar un mensaje por WhatsApp
  Para ello, se ha hecho un programa de prueba principal que lee un pulsador (TAKT switch) y, ante su opresión
  envía un mensaje a un determinado número de Wapp

## Hardware

  Una placa de desarrollo ESP32.  
  Un pulsador takt.   
  Un LED (se usa el propio del ESP32)
  Cables.  

## Conexiones

  Conectar un extremo del pulsador takt a Vdd (3.3 volt).  
  Conectar el otro extremo del takt a el GPIO "TAKT"

## Programa

  El programa está estructurado en modulos de compilación separada en estructura jerárquica.  

  El módulo más jerarquico es "main.cpp", quien es el gerenciador de mas alto nivel; a traves de "setup" inicaliza las herramientas generales (como Serial) y los módulos dependientes de él, como "wapp_bot.cpp". "led.cpp" y "takt.cpp".  

  A través de "loop", sencillamente prueba cada 100 mseg si se oprime el pulsador; en el caso que se oprima, prende el LED y solicita al módulo "wapp_bot.cpp" que envíe el mensaje a Wapp, colocando el estado de terminación del módulo, y luego apaga el LED  

  El resto de los tres módulos son autoexplicables a través de su código y de la pagina de Web indicada más abajo, de donde se obtuvo el algoritmo básico de la conexión con Wapp  

  Existen solo dos herramientas (se denomina herramientas a aquellos módulos que no tienen una dependencia jeráquica con el proyecto) como son las llamadas a Serial, ya incluidas en Arduino y las rutinas de acceso a WiFi que, en este caso, solo las usa el módulo "wapp_bot.cpp"; en efecto, este módulo, cuando necesita WiFi se conecta, realiza la transacción y luego se desconecta. Ver el funcionamiento de las rutinas de WiFi mas abajo  

---

## Constantes

 La única biblioteca externa que se usa es la que permite el acceso a UrlEncode 

 La constante "DIAL" debe llevar el número telefónico a donde quiere enviarse el mesnaje de Wapp  

 La constante "API" es la llave que debe negociarse con callmebot.com (ver vinculo más abajo)   

 "TAKT" y "LED" son los GPIO donde están conectados dichos periféricos

##    wifi

 Para acceso a WiFi simplificado usado en este proyecto, ver archivo _esp32wifi.md_ en este mismo directorio.

##  Links

  [ESP32 Useful Wi-Fi Library Functions (Arduino IDE)](https://randomnerdtutorials.com/esp32-useful-wi-fi-functions-arduino/)

  [ESP32: Send Messages to WhatsApp](https://randomnerdtutorials.com/esp32-send-messages-whatsapp/)

  [Send WhatsApp, Facebook and Telegram messages](https://www.callmebot.com/)


