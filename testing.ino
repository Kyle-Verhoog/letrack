#define O0 11
#define O1 10
#define O2 9
#define O3 6
#define O4 5
#define O5 3
#define I0 A0
#define I1 A1
#define I2 A2
#define I3 A3
#define I4 A4
#define I5 A5 

// OUTPUTS
const int LASER1_PIN = O1;
const int LASER2_PIN =  O0;
const int TRACK1_LED = O2;
const int TRACK2_LED = O3;

// INPUTS
const int SENSOR1_PIN = I0;
const int SENSOR2_PIN = I1;


const int SENSITIVITY = 200;
void setup() {
  Serial.begin(9600);
  pinMode(LASER1_PIN, OUTPUT);
  pinMode(LASER2_PIN, OUTPUT);
  pinMode(TRACK1_LED, OUTPUT);
  pinMode(TRACK2_LED, OUTPUT);
  digitalWrite(LASER1_PIN, HIGH);
  digitalWrite(LASER2_PIN, HIGH);
}

int sensor1Value = 0;
int sensor2Value = 0;
void loop() {
  sensor1Value = analogRead(SENSOR1_PIN);
  sensor2Value = analogRead(SENSOR2_PIN);

  if (sensor1Value < SENSITIVITY) {
    digitalWrite(TRACK1_LED, HIGH);
    digitalWrite(TRACK2_LED, LOW);
    delay(10000);
  } else if (sensor2Value < SENSITIVITY) {
    digitalWrite(TRACK2_LED, HIGH);
    digitalWrite(TRACK1_LED, LOW);
    delay(10000);
  }
  digitalWrite(TRACK1_LED, LOW);
  digitalWrite(TRACK2_LED, LOW);
}


