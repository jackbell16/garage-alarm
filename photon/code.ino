
TCPClient client;
byte server[] = { 192, 168, 1, 10 };
int port = 8000;
unsigned long previousMillis = 0;
unsigned int interval = 2000;


void setup() {
  pinMode(D2, INPUT_PULLUP);
  attachInterrupt(D2, notify, FALLING);
}

 void loop()
{

}

void notify(){
    unsigned long currentMillis = millis();

  if(currentMillis - previousMillis > interval) {
     previousMillis = currentMillis;
		client.connect(server, port);
        if ( client.connected() == TRUE )
       {
          client.flush();
          client.print("open");

        }

	}

}
