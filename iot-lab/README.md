
# week-3 (transfer sensor data to a smart phone using bluetooth)

```c
#include <SoftwareSerial.h> 
SoftwareSerial Bluetooth(9, 8);//RX,TX 
int LED = 13;//the on-board LED 
int Data;//the data received 
void setup() { 
Bluetooth.begin(9600); 
Serial.begin(9600); 
Serial.println("Waiting for command..."); 
Bluetooth.println("Send 1 to turn on the LED.Send 0 to turn off"); 
pinMode(LED,OUTPUT); 
} 
void loop() { 
if (Bluetooth.available()){ //wait for data received 
Data=Bluetooth.read(); 
if (Data==’1’) { 
digitalWrite(LED,1); 
Serial.println("LED On!"); 
Bluetooth.println("LED On!"); 
} 
else if(Data==’0’) { 
digitalWrite(LED,0); 
Serial.println("LED Off!"); 
Bluetooth.println("LED On D7 Off !"); 
} 
else{;} 
} 
delay(100); 
}
```
week-4 (Rfid read)

```C
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

//*****************************************************************************************//
void setup() {
  Serial.begin(9600);                                           // Initialize serial communications with the PC
  SPI.begin();                                                  // Init SPI bus
  mfrc522.PCD_Init();                                              // Init MFRC522 card
  Serial.println(F("Read personal data on a MIFARE PICC:"));    //shows in serial that it is ready to read
}

//*****************************************************************************************//
void loop() {

  // Prepare key - all keys are set to FFFFFFFFFFFFh at chip delivery from the factory.
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

  //some variables we need
  byte block;
  byte len;
  MFRC522::StatusCode status;

  //-------------------------------------------

  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.println(F("**Card Detected:**"));

  //-------------------------------------------

  mfrc522.PICC_DumpDetailsToSerial(&(mfrc522.uid)); //dump some details about the card

  //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));      //uncomment this to see all blocks in hex

  //-------------------------------------------

  Serial.print(F("Name:sneha "));

  byte buffer1[18];

  block = 4;
  len = 18;

  //------------------------------------------- GET FIRST NAME
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 4, &key, &(mfrc522.uid)); //line 834 of MFRC522.cpp file
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Authentication failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  status = mfrc522.MIFARE_Read(block, buffer1, &len);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Reading failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  //PRINT FIRST NAME
  for (uint8_t i = 0; i < 16; i++)
  {
    if (buffer1[i] != 32)
    {
      Serial.write(buffer1[i]);
    }
  }
  Serial.print(" ");

  //---------------------------------------- GET LAST NAME

  byte buffer2[18];
  block = 1;

  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 1, &key, &(mfrc522.uid)); //line 834
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Authentication failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  status = mfrc522.MIFARE_Read(block, buffer2, &len);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Reading failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  //PRINT LAST NAME
  for (uint8_t i = 0; i < 16; i++) {
    Serial.write(buffer2[i] );
  }


  //----------------------------------------

  Serial.println(F("\n**End Reading**\n"));

  delay(1000); //change value if you want to read cards faster

  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}
```

# week-4 (Rfid Write)

