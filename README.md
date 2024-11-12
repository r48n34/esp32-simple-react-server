# esp32-simple-react-server

Hosting a web server with react vite with esp32 wrover module with SPIFFS, WiFi, ESPAsyncWebServer and ArduinoJson.

## Hardware

Module: Teyleten Robot ESP32 30P  
Can be obtain in amazon for around 5.6 USD each.

![ESP32](https://m.media-amazon.com/images/I/71T9th3I59L._AC_SL1500_.jpg)

## Setup

0. Clone the project with:
```bash
git clone https://github.com/r48n34/esp32-simple-react-server.git
```

1. Install the following stuff in your Arduino-IDE Library:    

- `arduino-esp32fs-plugin` For SPIFFS  
https://github.com/me-no-dev/arduino-esp32fs-plugin  

- `ESPAsyncWebServer` For Hosting a simple web server  
https://github.com/lacamera/ESPAsyncWebServer  

- `ArduinoJson` For respond JSON  
https://arduinojson.org/?utm_source=meta&utm_medium=library.properties  

- `HTTPClient` For Fetching  
https://github.com/amcewen/HttpClient  

2. Open the `WiFiCredentials.h` and change the `WIFI_SSID` and `WIFI_PASSWORD` to your local wifi informations.  

3. Install `SPIFFS.h` for the esp32 and upload the website to the SP32 Filesystem.    
https://github.com/me-no-dev/arduino-esp32fs-plugin  

4. Verify the code from `esp32-react.ino` with adruino IDE and complie in the IDE.

## File structure
```
.
└── esp32-react/
    ├── data/ (SPIFFS folder for feeding HTML)
    │   └── react/
    │       └── Stuff that generated with `yarn build` in `src`
    ├── reactWeb/ (React project)
    │   ├── public
    │   ├── src
    │   │   └── ...
    │   ├── index.html
    │   ├── package.json
    │   ├── tsconfig.json
    │   ├── tsconfig.node.json
    │   └── vite.config.ts
    ├── esp32-react.ino   (Main program)
    └── WiFiCredentials.h (Input wifi ssid and password)
```

## References
1. ESP32 Filesystem Uploader  
https://randomnerdtutorials.com/esp32-web-server-spiffs-spi-flash-file-system/  