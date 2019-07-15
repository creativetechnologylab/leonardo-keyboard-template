#include "Keyboard.h"

#define pin 7

boolean prev_state;

void setup() {
  Serial.begin( 9600 );
  Keyboard.begin();
  pinMode( pin, INPUT );
}

void loop() {
  boolean state = ! digitalRead( pin );

  if ( state && ! prev_state ) {
    Serial.println( "Hello" );
    Keyboard.print(1);
  }

  if ( !state && prev_state ) {
    Serial.println( "Goodbye" );
    Keyboard.print(0);
  }

  prev_state = state;
}
