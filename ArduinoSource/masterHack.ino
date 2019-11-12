#include <Wire.h>     
#include <MPU6050.h>
MPU6050 accelerometer;
int smokeA0 = A0;
const int tem=A1; // Assigning analog pin A1 to variable
float tempc;
float vout;  //temporary variable to hold sensor reading

void setup() {
  Serial.begin(9600); 
  pinMode(tem,INPUT); 
  pinMode(smokeA0, INPUT);
  delay(2000);
  while(!accelerometer.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)) // Checking whether the mpu6050 is sensing or not
  {
  Serial.println("Failed to read from the sensor. Something is Wrong!");
  delay(500);
  }  
}

void loop() {
  Vector sensor_data = accelerometer.readNormalizeAccel();
  int pitch_value = -(atan2(sensor_data.XAxis, sqrt(sensor_data.YAxis*sensor_data.YAxis + sensor_data.ZAxis*sensor_data.ZAxis))*180.0)/M_PI;  // Calculating the pitch value
  Serial.print("acc: ");
  Serial.print("Pitch = ");
  Serial.print(pitch_value);        // Printing the pitch values on the Serial Monitor
  int roll_value = (atan2(sensor_data.YAxis, sensor_data.ZAxis)*180.0)/M_PI;    // Calculating the Raw value
  Serial.print(" Roll = ");
  Serial.println(roll_value);        // printing the Roll values on the serial monitor
  vout=analogRead(tem);
  vout=(vout*500)/1023;
  tempc=vout; // Storing value in Degree Celsius
  Serial.print("temp in DegreeC= ");
  Serial.println(tempc);
  int analogSensor = analogRead(smokeA0);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  delay(10);

}
