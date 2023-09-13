//UniKL BMI
//Connecthing Things & Big Data Analytics
//Jul 2019

//include libraries
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

// defines pins numbers
const int trigPin = D4;
const int echoPin = D3;

// defines variables
long duration;
int distance;

int delay_time  = 3000; // Its mean 3 seconds wait to enter first record

//Access point credentials
const char* ssid        = "YES";//"IOT";
const char* pwd         = "a2856245";//"commtech123";

String add_data_url     = "http://192.168.43.20/iot-bda-szs/flood/add.php";
WiFiServer server(80);  // open port 80 for server connection

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  Serial.begin(115200); //initialise the serial communication
  delay(20);
  WiFi.begin(ssid, pwd);

  //starting the server
  server.begin();
}

void loop() {
  delay(2000);
  WiFiClient client = server.available();
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance= duration*0.034/2;

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  /*if (distance <15)
  {
    Serial.println("ALERT!!!:");
  }else {
    Serial.println("SAFE!!!");
  }*/
    int loc = 1; //1 = Sg Pusu;
    add_device_data(distance,loc);
    delay(delay_time);
}


void add_device_data(int get_height, int get_location )
  {
        
        WiFiClient client = server.available();

        HTTPClient http;
        String url = add_data_url+"?dist="+get_height+"&loc="+get_location;
        
        http.begin(url);
        //GET method
        int httpCode = http.GET();
        String payload = http.getString();
        Serial.println(url);
        Serial.println(payload);
        http.end();
        
  
  }
