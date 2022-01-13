#include <WiFi.h>
//#include "secret.h"
//Geen idee hoe dit secret spul werkt, ik heb gewoon een wifi netwerkje gemaakt hiervoor.. 
#include "time.h"
// data below is set as a define in the file secret.h
const char* ssid       = "Mijn SSID";
const char* password   = "Mijn Wachtwoord";

void WiFi_connect(){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      printf(".");
  }
  printf(" CONNECTED\r\n");
}

void setup(){
  WiFi_connect();
}

void loop(){
}
