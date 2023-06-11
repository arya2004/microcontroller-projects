void setup() {
 
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);


}

void loop() {

  digitalWrite(0, LOW);
   digitalWrite(1, 	LOW);
   digitalWrite(2, HIGH);
   digitalWrite(3, HIGH);
   digitalWrite(4, LOW);
   digitalWrite(5, LOW);
   digitalWrite(6, HIGH);
   digitalWrite(7, LOW);
    digitalWrite(8, LOW);
   digitalWrite(9, HIGH); m
   digitalWrite(10, LOW);
   digitalWrite(11, LOW);
  delay(2000); // Wait for 1000 millisecond(s)
 
   digitalWrite(1, 	HIGH);
   digitalWrite(2, LOW);

  delay(800); 

  
  digitalWrite(0, HIGH);
   digitalWrite(1, 	LOW);
   digitalWrite(2, LOW);
   digitalWrite(3, LOW);
   digitalWrite(4, LOW);
   digitalWrite(5, HIGH);
   
  delay(2000); // Wait for 1000 millisecond(s)

   
   digitalWrite(4, HIGH);
   digitalWrite(5, LOW);
   
  delay(800); 
  
  
  
   digitalWrite(3, HIGH);
   digitalWrite(4, LOW);
   digitalWrite(5, LOW);
   digitalWrite(6, LOW);
   digitalWrite(7, LOW);
    digitalWrite(8, HIGH);

  delay(2000); // Wait for 1000 millisecond(s)
   
 
 
   digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
 
  delay(800); 
  
  
  
   digitalWrite(6, HIGH);
   digitalWrite(7, LOW);
    digitalWrite(8, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
   digitalWrite(11, HIGH);
  delay(2000); // Wait for 1000 millisecond(s)
  
 

  
   digitalWrite(10, HIGH);
   digitalWrite(11, LOW);
  delay(800); 
}