```c
/*
 * Write personal data of a MIFARE RFID card using a RFID-RC522 reader
 * Uses MFRC522 - Library to use ARDUINO RFID MODULE KIT 13.56 MHZ WITH TAGS SPI W AND R BY COOQROBOT. 
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 *
 * More pin layouts for other boards can be found here: https://github.com/miguelbalboa/rfid#pin-layout
 *
 * Hardware required:
 * Arduino
 * PCD (Proximity Coupling Device): NXP MFRC522 Contactless Reader IC
 * PICC (Proximity Integrated Circuit Card): A card or tag using the ISO 14443A interface, eg Mifare or NTAG203.
 * The reader can be found on eBay for around 5 dollars. Search for "mf-rc522" on ebay.com. 
 */

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

void setup() {
  Serial.begin(9600);        // Initialize serial communications with the PC
  SPI.begin();               // Init SPI bus
  mfrc522.PCD_Init();        // Init MFRC522 card
  Serial.println(F("Write personal data on a MIFARE PICC "));
}

void loop() {

  // Prepare key - all keys are set to FFFFFFFFFFFFh at chip delivery from the factory.
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print(F("Card UID:"));    //Dump UID
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.print(F(" PICC type: "));   // Dump PICC type
  MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
  Serial.println(mfrc522.PICC_GetTypeName(piccType));

  byte buffer[34];
  byte block;
  MFRC522::StatusCode status;
  byte len;

  Serial.setTimeout(20000L) ;     // wait until 20 seconds for input from serial
  // Ask personal data: Family name
  Serial.println(F("Type Family name, ending with #"));
  len = Serial.readBytesUntil('#', (char *) buffer, 30) ; // read family name from serial
  for (byte i = len; i < 30; i++) buffer[i] = ' ';     // pad with spaces

  block = 1;
  //Serial.println(F("Authenticating using key A..."));
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("PCD_Authenticate() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }
  else Serial.println(F("PCD_Authenticate() success: "));

  // Write block
  status = mfrc522.MIFARE_Write(block, buffer, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("MIFARE_Write() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }
  else Serial.println(F("MIFARE_Write() success: "));

  block = 2;
  //Serial.println(F("Authenticating using key A..."));
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("PCD_Authenticate() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  // Write block
  status = mfrc522.MIFARE_Write(block, &buffer[16], 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("MIFARE_Write() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }
  else Serial.println(F("MIFARE_Write() success: "));

  // Ask personal data: First name
  Serial.println(F("Type First name, ending with #"));
  len = Serial.readBytesUntil('#', (char *) buffer, 20) ; // read first name from serial
  for (byte i = len; i < 20; i++) buffer[i] = ' ';     // pad with spaces

  block = 4;
  //Serial.println(F("Authenticating using key A..."));
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("PCD_Authenticate() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  // Write block
  status = mfrc522.MIFARE_Write(block, buffer, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("MIFARE_Write() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }
  else Serial.println(F("MIFARE_Write() success: "));

  block = 5;
  //Serial.println(F("Authenticating using key A..."));
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("PCD_Authenticate() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  // Write block
  status = mfrc522.MIFARE_Write(block, &buffer[16], 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("MIFARE_Write() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }
  else Serial.println(F("MIFARE_Write() success: "));


  Serial.println(" ");
  mfrc522.PICC_HaltA(); // Halt PICC
  mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD

}
```

# week-5 (monitor temp and humidity)

```c
#include <Adafruit_Sensor.h> 
#include <DHT.h> 
#include <DHT_U.h> 
#define DHTPIN 2 
#define DHTTYPE DHT11 
DHT_Unified dht(DHTPIN, DHTTYPE); 
uint32_t delayMS; 
void setup() { 
Serial.begin(9600); 
dht.begin(); 
Serial.println(F("DHTxx Unified Sensor Example")); 
sensor_t sensor; 
dht.temperature().getSensor(&sensor); 
Serial.println(F("------------------------------------")); 
Serial.println(F("Temperature Sensor")); 
Serial.print (F("Sensor Type: ")); Serial.println(sensor.name);// 
Serial.print (F("Driver Ver: ")); Serial.println(sensor.version); 
Serial.print (F("Unique ID: ")); Serial.println(sensor.sensor_id); 
Serial.print (F("Max Value: ")); Serial.print(sensor.max_value); Serial.println(F("°C")); 
Serial.print (F("Min Value: ")); Serial.print(sensor.min_value); Serial.println(F("°C")); 
Serial.print (F("Resolution: ")); Serial.print(sensor.resolution); Serial.println(F("°C")); 
Serial.println(F("------------------------------------")); 
dht.humidity().getSensor(&sensor); 
Serial.println(F("Humidity Sensor")); 
Serial.print (F("Sensor Type: ")); Serial.println(sensor.name); 
Serial.print (F("Driver Ver: ")); Serial.println(sensor.version); 
Serial.print (F("Unique ID: ")); Serial.println(sensor.sensor_id); 
Serial.print (F("Max Value: ")); Serial.print(sensor.max_value); Serial.println(F("%")); 
Serial.print (F("Min Value: ")); Serial.print(sensor.min_value); Serial.println(F("%")); 
Serial.print (F("Resolution: ")); Serial.print(sensor.resolution); Serial.println(F("%")); 
Serial.println(F("------------------------------------")); 
delayMS = sensor.min_delay / 1000; 
} 
void loop() { 
delay(delayMS); 
sensors_event_t event; 
dht.temperature().getEvent(&event); 
if (isnan(event.temperature)) { 
Serial.println(F("Error reading temperature!"));} 
else { 
Serial.print(F("Temperature: ")); 
Serial.print(event.temperature); 
Serial.println(F("°C"));
} 
dht.humidity().getEvent(&event); 
if (isnan(event.relative_humidity)) { 
Serial.println(F("Error reading humidity!"));
} 
else { 
Serial.print(F("Humidity: ")); 
Serial.print(event.relative_humidity); 
Serial.println(F("%"));
}
} 
```

