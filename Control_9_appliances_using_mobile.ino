////////////////////////////////////////////////////////////////////////////
//  Control 9 Electronic appliamces using Mobile                          //
//  made by IoTFever                                                      //
//  Contact iotfever.tech                                                 //  
//  contact iotfever1@gmail.com                                           //
//  cantact IoTFever.blogspot.com                                         //
//  Project Website --- https://www.instructables.com/member/adhanu99/    //
//  WiFi Scrolling Display --- https://youtu.be/bLIyVbeDaXk               //
//  Arduino LED Cube --- https://youtu.be/vYDEDb1dkn8                     //
//  Like and Subscribe                                                    //
////////////////////////////////////////////////////////////////////////////

#include <ESP8266WiFi.h>
 
const char* ssid = "IoTFever";
const char* password = "7878787878";
 
int relaypin1 = D0;
int relaypin2 = D1;
int relaypin3 = D2;
int relaypin4 = D3;
int relaypin5 = D4;
int relaypin6 = D5;
int relaypin7 = D6;
int relaypin8 = D7;
int relaypin9 = D8;

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(relaypin1, OUTPUT);
  pinMode(relaypin2, OUTPUT);
  pinMode(relaypin3, OUTPUT);
  pinMode(relaypin4, OUTPUT);
  pinMode(relaypin5, OUTPUT);
  pinMode(relaypin6, OUTPUT);
  pinMode(relaypin7, OUTPUT);
  pinMode(relaypin8, OUTPUT);
  pinMode(relaypin9, OUTPUT);
  
  digitalWrite(relaypin1, HIGH);
  digitalWrite(relaypin2, HIGH);
  digitalWrite(relaypin3, HIGH);
  digitalWrite(relaypin4, HIGH);
  digitalWrite(relaypin5, HIGH);
  digitalWrite(relaypin6, HIGH);
  digitalWrite(relaypin7, HIGH);
  digitalWrite(relaypin8, HIGH);
  digitalWrite(relaypin9, HIGH);
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
//-----------------------------------R1-------------------------------------
  if (request.indexOf("/S1on") != -1)  {
    digitalWrite(relaypin1, LOW);
   }
  if (request.indexOf("/S1off") != -1)  {
    digitalWrite(relaypin1, HIGH);
  } 
//-----------------------------------R2-------------------------------------
  if (request.indexOf("/S2on") != -1)  {
    digitalWrite(relaypin2, LOW);
   }
  if (request.indexOf("/S2off") != -1)  {
    digitalWrite(relaypin2, HIGH);
  } 
//-----------------------------------R3-------------------------------------
  if (request.indexOf("/S3on") != -1)  {
    digitalWrite(relaypin3, LOW);
   }
  if (request.indexOf("/S3off") != -1)  {
    digitalWrite(relaypin3, HIGH);
  }
//-----------------------------------R4-------------------------------------
  if (request.indexOf("/S4on") != -1)  {
    digitalWrite(relaypin4, LOW);
   }
  if (request.indexOf("/S4off") != -1)  {
    digitalWrite(relaypin4, HIGH);
  }   
//-----------------------------------R5-------------------------------------
  if (request.indexOf("/S5on") != -1)  {
    digitalWrite(relaypin5, LOW);
   }
  if (request.indexOf("/S5off") != -1)  {
    digitalWrite(relaypin5, HIGH);
  } 
//-----------------------------------R6-------------------------------------
  if (request.indexOf("/S6on") != -1)  {
    digitalWrite(relaypin6, LOW);
   }
  if (request.indexOf("/S6off") != -1)  {
    digitalWrite(relaypin6, HIGH);
  } 
//-----------------------------------R7-------------------------------------
  if (request.indexOf("/S7on") != -1)  {
    digitalWrite(relaypin7, LOW);
   }
  if (request.indexOf("/S7off") != -1)  {
    digitalWrite(relaypin7, HIGH);
  } 
//-----------------------------------R8-------------------------------------
  if (request.indexOf("/S8on") != -1)  {
    digitalWrite(relaypin8, LOW);
   }
  if (request.indexOf("/S8off") != -1)  {
    digitalWrite(relaypin8, HIGH);
  }              
//-----------------------------------R9-------------------------------------
  if (request.indexOf("/S9on") != -1)  {
    digitalWrite(relaypin9, LOW);
   }
  if (request.indexOf("/S9off") != -1)  {
    digitalWrite(relaypin9, HIGH);
  }   
}
