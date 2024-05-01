int sensorPin = A0;
int relayPin = 3;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
   pinMode(relayPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorData = analogRead(sensorPin);
  Serial.print("Sensor data:");
  Serial.print(sensorData);
  Serial.print("\t |");
  if(sensorData >600){
    Serial.println("No moisture, soil is dry.");
    //code for working of motor.
    digitalWrite(relayPin, HIGH);
  }
   else if(sensorData >=400 && sensorData <=600){
    Serial.println("There is some moisture present.");
    digitalWrite(relayPin, LOW);
  }
  else if(sensorData >400){
    Serial.println("Soil is wet.");
    digitalWrite(relayPin, LOW);
  }

delay(100);
}
