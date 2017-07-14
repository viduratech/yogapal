/*
  1x2 presure sensor matrix code,
  where each row/column is connected to an individual analog pin */

// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            11

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      28

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

int vib1 = 5;
//int vib2 = 6;

int senPin0 = A0;
int rdgPin0 = 0;
int valPin0 = 0;
int ledPin0 = 0;

int senPin1 = A1;
int rdgPin1 = 0;
int valPin1 = 0;
int ledPin1 = 0;

int senPin2 = A2;
int rdgPin2 = 0;
int valPin2 = 0;
int ledPin2 = 0;

int senPin3 = A3;
int rdgPin3 = 0;
int valPin3 = 0;
int ledPin3 = 0;

int senPin4 = A4;
int rdgPin4 = 0;
int valPin4 = 0;
int ledPin4 = 0;

int senPin5 = A5;
int rdgPin5 = 0;
int valPin5 = 0;
int ledPin5 = 0;

void setup() {

    // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.

  //pinMode(rowPin0, OUTPUT);
  //pinMode(colPin0, OUTPUT);
  pinMode(senPin0,  INPUT);

  //pinMode(rowPin1, OUTPUT);
  //pinMode(colPin1, OUTPUT);
  pinMode(senPin1,  INPUT);

  //pinMode(rowPin2, OUTPUT);
  //pinMode(colPin2, OUTPUT);
  pinMode(senPin2,  INPUT);

  //pinMode(rowPin3, OUTPUT);
  //pinMode(colPin3, OUTPUT);
  pinMode(senPin3,  INPUT);
  pinMode(senPin4,  INPUT);
  pinMode(senPin5,  INPUT);

  pinMode(vib1, OUTPUT);
//  pinMode(vib2, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(vib1, HIGH);
  delay(10);

  //digitalWrite(colPin0, HIGH);
  rdgPin0 = analogRead(senPin0);
  Serial.print("sensor0 with colPin0 low: ");
  Serial.print(rdgPin0);
  //digitalWrite(colPin0,  LOW);

  //digitalWrite(colPin1, HIGH);
  rdgPin1 = analogRead(senPin1);
  Serial.print(", sensor1 with colPin1 low: ");
  Serial.print(rdgPin1);
  //digitalWrite(colPin1,  LOW);

  //digitalWrite(colPin2, HIGH);
  rdgPin2 = analogRead(senPin2);
  Serial.print(", sensor2 with colPin2 low: ");
  Serial.print(rdgPin2);
  //digitalWrite(colPin2,  LOW);

  //digitalWrite(colPin3, HIGH);
  rdgPin3 = analogRead(senPin3);
  Serial.print(", sensor3 with colPin3 low: ");
  Serial.println(rdgPin3);
  //digitalWrite(colPin2,  LOW);

  delay(10);
/*
  //digitalWrite(colPin0, HIGH);
  valPin0 = analogRead(senPin0);
  Serial.print("sensor0 with colPin0 high: ");
  Serial.print(valPin0);
  digitalWrite(colPin0,  LOW);

  //digitalWrite(colPin1, HIGH);
  valPin1 = analogRead(senPin1);
  Serial.print(", sensor1 with colPin1 high: ");
  Serial.print(valPin1);
  digitalWrite(colPin1,  LOW);

  //digitalWrite(colPin2, HIGH);
  valPin2 = analogRead(senPin2);
  Serial.print(", sensor2 with colPin0 high: ");
  Serial.print(valPin2);
  //digitalWrite(colPin2,  LOW);

  //digitalWrite(colPin3, HIGH);
  valPin3 = analogRead(senPin3);
  Serial.print(", sensor3 with colPin1 high: ");
  Serial.println(valPin3);
  //digitalWrite(colPin3,  LOW);
*/
  int sum = rdgPin0 + rdgPin1 + rdgPin2 + rdgPin3;

  if ( (sum) >  400) {
    Serial.println("0 Pressure!");
    ledPin0 = 1;
    
    digitalWrite( vib1 , LOW );
    delay(500);
    digitalWrite( vib1 , HIGH );
    delay(500);
     
  } else {
    Serial.println("0 Nothing...");
    ledPin0 = 0;
  }

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
/*
  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
*/
  delay(1000);
}

/*int readMux(int channel){
  int controlPin[] = {s0, s1, s2, s3};

  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
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


