#include "BluetoothSerial.h"
#define RXD2 16
#define TXD2 17

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

String luxString = "";

BluetoothSerial SerialBT;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  SerialBT.begin("ESP32"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  delay(10000);

}

void loop() {
  /*Serial.print("Data Recived: ");
  Serial.println(Serial2.readString());
  delay(200);*/
  luxString = Serial2.readString();
  SerialBT.println(luxString);
  delay(1000);
  // put your main code here, to run repeatedly:
  }
