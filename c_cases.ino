#ifndef C_CASES
#define C_CASES

void cases() {
  //wrap button around the number of cases (4
  if (mode == 4) {
    mode = 0;
  }
  switch (mode) {

    case MODE_START:
      Serial.print("MODE_START ");

      //first effect is an orange sunrise
      sat = 255;
      hue = 12;
      for (int i =   0; i < 255; i++) {
        val++;
        delay(10);
        fill_solid(LED, STRIP, CHSV(hue, sat, val));
        FastLED.show();
      }
      mode = LAGUNE;

      break;

    case LAGUNE:
      Serial.print("lagune");
      Serial.print("\n");
      modeTimer = millis();
      if ((H_MINUTE % 40) < 20) { //change mode to embers after 10 min
        mode = EMBERS;
      }
      waves();
      led_index = 0; //resets index to prevent pointer error
      //      buttonPress();
      break;

    case EMBERS:
      Serial.print("embers");
      Serial.print("\n");
      modeTimer = millis();
      if ((H_MINUTE % 40) >= 20) { //change mode to embers after 10 min
        mode = LAGUNE;
      }
      waves();
      led_index = 0; //resets index to prevent pointer error
      //      buttonPress();
      break;

    case RAINFALL: // color starting from the middle of the strip and cascades left and right
      rainfall();
      //mode = RAINFALL;
      break;
    /*
        case MUSIC: //display based on amplitude and base
          if (!alreadySet) { //reset of alreadySet will be in the button function
            //        comrade1.sound_setup(Apin1, Dpin1);
            comrade2.sound_setup(Apin2, Dpin2);
          }
          //      comrade1.sample(Apin1, Dpin1);
          comrade2.sample(Apin2, Dpin2);
          comrade1.displayMusic();
          delay(120); //minimum delay needed so that interrupt is not ignored is ms
          break;
    */
    default:
      fill_solid(LED, STRIP, CHSV(0, 0, 0));                          //clear strip
      buttonPress();
      break;
  }
}
#endif
