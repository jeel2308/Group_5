
#include <ESP8266WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include <Servo.h>


//Enter your Wifi name and password
#define WLAN_SSID       "Wi-Fi name" 
#define WLAN_PASS       "Wi-Fi password"

//Enter your Adafruit username and IO key 
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT   1883                  
#define AIO_USERNAME    "Adafruit IO id"
#define AIO_KEY         "Adafruit IO key"

Servo servo;  // initialize object of Servo class

WiFiClient client; //Initialize object of WifiClient class 

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

Adafruit_MQTT_Subscribe Door = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME"/feeds/door"); 

void MQTT_connect();   //function definition

void setup() {
  Serial.begin(115200);
  servo.attach(2);  //D4
  servo.write(0);
  
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); 
  Serial.println(WiFi.localIP());
  mqtt.subscribe(&Door);
  
}

void loop() {
 
  MQTT_connect();
  Adafruit_MQTT_Subscribe *subscription;
   /***************************************************************************************
      mqtt.readSubscription(20000) will sit and listen for up to 20 seconds for a message. 
      It will either get a message before the timeout,
      and reply with a pointer to the subscription or it will timeout and return 0.
    **************************************************************************************/
  while ((subscription = mqtt.readSubscription(20000))) {    
    if (subscription == &Door) {
      Serial.print("Got: "); 
      Serial.println((char *)Door.lastread);
      char* door = (char *)Door.lastread;
      if(*door == 'C')
      {
        servo.write(90);
      }
      else
      {
        servo.write(0);
      }
    }
  }
}

void MQTT_connect() 
{
  int8_t ret;  //signed 8-bit integer
  if (mqtt.connected()) 
  {
    return;
  }
  Serial.print("Connecting to MQTT... ");
  
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000); 
  }
  Serial.println("MQTT Connected!");  
}
