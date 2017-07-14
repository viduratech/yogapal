//FINAL PRESENTATION CODE!!!

//Mux control pins
int s0 = 8;
int s1 = 9;
int s2 = 10;
int s3 = 11;

//Vibration motors
int vib0 = 5;
int vib1 = 6;

int set = 0;

//LED strips
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN       13
#define NUMPIXELS 28

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//Mux in "SIG" pin
//int SIG_pin = 0;


int senPin0 = A0;
int senPin1 = A1;
int senPin2 = A2;
int senPin3 = A3;
int senPin4 = A4;
int senPin5 = A5;

int senVal  = 0;
int sum     = 0;

int senPins[6] = {A0, A1, A2, A3, A4, A5};
int senVals[6] = { 0,  0,  0,  0,  0,  0};

int senLocs[6][3]={ 
    {12, 16}, //channel 0, ALU
    {16, 20}, //channel 1, ARU
    { 6,  12}, //channel 2, ARD
    {20, 24}, //channel 3, BLU
    {24, 28}, //channel 4, BRU
    { 0,  6}, //channel 5, BLD
}; //str, fin

void setup() {
  // put your setup code here, to run once:
  
/*
  //Mux setup
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  //Vibration motor setup
  pinMode(vib0, OUTPUT);
  pinMode(vib1, OUTPUT);
  */
  //LED setup
  pixels.setBrightness(50);
  pixels.begin();
  pixels.show();

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //initialize vibration motors
  digitalWrite(vib0, HIGH);
  digitalWrite(vib1, HIGH);
  sum = 0;
  delay(10);
/*
  for(int i = 0; i < 8; i ++){
    Serial.print("Value at channel ");
    Serial.print(i);
    Serial.print(" is : ");
    Serial.println(readMux(i));
    
    delay(10);
  }*/
  
  for(int i = 0; i < 6; i ++){
    senVal = analogRead(senPins[i]);
    Serial.print("Value at channel ");
    Serial.print(i);
    Serial.print(" is : ");
    Serial.println(senVal);
    senVals[i] = senVal;
    
    delay(10);
  }
  
  for(int j = 0; j < 6; j ++){
    sum = sum + senVals[j];
  }

  Serial.print("sum = ");
  Serial.println(sum);
  
  Serial.println("");    
  Serial.print("set #");
  Serial.println(set);
  set++;

  for(int k = 0; k < 6; k ++){
      if( sum > 2222 ){
        //set to Purple
        for(int z = 0; z < 6; z ++){
          pixelColor( "Purple", senLocs[z][0], senLocs[z][1] );
        }
      }
      else if( (senVals[k] > 300) && (sum > 600) ){
        //set to Green
        pixelColor( "Green", senLocs[k][0], senLocs[k][1] );
      }
      else if( (senVals[k] < 300) && (sum > 600) ){
        //set to Red
        pixelColor( "Red", senLocs[k][0], senLocs[k][1] );
      }
      else if( (senVals[k] < 300) && (sum < 600) ){
        //set to Blue
        pixelColor( "Blue", senLocs[k][0], senLocs[k][1] );
      }
      else{
        //set to Blue
        pixelColor( "Blue", senLocs[k][0], senLocs[k][1] );
      }
  }
  delay(500);

}

/*
//function to read values from mux
int readMux(int channel){
  
  int controlPin[] = {s0, s1, s2, s3};

  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    //{0,0,1,0}, //channel 4
    //{1,0,1,0}, //channel 5
    //{0,1,1,0}, //channel 6
    //{1,1,1,0}, //channel 7
    //{0,0,0,1}, //channel 8
    //{1,0,0,1}, //channel 9
    //{0,1,0,1}, //channel 10
    //{1,1,0,1}, //channel 11
    //{0,0,1,1}, //channel 12
    //{1,0,1,1}, //channel 13
    //{0,1,1,1}, //channel 14
    //{1,1,1,1}  //channel 15
  };

  //loop through the 4 sig
  for(int i = 0; i < 4; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }

  //read the value at the SIG pin
  int val = analogRead(SIG_pin);

  //return the value
  return val;
}*/

void pixelColor( String color, int str, int fin ) {

  for( int l = str; l < fin; l++){
    if( color == "Red" ){
      redLED( l );
    } else if( color == "Green"){
      grnLED( l );
    } else if( color == "Blue"){
      bluLED( l );
    } else if( color == "Purple"){
      purLED( l );
    } 
      delay(10);
  }
}

//turns LEDs red
void redLED( int x ) {
  //Red   = 255, 0, 0
  pixels.setPixelColor( x, pixels.Color( 255, 0, 0 ));
  pixels.show();
}

//turns LEDs green
void grnLED( int x ) {
  //Green = 0, 255, 0
  pixels.setPixelColor( x, pixels.Color( 0, 255, 0 ));
  pixels.show();
}

//turns LEDs blue
void bluLED( int x ) {
  //Blue  = 0, 0, 255
  pixels.setPixelColor( x, pixels.Color( 0, 0, 255 ));
  pixels.show();
}

//turns LEDs Purple
void purLED( int x ) {
  //Purple  = 75, 0, 130
  pixels.setPixelColor( x, pixels.Color( 75, 0, 130 ));
  pixels.show();
}
