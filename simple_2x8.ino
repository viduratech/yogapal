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

//int rowPin0 = 6;
int colPin0 = 2;
int senPin0 = A0;
int rdgPin0 = 0;
int valPin0 = 0;
int ledPin0 = 0;

//int rowPin1 = 7;
int colPin1 = 3;
int senPin1 = A1;
int rdgPin1 = 0;
int valPin1 = 0;
int ledPin1 = 0;

//int rowPin2 = 8;
int colPin2 = 4;
int senPin2 = A2;
int rdgPin2 = 0;
int valPin2 = 0;
int ledPin2 = 0;

//int rowPin3 = 9;
int colPin3 = 5;
int senPin3 = A3;
int rdgPin3 = 0;
int valPin3 = 0;
int ledPin3 = 0;

//int rowPin4 = 8;
int colPin4 = 6;
int senPin4 = A4;
int rdgPin4 = 0;
int valPin4 = 0;
int ledPin4 = 0;

//int rowPin5 = 9;
int colPin5 = 7;
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
  pinMode(colPin0, OUTPUT);
  pinMode(senPin0,  INPUT);

  //pinMode(rowPin1, OUTPUT);
  pinMode(colPin1, OUTPUT);
  pinMode(senPin1,  INPUT);

  //pinMode(rowPin2, OUTPUT);
  pinMode(colPin2, OUTPUT);
  pinMode(senPin2,  INPUT);

  //pinMode(rowPin3, OUTPUT);
  pinMode(colPin3, OUTPUT);
  pinMode(senPin3,  INPUT);

  //pinMode(rowPin4, OUTPUT);
  pinMode(colPin4, OUTPUT);
  pinMode(senPin4,  INPUT);

  //pinMode(rowPin5, OUTPUT);
  pinMode(colPin5, OUTPUT);
  pinMode(senPin5,  INPUT);


  Serial.begin(9600);
}

