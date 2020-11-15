#define pinRele 5

#include <SoftwareSerial.h>
SoftwareSerial btSerial(12, 13); // RX, TX

void setup() {
  pinMode(pinRele, OUTPUT);
  digitalWrite(pinRele, HIGH);
  btSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
static String btComando;
static bool releStatus = HIGH; 

  while (btSerial.available()) {
     char comandoRec = btSerial.read();
     btComando += char( comandoRec );
     Serial.print(comandoRec);


        if (btComando == "B1;") {
            digitalWrite(5, HIGH);
        }
        btComando = ""; 
     }
  }
