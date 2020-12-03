#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "SKW";
const char* pass = "uni88123";

ESP8266WebServer server(80);
Servo myservo;

void setup(void){

  Serial.begin(115200);
  Serial.println("Connecting...");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", [](){
    
    server.send(200, "text/html", "<!DOCTYPE html> <html> <head> <title>41515015</title> <style> .button1{ background-color : #4caf50; text-decoration : none; text-align : center; font-size : 15px; font-weight : bold; width : 50px; height : 22.5px; border : none; color : white; padding : 15px 15px; margin : 2px 2px; cursor : pointer; display : inline-block; transition-duration: 0.2s; } .button2{ background-color : #e60a0a; text-decoration : none; text-align : center; font-size : 15px; font-weight : bold; width : 50px; height : 22.5px; border : none; color : white; padding : 15px 15px; margin : 2px 2px; cursor : pointer; display : inline-block; transition-duration: 0.2s; } </style> </head> <body><center> <h4>Dog_Food Auto_Feeding!</h4><a href=\"/on\" class=\"button1\"> ON </a></center></body> </html>");
  });

  server.on("/on", [](){

    Serial.println("ON");
    myservo.write(180);
    delay(1000);
    myservo.write(-180 );
    server.send(200, "text/html", "<!DOCTYPE html> <html> <head> <title>41515015</title> <style> .button1{ background-color : #4caf50; text-decoration : none; text-align : center; font-size : 15px; font-weight : bold; width : 50px; height : 22.5px; border : none; color : white; padding : 15px 15px; margin : 2px 2px; cursor : pointer; display : inline-block; transition-duration: 0.2s; } .button2{ background-color : #e60a0a; text-decoration : none; text-align : center; font-size : 15px; font-weight : bold; width : 50px; height : 22.5px; border : none; color : white; padding : 15px 15px; margin : 2px 2px; cursor : pointer; display : inline-block; transition-duration: 0.2s; } </style> </head> <body><center> <h4>Dog_Food Auto_Feeding!</h4><a href=\"/on\" class=\"button1\"> ON </a></center></body> </html>");
  });


  server.begin();
  Serial.println("HTTP server started");
  myservo.attach(D4);   // Servo attached to D4 pin
  myservo.write(0);
}

void loop(void){
  server.handleClient();
}
