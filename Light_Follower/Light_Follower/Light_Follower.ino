/*


Check the below link for connections and other details
http://exploreembedded.com/wiki/index.php?title=Explore_Robo 

*/



int MotorLeft[2] = {A0,A1};//Motor Pins
int MotorRight[2] = {A2,A3};//Motor Pins	



void setup()
{
	MotorInit();
	
	
	//Serial.begin(9600);
	//Serial.println("Light Follower Robot");
}


void loop()
{ 
	
	
	
}




//Initialize the motor

void MotorInit()
{
	int i;
	for(i=0 ; i<2; i++)
	{
		pinMode(MotorLeft[i],OUTPUT);
		pinMode(MotorRight[i],OUTPUT);
	}
}

//Robot Driving Functions
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
	digitalWrite(MotorLeft[0],1);
	digitalWrite(MotorLeft[1],0);
	digitalWrite(MotorRight[0],1);
	digitalWrite(MotorRight[1],0);
}

void Robot_Right()
{
	digitalWrite(MotorLeft[0],0);
	digitalWrite(MotorLeft[1],1);
	digitalWrite(MotorRight[0],0);
	digitalWrite(MotorRight[1],1);
}

void Robot_Stop()
{
	digitalWrite(MotorLeft[0],0);
	digitalWrite(MotorLeft[1],0);
	digitalWrite(MotorRight[0],0);
	digitalWrite(MotorRight[1],0);
}



