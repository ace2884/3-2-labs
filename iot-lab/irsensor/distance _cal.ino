// calculating the distance of space using ir sensor in cm

#define ECHOPIN
#define TRIGPIN
int led=12;
int a,b;

void setup() {
  serial.begin(9600);
  pinMode(ECHOPIN,INPUT);
  pinMode(TRIGPIN,OUTPUT);

}
void loop() {
  digitalWrite(TRIGPIN,LOW);
  delayMicroseconds(2000);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(1000);
  digitalWrite(TRIGPIN,LOW);
  float a=pulseIn(ECHOPIN,HIGH);
  b=a*0.344/2;
  serial.print(b);
  serial.print("cm");
  delay(1000);
}
