#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            13

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      28

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.setBrightness(50);
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show();
}

void loop() {

  pixelColor( "Red",1,2 ); //Red
  delay(1000);
  
  pixelColor( "Green",1,2 ); //Green
  delay(1000);
  
  pixelColor( "Blue", 1, 2 ); //Blue
  delay(1000);
  
}

//Red   = 255, 0, 0
//Green = 0, 255, 0
//Blue  = 0, 0, 255

/*void whichLED( String sensor ) {
  
  if( sensor == "BRD" ){
      ;
  } else if( color == "Green"){
      grnLED( i );
  } else if( color == "Blue"){
     bluLED( i );
  }
  delay(10);
}*/


void pixelColor( String color, int str, int fin ) {

  for( int i = str; i < fin; i++){
    if( color == "Red" ){
      redLED( i );
    } else if( color == "Green"){
      grnLED( i );
    } else if( color == "Blue"){
      bluLED( i );
    }
      delay(10);
  }
}

void redLED( int x ) {
  //Red   = 255, 0, 0
  pixels.setPixelColor( x, pixels.Color( 255, 0, 0 ));
  pixels.show();
}

void grnLED( int x ) {
  //Green = 0, 255, 0
  pixels.setPixelColor( x, pixels.Color( 0, 255, 0 ));
  pixels.show();
}

void bluLED( int x ) {
  //Blue  = 0, 0, 255
  pixels.setPixelColor( x, pixels.Color( 0, 0, 255 ));
  pixels.show();
}



