// RPM Counter using IR Sensor
// Arduino UNO | IR Sensor (5V) | DC Motor (12V)
// Ramco Institute of Technology - Kiruthika R

volatile int pulseCount = 0;
float rpm = 0;
unsigned long previousMillis = 0;
const int sensorPin = 2; // IR Sensor connected to pin 2
const int interval = 1000; // Calculate RPM every 1 second

void countPulse() {
  pulseCount++;
}

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(sensorPin), countPulse, RISING);
  Serial.println("RPM Counter Started...");
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    detachInterrupt(digitalPinToInterrupt(sensorPin));
    
    rpm = (pulseCount / 1.0) * 60.0;
    
    Serial.print("Pulse Count: ");
    Serial.println(pulseCount);
    Serial.print("RPM: ");
    Serial.println(rpm);
    
    pulseCount = 0;
    previousMillis = currentMillis;
    
    attachInterrupt(digitalPinToInterrupt(sensorPin), countPulse, RISING);
  }
}
