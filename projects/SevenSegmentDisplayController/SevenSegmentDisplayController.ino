int pins[8] = {4,5,8,7,6,3,2,9};

void setup() {
  for(int i = 0; i<8; i++){
    pinMode(pins[i], OUTPUT);
  }
}

void initt(){
  for(int j = 0; j < 8;j++){
    digitalWrite(pins[j],LOW);
    Serial.println(pins[j]);
  }
}

void one(){
  initt();
  digitalWrite(pins[1],HIGH);
  digitalWrite(pins[2],HIGH);
}

void two(){
  initt();
  digitalWrite(pins[0],HIGH);
  digitalWrite(pins[1],HIGH);
  digitalWrite(pins[3],HIGH);
  digitalWrite(pins[4],HIGH);
  digitalWrite(pins[6],HIGH);
}

void three(){
  initt();
  digitalWrite(pins[0],HIGH);
  digitalWrite(pins[1],HIGH);
  digitalWrite(pins[2],HIGH);
  digitalWrite(pins[3],HIGH);
  digitalWrite(pins[6],HIGH);
}

void four(){
  initt();
  digitalWrite(pins[1],HIGH);
  digitalWrite(pins[2],HIGH);
  digitalWrite(pins[5],HIGH);
  digitalWrite(pins[6],HIGH);
}

void five(){
  initt();
  digitalWrite(pins[0],HIGH);
  digitalWrite(pins[2],HIGH);
  digitalWrite(pins[3],HIGH);
  digitalWrite(pins[5],HIGH);
  digitalWrite(pins[6],HIGH);
}

void six(){
  initt();
  digitalWrite(pins[0],HIGH);
  digitalWrite(pins[6],HIGH);
  digitalWrite(pins[2],HIGH);
  digitalWrite(pins[3],HIGH);
  digitalWrite(pins[4],HIGH);
  digitalWrite(pins[5],HIGH);
}

void seven(){
  initt();
  digitalWrite(pins[0],HIGH);
  digitalWrite(pins[1],HIGH);
  digitalWrite(pins[2],HIGH);
}

void eight(){
  initt();
  digitalWrite(pins[0],HIGH);
  digitalWrite(pins[1],HIGH);
  digitalWrite(pins[2],HIGH);
  digitalWrite(pins[3],HIGH);
  digitalWrite(pins[4],HIGH);
  digitalWrite(pins[5],HIGH);
  digitalWrite(pins[6],HIGH);
}

void nine(){
  initt();
  digitalWrite(pins[0],HIGH);
  digitalWrite(pins[1],HIGH);
  digitalWrite(pins[2],HIGH);
  digitalWrite(pins[3],HIGH);
  digitalWrite(pins[5],HIGH);
  digitalWrite(pins[6],HIGH);
}

void zero(){
  initt();
  digitalWrite(pins[0],HIGH);
  digitalWrite(pins[1],HIGH);
  digitalWrite(pins[2],HIGH);
  digitalWrite(pins[3],HIGH);
  digitalWrite(pins[4],HIGH);
  digitalWrite(pins[5],HIGH);
}

void turnon(int num){
  switch(num){    
    case 1 :  
      one();
      break;  
    case 2:  
      two();
      break; 
    case 3:  
      three();
      break;  
    case 4 : 
     four();
      break;   
    case 5 :  
      five();
      break;  
    case 6:  
      six();
      break; 
    case 7:  
      seven();
      break;  
    case 8 : 
      eight();
      break; 
    case 9 : 
      nine();
      break;  
    case 0 : 
      zero();
      break;   
    default	:
      initt();
      break;
  }
}

void countup() {
  for(int q = 0; q < 10; q++){
    turnon(q);
    delay(1000);
  }
}

void countdown() {
  for(int q = 9; q >= 0; q--){
    turnon(q);
    delay(1000);
  }
}

void loop() {
  //countdown();
  countup();
  //turnon(2+3);
}