#include "WiFi.h"
#include "SPIFFS.h"
#include "ESPAsyncWebServer.h"
#include "ArduinoJson.h"
#include "WiFiCredentials.h"

#include <HTTPClient.h>

AsyncWebServer server(80);

void setup(){
    Serial.begin(115200);

    if(!SPIFFS.begin(true)){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }
    
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi..");
    }
    
    Serial.println(WiFi.localIP());

    server.on("/api/wifi-info", HTTP_GET, [](AsyncWebServerRequest *request) {    

        AsyncResponseStream *response = request->beginResponseStream("application/json");

        DynamicJsonDocument jsonData(1024);
        jsonData["status"] = "ok";
        jsonData["ssid"] = WiFi.SSID();
        jsonData["ip"] = WiFi.localIP().toString();

        serializeJson(jsonData, *response);
        request->send(response);
    });

    server.on("/ask", HTTP_GET, [](AsyncWebServerRequest *request){
        String advice = getServerData();

        AsyncResponseStream *response = request->beginResponseStream("application/json");
        DynamicJsonDocument json(1024);
        json["message"] = advice;
        serializeJson(json, *response);

        request->send(response);
    });

    server.serveStatic("/", SPIFFS, "/react")
        .setDefaultFile("index.html");
    
    server.onNotFound([](AsyncWebServerRequest *request){
        request->redirect("/");
    });
    
    server.begin();
}
  
void loop(){
    delay(2000);
}

String getServerData(){

    HTTPClient http;
    String serverPath = "https://api.adviceslip.com/advice";
    
    // Your Domain name with URL path or IP address with path
    http.begin(serverPath.c_str());
    
    // Send HTTP GET request
    int httpResponseCode = http.GET();

    if (!(httpResponseCode > 0)) { // Falied
        Serial.print("Error code: " + String(httpResponseCode));
        http.end();
        return "";
    }

    Serial.println("HTTP Response code: " + String(httpResponseCode));
    
    String payload = http.getString(); // Raw data

    DynamicJsonDocument doc(1024);
    deserializeJson(doc, payload);

    const char* advice = doc["slip"]["advice"];

    http.end();
    return String(advice);
}
