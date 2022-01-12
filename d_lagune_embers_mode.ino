#ifndef LAGUNE_EMBERS_MODE
#define LAGUNE_EMBERS_MODE

byte rightRange(int mode) { //chooses the right function for the range
  if (mode == LAGUNE) {
    return laguneRangeSet(groupShifter);
  } else if (mode == EMBERS) {
    return embersRangeSet(groupShifter);
  } else {
    Serial.print("rightRange has a problem \n");
  }
}

int rightNumCases(int mode) { //chooses the right number of cases
  if (mode == LAGUNE) {
    return num_lagune_cases;
  } else if (mode == EMBERS) {
    return num_embers_cases;
  } else {
    Serial.print("rightNumCases has a problem \n");
    Serial.print("\n");
  }
}

/*
   keep value between 40 and 255.
   every group has a max of 40 val difference between individual leds.
*/
byte setVal(byte *old_val, int last_group, int current_group) {
  int val_as_int = (int) * old_val;
  int max_val_diff = 40;
  if (&last_group != &current_group) { //between groups max 40 val diff
    if (wave_valup == false) {
      val_as_int -= millis() % max_val_diff;
    } else {
      val_as_int += millis() % max_val_diff;
    }
    if (val_as_int >= 255) {
      val_as_int = 255 - (val_as_int - 255); //prevents val_as_int to go to very low
      wave_valup = false;
      Serial.print("valup false, val: ");
      Serial.print(val_as_int);
      Serial.print("\n");
    } else if (val_as_int < 30) {
      val_as_int = 30 + (millis() % max_val_diff); //if val too low increase by 0-40}
      wave_valup = true;
      Serial.print("valup true, val: ");
      Serial.print(val_as_int);
      Serial.print("\n");
    }
  } else { // within a group max 20 val diff
    max_val_diff = 20;
    if (wave_valup == false) {
      val_as_int -= millis() % max_val_diff;
    } else {
      val_as_int += millis() % max_val_diff;
    }
    if (val_as_int >= 255) {
      val_as_int = 255 - (millis() % max_val_diff); //prevent sink to very low val
      wave_valup = false;
      Serial.print("valup false, val: ");
      Serial.print(val_as_int);
      Serial.print("\n");
    } else if (val_as_int < 30) {
      val_as_int = 30 + (millis() % max_val_diff); //if val too low increase by 0-40}
      wave_valup = true;
      Serial.print("valup true, val: ");
      Serial.print(val_as_int);
      Serial.print("\n");
    }
  }
  return val = (byte) val_as_int;
}

void waves() {
  /*
     divide the strip into groups of 5 leds
  */
  for (current_group = 0; current_group < led_groups_counter; current_group++) { //runs on all leds each group at a time
    for (int current_led_in_group = 0; current_led_in_group < GROUP_SIZE; current_led_in_group++ ) { //runs on 5 leds of each group
      /*
        set hue for each group. The groups move every 10 seconds (10000 millis) by adding
      */
      groupShifter = ((current_group + H_MINUTE) % rightNumCases(mode)); // every H_MINUTE the groups more 1 slot but the number cant exeed the max number of cases.
      LED[led_index] = CHSV(rightRange(mode), sat, setVal(&val, last_group, current_group)); //counts the led on the strip from first to last and gives each group a color range
      led_index++; //index for the setting of color in the strip
    }
    FastLED.show();
    delay(50);
  }
  last_group++; // run of current group is ended and it becomes the last group
  if (last_group > led_groups_counter) { //resets last group when it equals the total number of groups
    last_group = 0;
  }
}

