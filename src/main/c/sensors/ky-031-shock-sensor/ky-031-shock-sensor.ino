int Led=13;
int Shock=3;
int val;

void setup(){
  pinMode(Led,OUTPUT);
  pinMode(Shock,INPUT);
  Serial.begin(9600);
}

void loop(){
  val=digitalRead(Shock);
  if(val==HIGH){
    digitalWrite(Led,LOW);
    Serial.print("Reading Raw: ");
    Serial.println(val);
    delay(1500);
  } else {
    digitalWrite(Led,HIGH);
    Serial.print("Reading Raw: ");
    Serial.println(val);
    delay(1500);
  }
}
