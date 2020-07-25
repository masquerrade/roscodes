/* rosserial Subscriber Example */

#include <ros.h>
#include <std_msgs/Bool.h>

ros::NodeHandle  nh;

void messageCb( const std_msgs::Bool& msg){
  digitalWrite(13, msg.data);   // set the pin state to the message data;
  Serial.println(msg.data);
}

ros::Subscriber<std_msgs::Bool> sub("/arduino/led", &messageCb );

void setup()
{ 
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
