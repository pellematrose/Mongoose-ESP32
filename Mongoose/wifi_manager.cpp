#include "wifi_manager.h"
#include "WiFi.h"
#include "my_globals.h"
#include "mg_functions.h"
#include <ESPmDNS.h>

const char *ssidap = "ESP32-C3";
const char *passwordap = "123456789";

struct Cred {
  char ssid[40];
  char pass[40];
  char devname[40];
};
Cred c;

// Create WiFiServer object on port 80
WiFiServer  server(80);

void connect_wifi(){
  uint8_t timeout = 0;

  load(WIFI_ADDRESS, &c, sizeof(c));

  // Connecting to extern Wifi network
  WiFi.setHostname(c.devname);
  WiFi.mode(WIFI_STA);
  WiFi.begin(c.ssid, c.pass);
  Serial.printf("Connecting to %s\n", c.ssid);
  while (WiFi.status() != WL_CONNECTED && timeout < 12) {
    timeout++;
    delay(500);
    Serial.print(".");
    if(timeout==11) open_ap();
  }
  MDNS.begin(c.devname);
  Serial.println(" connected!");
  MG_INFO(("Connected; IP: %s", WiFi.localIP().toString().c_str()));
}

void open_ap(){
  // Establish a AP
  WiFi.softAP(ssidap, passwordap);
  delay(100);
  IPAddress IP = WiFi.softAPIP();
  Serial.printf("Connected; IP: %s", WiFi.localIP().toString().c_str());
  server.begin();
}