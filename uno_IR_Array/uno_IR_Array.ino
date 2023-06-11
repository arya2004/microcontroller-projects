void setup() {
  // put your setup code here, to run once:
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("NEW");
  int thre = digitalRead(3);
  Serial.print("3 : ");
  Serial.println(thre);

    int fo = digitalRead(4);
  Serial.print("4 : ");
  Serial.println(fo);
    int fi = digitalRead(5);
  Serial.print("5 : ");
  Serial.println(fi);
    int si = digitalRead(6);
  Serial.print("6 : ");
  Serial.println(si);
    int se = digitalRead(7);
  Serial.print("7 : ");
  Serial.println(se);
  delay(1000);
}
