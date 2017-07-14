/*
1x2 presure sensor matrix code, 
 where each row/column is connected to an individual analog pin */
/*
int rowPin0 = 6;
int colPin0 = 2;
int senPin0 = A0;
int rdgPin0 = 0;
int valPin0 = 0;

int rowPin1 = 7;
int colPin1 = 3;
int senPin1 = A1;
int rdgPin1 = 0;
int valPin1 = 0;
*/
int rowPin0 = 8;
int colPin0 = 4;
int senPin0 = A2;
int rdgPin0 = 0;
int valPin0 = 0;

int rowPin1 = 9;
int colPin1 = 5;
int senPin1 = A3;
int rdgPin1 = 0;
int valPin1 = 0;

void setup() {
  
  pinMode(rowPin0, OUTPUT);  
  pinMode(colPin0, OUTPUT); 
  pinMode(senPin0,  INPUT);

  pinMode(rowPin1, OUTPUT);  
  pinMode(colPin1, OUTPUT); 
  pinMode(senPin1,  INPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(rowPin0,  LOW);
  digitalWrite(rowPin1,  LOW);
  digitalWrite(colPin0,  LOW);
  digitalWrite(colPin1,  LOW);

  delay(100);
  
  rdgPin0 = analogRead(senPin0);
  Serial.print("sensor0 with colPin0 low: ");
  Serial.print(rdgPin0);

  rdgPin1 = analogRead(senPin1);
  Serial.print(", sensor with colPin1 low: ");
  Serial.println(rdgPin1);
  
  delay(100);
  
  digitalWrite(colPin0, HIGH);
  valPin0 = analogRead(senPin0);
  Serial.print("sensor with colPin0 high: ");
  Serial.print(valPin0);
  
  digitalWrite(colPin1, HIGH);
  valPin1 = analogRead(senPin1);
  Serial.print(", sensor with colPin1 high: ");
  Serial.println(valPin1);
  
  if( (valPin0 - rdgPin0) >  100) {
    Serial.println("0 Pressure!");
  } else {
    Serial.println("0 Nothing..."); 
  }

  if( (valPin1 - rdgPin1) >  100) {
    Serial.println("1 Pressure!");
  } else {
    Serial.println("1 Nothing..."); 
  }
  
  delay(1000);
}


