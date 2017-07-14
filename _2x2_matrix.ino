/* Smart Yoga Mat Code 2x2 Matrix */

int numRows = 2;
int numCols = 2;
int numSens = 2;
int numRdgs = 2;
int numVals = 2;

int rows[] = {
  6, 7, 8, 9};
int cols[] = {
  2, 3, 4, 5};
int sens[] = {
  A0, A1, A2, A3};
int chks[4] = {
  };
int rdgP[4] = {
  };
int rdgC[4] = {
  };  
int vals[4] = {
  };

void setup() {
  // set all rows, columns, sensors, and values to INPUT (high impedance):
  for(int i=0; i<numRows; i++){
    pinMode(rows[i], OUTPUT);
  }
  for(int i=0; i<numCols; i++){
    pinMode(cols[i], OUTPUT);
  }
  for(int i=0; i<numSens; i++){
    pinMode(sens[i],  INPUT);
  }
  
  Serial.begin(9600);
}

void loop() {
  
  for(int r=0; r<numRows; r++){
    digitalWrite(rows[r], LOW);
  }
  for(int c=0; c<numCols; c++){
    digitalWrite(cols[c], LOW);
  }
  
  delay(100);

  int m = 0;
  int n = 0;
  
  for(int c=0; c<numCols; c++){

    for(int r=0; r<numRows; r++){
      
      n = r + c + m;
      Serial.print("n = ");
      Serial.println(n);
      
      chks[n] = analogRead(sens[n]);
      Serial.print("chks");
      Serial.print(n);
      Serial.print(" with col LOW: ");
      Serial.print(chks[n]);
  
      delay(100);
      
      digitalWrite(cols[c], HIGH);  // set HIGH
      
      rdgC[n] = analogRead(sens[n]);
      Serial.print(", sens");
      Serial.print(n);
      Serial.print(" with col HIGH: ");
      Serial.println(rdgC[n]);

      digitalWrite(cols[c],  LOW);
    
    }// end rowCount
    
    m = m + numCols - 1; 
    Serial.print("m = ");
    Serial.println(m);
    
  }// end colCount

  for(int j=0; j<numVals; j++){
    if( (rdgC[j]-rdgP[j]) > 100 ) {
      vals[j] = 1;
      Serial.print("Pressure on sens");
      Serial.println(j);
    } else {
      vals[j] = 0;
      Serial.print("Nothing on sens");
      Serial.println(j);
    }
    rdgP[j] = rdgC[j];
  }

  delay(1000);

}
