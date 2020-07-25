#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
float st;

float ar[20];

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  radio.begin();
  bool check=radio.isChipConnected();
  if(check){
    Serial.println(F("Chip Connected"));
  }
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

}

void loop() {
  // put your main code here, to run repeatedly:
    if (radio.available()) {
    radio.read(ar, sizeof(ar)); 
     Serial.print("[");  
    for(int i=0;i<5;i++){
   
    Serial.print(ar[i],6);
    Serial.print(", ");
    }
    Serial.print("]");
    Serial.println();
  }
  
  //delay();

}
