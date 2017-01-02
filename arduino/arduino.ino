#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server(192,168,1,10);  

EthernetClient client;
int port = 8000;
int pin = 2;
unsigned long previousMillis = 0;
unsigned int interval = 2000;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    Ethernet.begin(mac);
  }
  delay(1000);
  pinMode(pin,INPUT);
  Serial.println("connecting...");
  attachInterrupt(pin, notify, RISING);
}

void loop() {
  
}

void notify(){
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
     previousMillis = currentMillis;
    client.connect(server, port);
        if ( client.connected() == true )
       {
          client.flush();
          client.print("open");
        }
    }
}

