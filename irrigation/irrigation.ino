const int motor = 10;            //LED connected to digital pin 10
const int OpenAirReading = 700;  //calibration data 1
const int WaterReading = 280;    //calibration data 2
int MoistureLevel = 0;
int SoilMoisturePercentage = 0;

void setup() {
  Serial.begin(9600);      // open serial port, set the baud rate to 9600 bps
  pinMode(motor, OUTPUT);  //sets the digital pin as output
}

void loop() {
  MoistureLevel = analogRead(A0);  //update based on the analog Pin selected
  Serial.println(MoistureLevel);
  SoilMoisturePercentage = map(MoistureLevel, OpenAirReading, WaterReading, 0, 100);

  if (SoilMoisturePercentage >= 50) {
    digitalWrite(motor, LOW);
    Serial.print("Soil Hydrated\n");
    delay(5000);
  } else if (SoilMoisturePercentage < 50) {
    digitalWrite(motor, HIGH);
    Serial.print("Soil Dehydrated\n");
    delay(1000);
  }
}