# week-6(interface IR sensors)

```c
#include <ESP8266WiFi.h>
String apiKey = "PFFHC1B2IRN0GGQ0"; 
const char *ssid = "Veeresh"; 
const char *pass = "veeru1987";
const char* server = "api.thingspeak.com";
#define IRpin D4 
WiFiClient client;
int value; 
void setup() 
{
Serial.begin(115200);
pinMode(IRpin, INPUT); 
delay(1000);
Serial.println("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, pass);
while (WiFi.status() != WL_CONNECTED)
{
delay(2000);
Serial.print(".");
}
Serial.println(" ");
Serial.println("WiFi connected");
}
void loop(){
 value = digitalRead(IRpin); 
Serial.println(value);
 if(value==0) 
 {
 Serial.print("object detected");
 }
 else
 {
 Serial.print("no object detected");
 }
if (client.connect(server,80)) 
{
String postStr = apiKey;
postStr +="&field1=";
postStr += String(value);
postStr += "\r\n\r\n";
client.print("POST /update HTTP/1.1\n");
client.print("Host: api.thingspeak.com\n");
client.print("Connection: close\n");
client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
client.print("Content-Type: application/x-www-form-urlencoded\n");
client.print("Content-Length: ");
client.print(postStr.length());
client.print("\n\n");
client.print(postStr);
client.stop();
Serial.println("Waiting...");
delay(1000);
}
}
```
# week-7 (uplaoding the temp and humidity data to the cloud)

```c
#include <DHT.h> // Including library for dht 
#include <ESP8266WiFi.h> 
String apiKey = "QR2JW82GS69I4DVY"; // Enter your Write API key from ThingSpeak 
const char *ssid = "Nokia G21"; // replace with your wifi ssid and wpa2 key 
const char *pass = "Vinutha23@"; 
const char* server = "api.thingspeak.com"; 
#define DHTPIN D5 //pin where the dht11 is connected 
DHT dht(DHTPIN, DHT22); 
WiFiClient client; 
void setup() { 
Serial.begin(9600); 
delay(1000); 
dht.begin(); 
Serial.println("Connecting to "); 
Serial.println(ssid); 
WiFi.begin(ssid, pass); 
while (WiFi.status() != WL_CONNECTED) { 
delay(5000); 
Serial.print(".");
} 
Serial.println(""); 
Serial.println("WiFi connected");
} 
void loop() { 
float h = dht.readHumidity(); 
float t = dht.readTemperature(); 
if (isnan(h) || isnan(t)) { 
Serial.println(F("Failed to read from DHT sensor!")); 
return;} 
if (client.connect(server,80)) // "184.106.153.149" or api.thingspeak.com{ 
String postStr = apiKey; 
postStr +="&field1="; 
postStr += String(h); 
postStr +="&field2="; 
postStr += String(t); 
postStr += "\r\n\r\n"; 
client.print("POST /update HTTP/1.1\n"); 
client.print("Host: api.thingspeak.com\n"); 
client.print("Connection: close\n"); 
client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n"); 
client.print("Content-Type: application/x-www-form-urlencoded\n"); 
client.print("Content-Length: "); 
client.print(postStr.length()); 
client.print("\n\n"); 
client.print(postStr); 
Serial.println("Temperature: "); 
Serial.println(t); 
Serial.print(" degrees Celcius, Humidity: "); 
Serial.println(h); 
Serial.println("%. Send to Thingspeak.");
} 
client.stop(); 
Serial.println("Waiting..."); 
delay(30);
} 
```

# week-8 (retrieve temp and humidity from cloud)

