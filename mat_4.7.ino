/* Smart Yoga Mat Code V3 */
 
int fsr0 = 0;     // the FSR and 10K pulldown are connected to a0
int rdg0;            // the analog reading from the FSR resistor divider
int yel0 = 3;

int fsr1 = 1;     // the FSR and 10K pulldown are connected to a0
int rdg1;            // the analog reading from the FSR resistor divider
int yel1 = 5;

int fsr2 = 2;     // the FSR and 10K pulldown are connected to a0
int rdg2;            // the analog reading from the FSR resistor divider
int yel2 = 6;

int fsr3 = 3;     // the FSR and 10K pulldown are connected to a0
int rdg3;            // the analog reading from the FSR resistor divider
int yel3 = 9;

int red0 = 10;
int blu0 = 11;
  
int totl;
int vals;
int avg1;

int val0;
int val1;
int val2;
int val3;

int minval = 0;
int lcount = 1;
int dif = 0;

int valA[] = {rdg0, rdg1, rdg2, rdg3};
int yelA[] = {yel0, yel1, yel2, yel3};

void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);
  
  pinMode(yel0, OUTPUT); 
  pinMode(yel1, OUTPUT);
  pinMode(yel2, OUTPUT);
  pinMode(yel3, OUTPUT);
  pinMode(red0, OUTPUT);
  pinMode(blu0, OUTPUT); 
  
}
 
void loop(void) {
 
  rdg0 = analogRead(fsr0);
  rdg1 = analogRead(fsr1);
  rdg2 = analogRead(fsr2);
  rdg3 = analogRead(fsr3);

  if( rdg0 > 400 ) {
    val0 = 1;
  } else {
    val0 = 0;
  }

  if( rdg1 > 400 ) {
    val1 = 1;
  } else {
    val1 = 0;
  }

  if( rdg2 > 900 ) {
    val2 = 1;
  } else {
    val2 = 0;
  }

  if( rdg3 > 900 ) {
    val3 = 1;
  } else {
    val3 = 0;
  }

  vals = val0 + val1 + val2 + val3;
  
 // if( vals// some recursive shit
  
  //totl = rdg0 + rdg1 + rdg2 + rdg3;

  //avg1 = totl/4;

  if( vals > 3 ) {
    
    digitalWrite(yel0,  LOW);
    digitalWrite(yel1,  LOW);
    digitalWrite(yel2,  LOW);
    digitalWrite(yel3,  LOW);
    
    digitalWrite(red0,  LOW);
    digitalWrite(blu0,  LOW);

    dif = valA[minval] - valA[lcount];

    int i;
    for (i = 1; i < 5; i = i + 1) {

      lcount = i;
      
      switch (vals) {
      case 1:
        if (dif < 0) {
          minval = lcount;
        }
        break;
      case 2:
        if (dif < 0) {
          minval = lcount;
        }
        break;
      case 3:
        if (dif < 0) {
          minval = lcount;
        }
        break;
      case 4:
        analogWrite( 5, HIGH);
        analogWrite( 6, HIGH);
        digitalWrite(blu0, HIGH);

        delay(100);
         
        analogWrite( 5, LOW);
        analogWrite( 6, LOW);
        break;
      default: 
        //do no things
      break;
      }
    }

    //digitalWrite(yelA[minval], HIGH);
    
  } else {
    digitalWrite(yel0,  LOW);
    digitalWrite(yel1,  LOW);
    digitalWrite(yel2,  LOW);
    digitalWrite(yel3,  LOW);
    
    digitalWrite(red0, HIGH);
    digitalWrite(blu0,  LOW);
  }

   Serial.print("minval = ");
   Serial.print(minval);
   
   Serial.print(", rdg0 = ");
   Serial.print(rdg0);
   
   Serial.print(", rdg1 = ");
   Serial.print(rdg1);
   
   Serial.print(", rdg2 = ");
   Serial.print(rdg2);
   
   Serial.print(", rdg3 = ");
   Serial.println(rdg3);
    
   delay(100);
} 



