#include<DHT.h>
#define dhtPin 2
#define dhtType DHT11
DHT dht(dhtPin,dhtType);
void setup() {
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
delay(2000);
float ph = 6.3;
int temp = 25;
int turbidity = 25;

if(isnan(ph)||isnan(temp)||isnan(turbidity))
{
  Serial.println("No data Availabale");
}
// Serial.print("Temperature:");
Serial.print(ph);
Serial.print(",");
Serial.print(temp);
Serial.print(",");
Serial.print(turbidity);
Serial.println(" ");

}