```c
#include <DHT.h> 
#include <ESP8266WiFi.h>
String apiKey = "UYK6QJGVZPSG5LF2"; //read 
const char *ssid = "Anuja"; 
const char *pass = "Anuja123";
const char* server = "api.thingspeak.com";
#define DHTPIN D3
 DHT dht(DHTPIN, DHT11);
WiFiClient client;
 void setup() 
{
 Serial.begin(115200);
 delay(1000);
 dht.begin();
 Serial.println("Connecting to ");
 Serial.println(ssid);
 WiFi.begin(ssid, pass);
 while (WiFi.status() != WL_CONNECTED) 
 {
 delay(500);
 Serial.print(".");
 }
Serial.println("");
Serial.println("WiFi connected");
}
void loop() 
{
 float h = dht.readHumidity();
 float t = dht.readTemperature();
 if (isnan(h) || isnan(t)) 
 {
 Serial.println("Failed to read from DHT sensor!");
 return;
 }
if (client.connect(server,80)) // "184.106.153.149" or api.thingspeak.com
{ 
 String postStr = apiKey;
 postStr +="&field1=";
 postStr += String(h);
 postStr +="&field2=";
 postStr += String(t);
 postStr += "\r\n\r\n";
 client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
 client.print("Content-Length: ");
 client.print(postStr.length());
 client.print("\n\n");
 client.print(postStr);
 Serial.print("Temperature: ");
 Serial.print(t);
 Serial.print(" degrees Celcius, Humidity: ");
 Serial.print(h);
 Serial.println("%. Send to Thingspeak.");
}
 client.stop();
 Serial.println("Waiting...");
 delay(1000);
}

```

# week 9 ( tcp server on cloud)

```c
#include "ESP8266WiFi.h"
#include "DHT.h"
const char* ssid = "Anuja";
const char* password = "Anuja123";
WiFiServer wifiServer(8080);
DHT dht(D3, DHT11); 
void setup() {
 Serial.begin(115200);
 delay(1000);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
 delay(1000);
 Serial.println("Connecting..");
 }
 Serial.print("Connected to WiFi. IP:");
 Serial.println(WiFi.localIP());
 wifiServer.begin();
 dht.begin();
}
void loop() {
 WiFiClient client = wifiServer.available();
 if (client) {
 while (client.connected()) {
 while (client.available()>0) {
 float t=dht.readTemperature();
 float h = dht.readHumidity();
 client.println("humidity :");
 client.println("temperature :");
 client.println(h);
 Serial.println(h);
 client.println(t);
 Serial.println(t);
 delay(2000);
 }
 }
 client.stop();
 Serial.println("Client disconnected");
 }
}
```

# week-10 ( udp server on cloud)

```c
#include <ESP8266WiFi.h> 
#include <WiFiUdp.h> 
#include <DHT.h> 
const char* ssid = "Galaxy A21sE600"; 
const char* password = "zilh8480"; 
const char* udpAddress = "192.168.87.225"; 
const int udpPort = 1234; 
#define DHTPIN D3 
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE); 
WiFiUDP udp; 
void setup() { 
 Serial.begin(115200); 
 Serial.println(); 
 Serial.println("Connecting to WiFi..."); 
 WiFi.begin(ssid, password); 
 while (WiFi.status() != WL_CONNECTED) { 
 delay(2000); 
 Serial.print(".");
} 
 Serial.println(); 
 Serial.println("WiFi connected."); 
 dht.begin();
} 
void loop() { 
 delay(2000); 
 float temperature = dht.readTemperature(); 
 float humidity = dht.readHumidity(); 
 if (isnan(temperature) || isnan(humidity)) { 
 Serial.println("Failed to read from DHT sensor!"); 
 return;} 
 Serial.print("Temperature: "); 
 Serial.print(temperature); 
 Serial.print(" °C\tHumidity: "); 
 Serial.print(humidity); 
 Serial.println(" %"); 
 Serial.println("Sending data over UDP..."); 
 udp.beginPacket(udpAddress, udpPort); 
 udp.print("Temperature: "); 
 udp.print(temperature); 
 udp.print(" °C, Humidity: "); 
 udp.print(humidity); 
 udp.println(" %"); 
 udp.endPacket(); 
 Serial.println("Data sent over UDP.");
} 
```
# Ultra Sonic sensor (calculate the Distance in cm)

```c
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
```

# IR sensor (object detection )

```c
int IRPin =8;
int led=13;
int value; 
void setup(){
pinMode(IRPin,INPUT); 
Serial.begin(9600); 
pinMode(led,OUTPUT);

}
void loop(){
 value = digitalRead(IRPin);           
Serial.println(value);
  if(digitalRead(IRPin)==0)
  { 
 digitalWrite(led,HIGH);
 Serial.println("object detected");
 
  }
  else
  {
  digitalWrite(led,LOW);
   Serial.println("object not detected");
 
}
}
```






