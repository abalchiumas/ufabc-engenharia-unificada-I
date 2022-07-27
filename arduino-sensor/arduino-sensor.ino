const int TRIG = 3;
const int ECHO = 2;

void setup() {
  Serial.begin(1200);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
}

void loop() {
  Serial.println(sensor(TRIG,ECHO));
  delay(100);
}

int sensor(int pinotrig,int pinoecho){
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/58;
}
