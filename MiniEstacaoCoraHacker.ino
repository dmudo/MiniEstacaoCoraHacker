#include "DHTesp.h"
#include "MQ7.h"

DHTesp dht;
MQ7 mq7(A0,16);

void setup()
{
  Serial.begin(115200);
  Serial.println();
  

  dht.setup(4); // Connect DHT sensor to GPIO 17
  
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod());
  

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  float monoxidocarbono = mq7.getPPM();

  Serial.print(dht.getStatusString());
  Serial.print("\t");                     //distanciamento
  Serial.println("Umidade\tTemperatura\tMonóxido Carbono");
  Serial.print("\t");
  Serial.print(humidity, 1);              //o numero 1 franciona em 00.0 
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.print(mq7.getPPM());
  Serial.print("\t\t");
  Serial.println();
}
