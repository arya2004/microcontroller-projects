long aa(int t, int e)
{
  pinMode(t, OUTPUT);  // Clear the trigger
  digitalWrite(t, LOW);delayMicroseconds(2);digitalWrite(t, HIGH);
  delayMicroseconds(10);digitalWrite(t, LOW);pinMode(e, INPUT);
  return  (0.01723 *pulseIn(e, HIGH));
}


void setup(){Serial.begin(9600);pinMode(2,OUTPUT);}

void loop()
{
  Serial.println(aa(7,8));
	if(aa(7,8)> 30){
    	digitalWrite(2,HIGH);
    }
  	if(aa(7,8)<= 30){
    	digitalWrite(2,LOW);
    }
	delay(100); 
}





void setup()
{Serial.begin(9600);pinMode(A5,INPUT);pinMode(4,OUTPUT);}
void loop(){int value=analogRead(A5);Serial.println(value);
if(value<200){
    digitalWrite(4,HIGH);}
digitalWrite(4,LOW);
}