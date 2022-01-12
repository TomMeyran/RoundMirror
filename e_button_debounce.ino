/*
   Button has 4 pins, 2 coming out of each side:
    1 (up left)
    2 (down left)
    3 (up right)
    4 (down right)
    1&3, 2&4 are connected both when the button is pressed and not
    1&2, 3&4 are connected when the button is pressed
    Button as interrupt (button pins are b1-b4):
      B1 open
      B2 goes to D2
      B3 goes to GND
      B4 goes to 10k ohm resistor and then to 5v
*/

static void button_ISR() {
  buttonFlag = true;
  flagTime = millis();
}

void buttonPress() {
  if (millis() - flagTime > debounceTime && buttonFlag == true) {
    mode++;         //change mode
    flagTime = 0;   //reset timer
    buttonFlag = false;
    }
//    Serial.print("mode: ");
//    Serial.println(mode);

}
