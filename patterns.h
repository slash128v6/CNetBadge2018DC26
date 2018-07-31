//   Pattern functions
//   Each function should have the following components:
//    * Must be declared void with no parameters or will break function pointer array
//    * Check effectInit, if false then init any required settings and set effectInit true
//    * Set effectDelay (the time in milliseconds until the next run of this effect)
//    * All animation should be controlled with counters and effectDelay, no delay() or loops
//    * Pixel data should be written using leds[XY(x,y)] to map coordinates to the led layout

void rainbow() 
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, cycleHue, 7);
}

void addGlitter( fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}

void rainbowWithGlitter() 
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}

void confetti() 
{

  // startup tasks
  if (effectInit == false) {
    effectInit = true;
    effectDelay = 10;
    selectRandomPalette();
  }

  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( cycleHue + random8(64), 200, 255);
}

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 60, 0, NUM_LEDS-1 );
  leds[pos] += CHSV( cycleHue, 255, 192);
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, cycleHue+(i*2), beat-cycleHue+(i*10));
  }
}

void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16( i+7, 0, NUM_LEDS-1 )] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}


void rotateColor() {
  // Rotating color dot
  // startup tasks
  if (effectInit == false) {
    effectInit = true;
    currentLed = 0;
    effectDelay = 32;
  }

    fadeToBlackBy( leds, NUM_LEDS, 16);

     previousLed = currentLed - 1;
      if (previousLed < 0) {
      previousLed = 16;
    }
    leds[currentLed] += CHSV( cycleHue, 255, 192);
    leds[previousLed] = CRGB::Black;
    currentLed++;
    if (currentLed > 16) {
      currentLed = 0;
    }
}

void pulsar() {
  // Pulsing white dots
  static byte ledPos = 0;

  // startup tasks
  if (effectInit == false) {
    effectInit = true;
    effectDelay = 5;
  }

  for (byte x = 0; x < kMatrixWidth; x++) {
    for (byte y = 0; y < kMatrixHeight; y++) {
      leds[XY(x, y)] = CHSV(cycleHue, 0, quadwave8(x * 256 + y * 256 + ledPos));
    }
  }

  ledPos -= 4;

}
