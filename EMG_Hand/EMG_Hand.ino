#include <Servo.h>
//define servo motors
Servo servo_3; Servo servo_4; Servo servo_5; Servo servo_6; Servo servo_7;
//set red, blue, green and button pin
const int r = 11; const int g = 12; const int b = 13;
const int buttonstate = 9; 
//initialise count for mode selection
int count = 0; 
int button = 0;
int thresholdvalue = 240;
void setup() 
{
  Serial.begin(11500);
  servo_3.attach(3); servo_4.attach(4); servo_5.attach(5); servo_6.attach(6); servo_7.attach(7);
  pinMode(r, OUTPUT); pinMode(g, OUTPUT); pinMode(b, OUTPUT);
  pinMode(buttonstate, INPUT); 
}
void loop() {
  button=digitalRead(buttonstate);
  if (button == HIGH)
    {
     count = count + 1; //increase the counter once the button is released
     Serial.println(count);
    }
  int emgsensor= analogRead(A0);//to read analog value from emg sensor
  Serial.println(emgsensor);   //to print value of sensor in serial monitor 
  //for mode selection
   if (count == 0) //mode 0 in which the function of the hand is just opening and closing all fingers
   {
    digitalWrite(g, LOW); digitalWrite(b, LOW); digitalWrite(r, HIGH); // for mode 0 red light 
    if(emgsensor < thresholdvalue)
    {
      servo_3.write(0);delay(100);servo_4.write(0);delay(100);servo_5.write(0);delay(100);servo_6.write(0);delay(100);servo_7.write(0);delay(100);
    }
    else
    {
      servo_3.write(180);delay(100);servo_4.write(180);delay(100);servo_5.write(180);delay(100);servo_6.write(180);delay(100);servo_7.write(180);delay(100);
   }
  } 
  if (count == 1)//mode 1 for thumb and index finger while others remain close
   {
    digitalWrite(r, LOW);digitalWrite(b, LOW);digitalWrite(g, HIGH);// for mode 1 green light 
    if(emgsensor < thresholdvalue)
    {
      servo_3.write(180);delay(100);servo_4.write(180);delay(100);servo_5.write(180);delay(100);servo_6.write(0);delay(100);servo_7.write(0);delay(100);
    }
    else
    {
      servo_3.write(180);delay(100);servo_4.write(180);delay(100);servo_5.write(180);delay(100);servo_6.write(180);delay(100);servo_7.write(180);delay(100);
   }
  } 
  if (count == 2)//mode 2 for thumb, index and middle finger while others remain close
   {
    digitalWrite(b, HIGH);digitalWrite(r, LOW);digitalWrite(g, LOW);// for mode 2 blue light 
    if(emgsensor < thresholdvalue)
    {
      servo_3.write(180);delay(100);servo_4.write(180);delay(100);servo_5.write(0);delay(100);servo_6.write(0);delay(100);servo_7.write(0);delay(100);
    }
    else
    {
      servo_3.write(180);delay(100);servo_4.write(180);delay(100);servo_5.write(180);delay(100);servo_6.write(180);delay(100);servo_7.write(180);delay(100);
   }
  } 
   if (count == 3)//mode 3 takes back to mode 0
   {
    count = 0;
   }
   
}
