#ifndef B_MAIN
#define B_MAIN


void setup() {
  Serial.begin(9600);
  Serial.println("setup");
  pinMode(BUTTON_PIN, INPUT_PULLUP);                                //set the button pin
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), button_ISR, FALLING);
//  pinMode(Apin1, INPUT); //sound detector analog pin
//  pinMode(Dpin1, INPUT); //sound detector digital pin
//  pinMode(Apin2, INPUT); //sound detector analog pin
//  pinMode(Dpin2, INPUT); //sound detector digital pin
  if (STRIP % 2 == 0) { //has STRIP an even number of LEDs?
    even = true;
  } else {
    even = false;
  }
  /*
       if the strip has a number of leds that doesn't divide by GROUP_SIZE
       led_groups_counter should be incremented by 1 so those
       leds won't be dead
  */
  if (STRIP % GROUP_SIZE != 0) {
    led_groups_counter++;
  }
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), button_ISR, FALLING);
  delay(200); //soft start for some reason
  FastLED.addLeds<LEDTYPE, PL, GRB>(LED, STRIP);                                                                     //strip details
//  FastLED.setBrightness(50);
//  comrade1.sound_setup(Apin1, Dpin1); //create object
//  comrade2.sound_setup(Apin2, Dpin2); //create object
}


void loop() {
  buttonPress();
  cases();
}

#endif
