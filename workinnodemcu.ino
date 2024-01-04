#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

WiFiClient client;

long myChannelNumber1 = 2240581;
long myChannelNumber2 = 2323265;
long myChannelNumber3 = 2323266;
const char myWriteAPIKey1[] = "J5RBL39RXT5ENIYU";
const char myWriteAPIKey2[] = "FGPI99VADNVRTBD3";
const char myWriteAPIKey3[] = "T9TLP3L7RTSNG6IW";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("ONEPLUS_co_apdias", "shruti123");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  // dht.begin();
  ThingSpeak.begin(client);
}

void loop() {
  
String data=Serial.readStringUntil('\n');

int comma = data.indexOf(',');
if(comma!=-1){
  float ph = data.substring(0,comma).toFloat();
  data = data.substring(comma+1);
  comma = data.indexOf(',');
  int temp = data.substring(0,comma).toInt();
  int turbidity = data.substring(comma+1).toInt();
  Serial.print(ph);
  Serial.print(" ");
  Serial.print(temp);
  Serial.print(" ");
  Serial.print(turbidity);
  Serial.print("\n");

  ThingSpeak.writeField(myChannelNumber1, 1, ph, myWriteAPIKey1);
  ThingSpeak.writeField(myChannelNumber2, 1, temp, myWriteAPIKey2);
  ThingSpeak.writeField(myChannelNumber3, 1, turbidity, myWriteAPIKey3);
  delay(2000);
}
}