void loop() {
  /*digitalWrite(rowPin0,  LOW);
  digitalWrite(rowPin1,  LOW);
  digitalWrite(rowPin2,  LOW);
  digitalWrite(rowPin3,  LOW);
*/
  digitalWrite(colPin0,  LOW);
  digitalWrite(colPin1,  LOW);
  digitalWrite(colPin2,  LOW);
  digitalWrite(colPin3,  LOW);
  digitalWrite(colPin4,  LOW);
  digitalWrite(colPin5,  LOW);

  delay(10);

  //digitalWrite(colPin0, HIGH);
  rdgPin0 = analogRead(senPin0);
  Serial.print("sensor0 prev: ");
  Serial.print(rdgPin0);
  digitalWrite(colPin0,  LOW);

  //digitalWrite(colPin1, HIGH);
  rdgPin1 = analogRead(senPin1);
  Serial.print(", sensor1 prev: ");
  Serial.print(rdgPin1);
  digitalWrite(colPin1,  LOW);

  //digitalWrite(colPin2, HIGH);
  rdgPin2 = analogRead(senPin2);
  Serial.print(", sensor2 prev: ");
  Serial.print(rdgPin2);
  digitalWrite(colPin2,  LOW);

  //digitalWrite(colPin3, HIGH);
  rdgPin3 = analogRead(senPin3);
  Serial.print(", sensor3 prev: ");
  Serial.print(rdgPin3);
  digitalWrite(colPin3,  LOW);

  //digitalWrite(colPin4, HIGH);
  rdgPin4 = analogRead(senPin4);
  Serial.print(", sensor4 prev: ");
  Serial.print(rdgPin4);
  digitalWrite(colPin4,  LOW);

  //digitalWrite(colPin5, HIGH);
  rdgPin5 = analogRead(senPin5);
  Serial.print(", sensor5 prev: ");
  Serial.println(rdgPin5);
  digitalWrite(colPin5,  LOW);

  delay(100);

  //digitalWrite(colPin0, HIGH);
  valPin0 = analogRead(senPin0);
  Serial.print("sensor0 curr: ");
  Serial.print(valPin0);
  digitalWrite(colPin0,  LOW);

  //digitalWrite(colPin1, HIGH);
  valPin1 = analogRead(senPin1);
  Serial.print(", sensor1 curr: ");
  Serial.print(valPin1);
  digitalWrite(colPin1,  LOW);

  //digitalWrite(colPin2, HIGH);
  valPin2 = analogRead(senPin2);
  Serial.print(", sensor2 curr: ");
  Serial.print(valPin2);
  digitalWrite(colPin2,  LOW);

  //digitalWrite(colPin3, HIGH);
  valPin3 = analogRead(senPin3);
  Serial.print(", sensor3 curr: ");
  Serial.print(valPin3);
  digitalWrite(colPin3,  LOW);

  //digitalWrite(colPin4, HIGH);
  valPin4 = analogRead(senPin4);
  Serial.print(", sensor4 curr: ");
  Serial.print(valPin4);
  digitalWrite(colPin4,  LOW);

  ///digitalWrite(colPin5, HIGH);
  valPin5 = analogRead(senPin5);
  Serial.print(", sensor5 curr: ");
  Serial.println(valPin5);
  digitalWrite(colPin5,  LOW);

  if ( (ledPin0 >= 1) && ((valPin0 - rdgPin0) > 100)) {
    Serial.println("0 Pressure!");
    ledPin0 = 1;
  } else if ( (ledPin0 >= 1) && ((valPin0 - rdgPin0) < 100)) {
    Serial.println("0 Pressure!");
    ledPin0 = 2;
  } else if ( (ledPin0 >= 1) && ((rdgPin0 - valPin0) < 100)) {
    Serial.println("0 Pressure!");
    ledPin0 = 0;  
  } else {
    Serial.println("0 Nothing...");
    ledPin0 = 0;
  }

  if ( (ledPin1 >= 1) && ((valPin1 - rdgPin1) > 100)) {
    Serial.println("1 Pressure!");
    ledPin1 = 1;
  } else if ( (ledPin1 >= 1) && ((valPin1 - rdgPin1) < 100)) {
    Serial.println("1 Pressure!");
    ledPin1 = 2;
  } else if ( (ledPin1 >= 1) && ((rdgPin1 - valPin1) < 100)) {
    Serial.println("1 Pressure!");
    ledPin1 = 0;  
  } else {
    Serial.println("1 Nothing...");
    ledPin1 = 0;
  }

  if ( (ledPin2 >= 1) && ((valPin2 - rdgPin2) > 100)) {
    Serial.println("2 Pressure!");
    ledPin2 = 1;
  } else if ( (ledPin2 >= 1) && ((valPin2 - rdgPin2) < 100)) {
    Serial.println("2 Pressure!");
    ledPin2 = 2;
  } else if ( (ledPin2 >= 1) && ((rdgPin2 - valPin2) < 100)) {
    Serial.println("2 Pressure!");
    ledPin2 = 0;  
  } else {
    Serial.println("2 Nothing...");
    ledPin2 = 0;
  }

  if ( (ledPin3 >= 1) && ((valPin3 - rdgPin3) > 100)) {
    Serial.println("3 Pressure!");
    ledPin3 = 1;
  } else if ( (ledPin3 >= 1) && ((valPin3 - rdgPin3) < 100)) {
    Serial.println("3 Pressure!");
    ledPin3 = 2;
  } else if ( (ledPin3 >= 1) && ((rdgPin3 - valPin3) < 100)) {
    Serial.println("3 Pressure!");
    ledPin3 = 0;  
  } else {
    Serial.println("3 Nothing...");
    ledPin3 = 0;
  }

  if ( (ledPin4 >= 1) && ((valPin4 - rdgPin4) > 100)) {
    Serial.println("4 Pressure!");
    ledPin4 = 1;
  } else if ( (ledPin4 >= 1) && ((valPin4 - rdgPin4) < 100)) {
    Serial.println("4 Pressure!");
    ledPin4 = 2;
  } else if ( (ledPin4 >=1) && ((rdgPin4 - valPin4) < 100)) {
    Serial.println("4 Pressure!");
    ledPin4 = 0;  
  } else {
    Serial.println("4 Nothing...");
    ledPin4 = 0;
  }

  if ( (ledPin5 >=1) && ((valPin5 - rdgPin5) > 100)) {
    Serial.println("5 Pressure!");
    ledPin5 = 1;
  } else if ( (ledPin5 >=1) && ((valPin5 - rdgPin5) < 100)) {
    Serial.println("5 Pressure!");
    ledPin5 = 2;
  } else if ( (ledPin5 >=1) && ((rdgPin5 - valPin5) < 100)) {
    Serial.println("5 Pressure!");
    ledPin5 = 0;  
  } else {
    Serial.println("5 Nothing...");
    ledPin5 = 0;
  }
  
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(148,0,211)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(1); // Delay for a period of time (in milliseconds).
    
  }