/*
   The range is set via cases for each group.
   Cases are set to form a smooth transition by having double the number of cases minus one:
   After the case with the max hue for the range is reached the cases repeat in a dropping order.
   TODO - make a self setting function that devides the entire range according to led_groups_counter  enum? const?
*/
byte laguneRangeSet(int current_group) {
  switch (current_group) {

    case 0: //group range 105 - 110
      if (hue <= 105) {                                                                     //lower border of blue and sets hue up
        hue = 105 + (millis() % 5);
        delay(110);
      } else if (hue >= 110) {                                                                     //upper border of blue  and sets hue down
        hue = 110 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 1: //group range 110 - 115
      if (hue <= 110) {                                                                     //lower border of blue and sets hue up
        hue = 110 + (millis() % 5);
        delay(110);
      } else if (hue >= 115) {                                                                     //upper border of blue  and sets hue down
        hue = 115 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 2: //group range 115 - 120
      if (hue <= 115) {                                                                     //lower border of blue and sets hue up
        hue = 115 + (millis() % 5);
        delay(110);
      } else if (hue >= 120) {                                                                     //upper border of blue  and sets hue down
        hue = 120 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 3: //group range 120 - 125
      if (hue <= 120) {                                                                     //lower border of blue and sets hue up
        hue = 120 + (millis() % 5);
        delay(110);
      } else if (hue >= 125) {                                                                     //upper border of blue  and sets hue down
        hue = 125 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 4: //group range 125 - 130
      if (hue <= 125) {                                                                     //lower border of blue and sets hue up
        hue = 125 + (millis() % 5);
        delay(110);
      } else if (hue >= 130) {                                                                     //upper border of blue  and sets hue down
        hue = 130 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 5: //group range 130 - 135
      if (hue <= 130) {                                                                     //lower border of blue and sets hue up
        hue = 130 + (millis() % 5);
        delay(110);
      } else if (hue >= 135) {                                                                     //upper border of blue  and sets hue down
        hue = 135 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 6: //group range 135 - 140
      if (hue <= 135) {                                                                     //lower border of blue and sets hue up
        hue = 135 + (millis() % 5);
        delay(110);
      } else if (hue >= 140) {                                                                     //upper border of blue  and sets hue down
        hue = 140 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 7: //group range 140 - 145
      if (hue <= 140) {                                                                     //lower border of blue and sets hue up
        hue = 140 + (millis() % 5);
        delay(110);
      } else if (hue >= 145) {                                                                     //upper border of blue  and sets hue down
        hue = 145 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 8: //group range 145 - 150
      if (hue <= 145) {                                                                     //lower border of blue and sets hue up
        hue = 145 + (millis() % 5);
        delay(110);
      } else if (hue >= 150) {                                                                     //upper border of blue  and sets hue down
        hue = 150 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 9: //group range 150 - 155
      if (hue <= 150) {                                                                     //lower border of blue and sets hue up
        hue = 150 + (millis() % 5);
        delay(110);
      } else if (hue >= 155) {                                                                     //upper border of blue  and sets hue down
        hue = 155 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 10: //group range 155 - 160
      if (hue <= 15) {                                                                     //lower border of blue and sets hue up
        hue = 155 + (millis() % 5);
        delay(110);
      } else if (hue >= 160) {                                                                     //upper border of blue  and sets hue down
        hue = 160 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 11: //group range 160 - 165
      if (hue <= 160) {                                                                     //lower border of blue and sets hue up
        hue = 160 + (millis() % 5);
        delay(110);
      } else if (hue >= 165) {                                                                     //upper border of blue  and sets hue down
        hue = 165 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 12: //group range 165 - 170
      if (hue <= 165) {                                                                     //lower border of blue and sets hue up
        hue = 165 + (millis() % 5);
        delay(110);
      } else if (hue >= 170) {                                                                     //upper border of blue  and sets hue down
        hue = 170 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 13: //group range 170 - 175
      if (hue <= 170) {                                                                     //lower border of blue and sets hue up
        hue = 170 + (millis() % 5);
        delay(110);
      } else if (hue >= 175) {                                                                     //upper border of blue  and sets hue down
        hue = 175 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 14: //group range 165 - 170
      if (hue <= 165) {                                                                     //lower border of blue and sets hue up
        hue = 165 + (millis() % 5);
        delay(110);
      } else if (hue >= 170) {                                                                     //upper border of blue  and sets hue down
        hue = 170 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 15: //group range 160 - 165
      if (hue <= 160) {                                                                     //lower border of blue and sets hue up
        hue = 160 + (millis() % 5);
        delay(110);
      } else if (hue >= 165) {                                                                     //upper border of blue  and sets hue down
        hue = 165 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 16: //group range 155 - 160
      if (hue <= 15) {                                                                     //lower border of blue and sets hue up
        hue = 155 + (millis() % 5);
        delay(110);
      } else if (hue >= 160) {                                                                     //upper border of blue  and sets hue down
        hue = 160 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 17: //group range 150 - 155
      if (hue <= 150) {                                                                     //lower border of blue and sets hue up
        hue = 150 + (millis() % 5);
        delay(110);
      } else if (hue >= 155) {                                                                     //upper border of blue  and sets hue down
        hue = 155 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 18: //group range 145 - 150
      if (hue <= 145) {                                                                     //lower border of blue and sets hue up
        hue = 145 + (millis() % 5);
        delay(110);
      } else if (hue >= 150) {                                                                     //upper border of blue  and sets hue down
        hue = 150 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 19: //group range 140 - 145
      if (hue <= 140) {                                                                     //lower border of blue and sets hue up
        hue = 140 + (millis() % 5);
        delay(110);
      } else if (hue >= 145) {                                                                     //upper border of blue  and sets hue down
        hue = 145 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 20: //group range 135 - 140
      if (hue <= 135) {                                                                     //lower border of blue and sets hue up
        hue = 135 + (millis() % 5);
        delay(110);
      } else if (hue >= 140) {                                                                     //upper border of blue  and sets hue down
        hue = 140 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 21: //group range 130 - 135
      if (hue <= 130) {                                                                     //lower border of blue and sets hue up
        hue = 130 + (millis() % 5);
        delay(110);
      } else if (hue >= 135) {                                                                     //upper border of blue  and sets hue down
        hue = 135 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 22: //group range 125 - 130
      if (hue <= 125) {                                                                     //lower border of blue and sets hue up
        hue = 125 + (millis() % 5);
        delay(110);
      } else if (hue >= 130) {                                                                     //upper border of blue  and sets hue down
        hue = 130 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 23: //group range 120 - 125
      if (hue <= 120) {                                                                     //lower border of blue and sets hue up
        hue = 120 + (millis() % 5);
        delay(110);
      } else if (hue >= 125) {                                                                     //upper border of blue  and sets hue down
        hue = 125 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 24: //group range 115 - 120
      if (hue <= 115) {                                                                     //lower border of blue and sets hue up
        hue = 115 + (millis() % 5);
        delay(110);
      } else if (hue >= 120) {                                                                     //upper border of blue  and sets hue down
        hue = 120 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 25: //group range 110 - 115
      if (hue <= 110) {                                                                     //lower border of blue and sets hue up
        hue = 110 + (millis() % 5);
        delay(110);
      } else if (hue >= 115) {                                                                     //upper border of blue  and sets hue down
        hue = 115 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    default:
      if (hue < 105) {                                                                     //lower border of blue and sets hue up
        hueup = true;                                                                     //hue++
      } else if (hue >= 170) {                                                                     //upper border of blue  and sets hue down
        hueup = false;
      }
      hueup ? hue++ : hue--;
      return hue;
      break;
  }
}

byte embersRangeSet(int current_group) {
  switch (current_group) {

    case 0: //group range 0 - 5
      if (hue <= 0) {                                                                     //lower border of blue and sets hue up
        hue = 0 + (millis() % 5);
        delay(110);
      } else if (hue >= 5) {                                                                     //upper border of blue  and sets hue down
        hue = 5 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 1: //group range 5 - 10
      if (hue <= 5) {                                                                     //lower border of blue and sets hue up
        hue = 5 + (millis() % 5);
        delay(110);
      } else if (hue >= 10) {                                                                     //upper border of blue  and sets hue down
        hue = 10 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 2: //group range 10 - 15
      if (hue <= 10) {                                                                     //lower border of blue and sets hue up
        hue = 10 + (millis() % 5);
        delay(110);
      } else if (hue >= 15) {                                                                     //upper border of blue  and sets hue down
        hue = 15 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 3: //group range 15 - 20
      if (hue <= 15) {                                                                     //lower border of blue and sets hue up
        hue = 15 + (millis() % 5);
        delay(110);
      } else if (hue >= 20) {                                                                     //upper border of blue  and sets hue down
        hue = 20 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 4: //group range 20 - 25
      if (hue <= 20) {                                                                     //lower border of blue and sets hue up
        hue = 20 + (millis() % 5);
        delay(110);
      } else if (hue >= 25) {                                                                     //upper border of blue  and sets hue down
        hue = 25 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 5: //group range 25 - 30
      if (hue <= 25) {                                                                     //lower border of blue and sets hue up
        hue = 25 + (millis() % 5);
        delay(110);
      } else if (hue >= 30) {                                                                     //upper border of blue  and sets hue down
        hue = 30 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 6: //group range 30 - 35
      if (hue <= 30) {                                                                     //lower border of blue and sets hue up
        hue = 30 + (millis() % 5);
        delay(110);
      } else if (hue >= 35) {                                                                     //upper border of blue  and sets hue down
        hue = 35 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 7: //group range 25 - 30
      if (hue <= 25) {                                                                     //lower border of blue and sets hue up
        hue = 25 + (millis() % 5);
        delay(110);
      } else if (hue >= 30) {                                                                     //upper border of blue  and sets hue down
        hue = 30 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 8: //group range 20 - 25
      if (hue <= 20) {                                                                     //lower border of blue and sets hue up
        hue = 20 + (millis() % 5);
        delay(110);
      } else if (hue >= 25) {                                                                     //upper border of blue  and sets hue down
        hue = 25 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 9: //group range 15 - 20
      if (hue <= 15) {                                                                     //lower border of blue and sets hue up
        hue = 15 + (millis() % 5);
        delay(110);
      } else if (hue >= 20) {                                                                     //upper border of blue  and sets hue down
        hue = 20 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 10: //group range 10 - 15
      if (hue <= 10) {                                                                     //lower border of blue and sets hue up
        hue = 10 + (millis() % 5);
        delay(110);
      } else if (hue >= 15) {                                                                     //upper border of blue  and sets hue down
        hue = 15 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    case 11: //group range 5 - 10
      if (hue <= 5) {                                                                     //lower border of blue and sets hue up
        hue = 5 + (millis() % 5);
        delay(110);
      } else if (hue >= 10) {                                                                     //upper border of blue  and sets hue down
        hue = 10 - (millis() % 5);
        delay(110);
      }
      return hue;
      break;

    default:
      if (hue < 0) {                                                                     //lower border of blue and sets hue up
        hueup = true;                                                                     //hue++
      } else if (hue >= 70) {                                                                     //upper border of blue  and sets hue down
        hueup = false;
      }
      hueup ? hue++ : hue--;
      return hue;
      break;
  }
}

#endif
