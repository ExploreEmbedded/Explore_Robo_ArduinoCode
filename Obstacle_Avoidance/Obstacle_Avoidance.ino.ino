
 /*


 

 */

#define trigPin A3
#define echoPin 2

int MotorLeft[2] = {8,9};//Motor Pins
int MotorRight[2] = {10,11};//Motor Pins  
long duration, distance;
char secondobstacle2;

void setup() {
  MotorInit();
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  secondobstacle2 = 0;
}

void loop() {

  getdistance();
   
    if ((distance < 20) && (secondobstacle2 == 0) )
  {
   Robot_Stop();
   delay(100); 
   Robot_Backward();
   delay(1000);
   Robot_Left();
   delay(1000);
   secondobstacle2 = 1;    
  }
  
 else if((distance < 20) && (secondobstacle2 == 1))
 {
   Robot_Stop();
   delay(100); 
   Robot_Backward();
   delay(1000);
   Robot_Right();
   delay(1000);
   secondobstacle2 = 0;    
  }

  

 else
 {
     Robot_Forward(); 
 }
 
  
 
 
}

void MotorInit()
{
  int i;
  for(i=0 ; i<2; i++)
  {
    pinMode(MotorLeft[i],OUTPUT);
    pinMode(MotorRight[i],OUTPUT);
  }
}


void Robot_Forward()
{
   digitalWrite(MotorLeft[0],0);
   digitalWrite(MotorLeft[1],1);
   digitalWrite(MotorRight[0],1);
   digitalWrite(MotorRight[1],0);   
}

void Robot_Backward()
{
   digitalWrite(MotorLeft[0],1);
   digitalWrite(MotorLeft[1],0);
   digitalWrite(MotorRight[0],0);
   digitalWrite(MotorRight[1],1);  
}

void Robot_Left()
{
  digitalWrite(MotorLeft[0],0);
  digitalWrite(MotorLeft[1],0);
  digitalWrite(MotorRight[0],1);
  digitalWrite(MotorRight[1],0);    
}

void Robot_Right()
{
  digitalWrite(MotorLeft[0],0);
  digitalWrite(MotorLeft[1],1);
  digitalWrite(MotorRight[0],0);
  digitalWrite(MotorRight[1],0);    
}
void Robot_Stop()
{
  digitalWrite(MotorLeft[0],0);
  digitalWrite(MotorLeft[1],0);
  digitalWrite(MotorRight[0],0);
  digitalWrite(MotorRight[1],0);
}

void getdistance()
{

  
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  
}



