#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <ros.h>
#include <std_msgs/Int32MultiArray.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

std_msgs::Int32MultiArray Arr;

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
    radio.read(&Arr, sizeof(Arr));
    Serial.println(Arr.data[0]);
     Serial.print("DATA=");
    
    Serial.println(Arr.data[1]);
    Serial.println(Arr.data[2]);
    Serial.println(Arr.data[3]);
    Serial.println(Arr.data[4]);
    //Serial.println(b.ayl);
    //Serial.println(b.azl);
    //Serial.println(b.axw);
    ////Serial.println(b.ayw);
    //Serial.println(b.azw);
    delay(500);
    
  }
  
 

}
