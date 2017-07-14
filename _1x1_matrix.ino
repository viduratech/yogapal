/*
1x1 presure sensor matrix code, 
 where each row/column is connected to an individual analog pin */

int grnLED = 5;
int redLED = 6;
int senPin = A0;
int rdgPin = 0;

int inComVals[2] = {
};

void setup() {
  //pinMode(rowPin, OUTPUT);  
  //pinMode(colPin, OUTPUT); 
  pinMode(senPin,  INPUT);
   
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(grnLED, LOW);
  digitalWrite(redLED, LOW);
  
  rdgPin = analogRead(senPin);
  Serial.print("sensor with colPin low: ");
  Serial.println(rdgPin);

  if(( rdgPin > 300 )) {
    digitalWrite(grnLED, HIGH);
    digitalWrite(redLED,  LOW);
    Serial.println("Pressure!");
  } else {
    digitalWrite(redLED, HIGH);
    digitalWrite(grnLED,  LOW);
    Serial.println("Nothing..."); 
  }
  
  delay(1000);
}