/*
  if ( ledPin0 = 1 ) {
    pixels.setPixelColor(11, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(10, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(12, pixels.Color(0, 255, 0)); // Green
  } else if ( ledPin0 = 2 ) {
    pixels.setPixelColor(11, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(10, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(12, pixels.Color(0 , 0, 255)); // Blue
  } else if ( ledPin0 = 0 ) {
    pixels.setPixelColor(11, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(10, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(12, pixels.Color(255, 0, 0)); // Red
  }

  if ( ledPin1 = 1 ) {
    pixels.setPixelColor(6, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(7, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(8, pixels.Color(0, 255, 0)); // Green
  } else if ( ledPin1 = 2 ) {
    pixels.setPixelColor(6, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(7, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(8, pixels.Color(0 , 0, 255)); // Blue
  } else if ( ledPin1 = 0 ) {
    pixels.setPixelColor(6, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(7, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(8, pixels.Color(255, 0, 0)); // Red
  }
  
  if ( ledPin2 = 1 ) {
    pixels.setPixelColor(3, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(4, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(5, pixels.Color(0, 255, 0)); // Green
  } else if ( ledPin2 = 2 ) {
    pixels.setPixelColor(3, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(4, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(5, pixels.Color(0 , 0, 255)); // Blue
  } else if ( ledPin2 = 0 ) {
    pixels.setPixelColor(3, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(4, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(5, pixels.Color(255, 0, 0)); // Red
  }

  if ( ledPin3 = 1 ) {
    pixels.setPixelColor(0, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(1, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(2, pixels.Color(0, 255, 0)); // Green
  } else if ( ledPin3 = 2 ) {
    pixels.setPixelColor(0, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(1, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(2, pixels.Color(0 , 0, 255)); // Blue
  } else if ( ledPin3 = 0 ) {
    pixels.setPixelColor(0, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(1, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(2, pixels.Color(255, 0, 0)); // Red
  }

  if ( ledPin4 = 1 ) {
    pixels.setPixelColor(20, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(21, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(22, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(23, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(24, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(25, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(26, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(27, pixels.Color(0, 255, 0)); // Green
  } else if ( ledPin4 = 2 ) {
    pixels.setPixelColor(20, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(21, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(22, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(23, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(24, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(25, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(26, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(27, pixels.Color(0 , 0, 255)); // Blue
  } else if ( ledPin4 = 0 ) {
    pixels.setPixelColor(20, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(21, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(22, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(23, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(24, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(25, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(26, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(27, pixels.Color(255, 0, 0)); // Red
  }

   if ( ledPin5 = 1 ) {
    pixels.setPixelColor(12, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(13, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(14, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(15, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(16, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(17, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(18, pixels.Color(0, 255, 0)); // Green
    pixels.setPixelColor(19, pixels.Color(0, 255, 0)); // Green
  } else if ( ledPin5 = 2 ) {
    pixels.setPixelColor(12, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(13, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(14, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(15, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(16, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(17, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(18, pixels.Color(0 , 0, 255)); // Blue
    pixels.setPixelColor(19, pixels.Color(0 , 0, 255)); // Blue
  } else if ( ledPin5 = 0 ) {
    pixels.setPixelColor(12, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(13, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(14, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(15, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(16, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(17, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(18, pixels.Color(255, 0, 0)); // Red
    pixels.setPixelColor(19, pixels.Color(255, 0, 0)); // Red
  }*/
/*
  pixels.setPixelColor(255, 0, 0), 50); // Red
  pixels.setPixelColor(0, 255, 0), 50); // Green
  pixels.setPixelColor(0, 0, 255), 50); // Blue
*/
  delay(1000);
}


