#include <SPI.h>
#include <RF24.h>
#include <ros.h>

//#include <geometry_msgs/Twist.h
#include <std_msgs/Int32MultiArray.h>

ros::NodeHandle nh;

int32_t l;
//int32_t* j;
//int32_t* c;
//int32_t i;
int32_t last;
int32_t* first;
//int32t lirst;
int32_t ar[20];

 
 void storeData(const std_msgs::Int32MultiArray& msg){  
 last=msg.st_data;
 first=msg.data;
 l=msg.data_length;
 for(int i=0;i<l;i++){
 ar[i]=*(first+i);
 }
}


 
 ros::Subscriber<std_msgs::Int32MultiArray> sub1("/consensunval", &storeData); 


RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

 void setup()
 {
      radio.begin();
     radio.openWritingPipe(address);
     radio.stopListening();
     nh.initNode();
     nh.subscribe(sub1);
  }
  void loop()
  {
    nh.spinOnce();
    delay(1);
    radio.write(ar,sizeof(ar));
  }
