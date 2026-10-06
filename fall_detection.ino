#include <Wire.h>

const int MPU_ADDR = 0x68;
const int BUZZER_PIN = 11;

int16_t AcX, AcY, AcZ;
float ax, ay, az;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  // Wake up the MPU6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  Serial.println("Tilt-Based Fall Detection Ready");
}

void loop() {
  readAccel();

  // Calculate acceleration magnitude
  float AM = sqrt(ax * ax + ay * ay + az * az);

  Serial.print("ax: ");
  Serial.print(ax);
  Serial.print(" ay: ");
  Serial.print(ay);
  Serial.print(" az: ");
  Serial.print(az);
  Serial.print(" | AM: ");
  Serial.println(AM);

  /*
    Tilt-based fall detection:
    When the absolute value of az falls below 0.6 g,
    the system considers the sensor to be significantly tilted
    and activates the buzzer.
  */

  if (abs(az) < 0.6) {
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("FALL (TILT) DETECTED");
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(200);
}

void readAccel() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU_ADDR, 6, true);

  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();

  // Convert raw accelerometer values to g
  ax = AcX / 16384.0;
  ay = AcY / 16384.0;
  az = AcZ / 16384.0;
}
