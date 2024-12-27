#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// Define the IR sensor pins
const int ir_sensor_1_pin = 15;  // Adjust as per your wiring
const int ir_sensor_2_pin = 23;
const int ir_sensor_3_pin = 16;

void setup() {
  Serial.begin(115200);           // Serial monitor on computer
  SerialBT.begin("ESP32_Parking"); // Bluetooth name for ESP32
  Serial.println("Bluetooth started. Waiting for connections...");

  // Set up IR sensor pins as inputs
  pinMode(ir_sensor_1_pin, INPUT);
  pinMode(ir_sensor_2_pin, INPUT);
  pinMode(ir_sensor_3_pin, INPUT);
}

void loop() {
  // Read the sensor values
  int sensor_value_1 = digitalRead(ir_sensor_1_pin);
  int sensor_value_2 = digitalRead(ir_sensor_2_pin);
  int sensor_value_3 = digitalRead(ir_sensor_3_pin);

  // Determine and print the status of each parking space
  String status1 = (sensor_value_1 == HIGH) ? "Occupied" : "Vacant";
  String status2 = (sensor_value_2 == HIGH) ? "Occupied" : "Vacant";
  String status3 = (sensor_value_3 == HIGH) ? "Occupied" : "Vacant";

  // Format the output for Serial Monitor and Bluetooth
  String output = "Space 1: " + status1 + "\n" +
                  "Space 2: " + status2 + "\n" +
                  "Space 3: " + status3 + "\n" +
                  "-------------------------";

  // Print to Serial Monitor
  Serial.println(output);

  // Print to Bluetooth Terminal
  SerialBT.println(output);

  // Delay between readings
  delay(2000);
}