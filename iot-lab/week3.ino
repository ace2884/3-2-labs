#include <softwareSerial.h>
SoftwareSerial Bluetooth(9,8);
int LED = 13;
int Data;
void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Waiting for command");
  Bluetooth.println("send 1 to turn on the Led. send o0 to turn off");
  pinMode(LED,OUTPUT);
}
void loop() {
  if(Bluetooth.avaliable()){
Data=bluetooth.read();
    if(Data=='1'){
digitalWrite(LED,1);
Serial.println("LED On");
Bluetoth.println("LED on");
    }
    else if(Data == '0'){
digitalWrite(LED,0);
serial.println("LED Off");
Blutooth.println("LED On D7 Off ");
    }      
    else{;}
    }
    delay(1000);
  }

