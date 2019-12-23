const int AnalogPin = A0;
const float GAUSS_PER_STEP = 1.96;  // Sensor outputs 2.5mV / Gauss.  
                                    // ADC step is about 4.89mV / Step
float rawValue = 0.0;
float gaussValue = 0.0;
float zeroLevel = 530.0;  // Adjust as needed to get zero output with no magnetic field present.

void setup() { 
  pinMode(AnalogPin, INPUT);
  Serial.begin(9600);         // Set comm speed for debug window messages
}

void loop() {
  rawValue = analogRead(AnalogPin) - zeroLevel;  // Output normalized to '0' with no field present
  Serial.print("Reading Raw: ");
  Serial.println(rawValue);
  // Reading positive relative to the South Pole, the North Pole negative
  gaussValue = rawValue * GAUSS_PER_STEP;
  Serial.print("Reading in Gauss: ");
  Serial.println(gaussValue);
  delay(3000);
}
