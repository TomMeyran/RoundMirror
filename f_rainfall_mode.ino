#ifndef F_RAINFALL
#define F_RAINFALL

//variables for both lists
bool changeHue = false;
//variables for list 1
int middleOfSide1 = (STRIP / 2 - 1); //string with 70 leds middle is 34
int endOfSide1 = 0; // increases the index of the end of the strip to make the effect of rain accumulating on the buttom
bool iAtEnd = false; // detects when i in rainfall for loop has reached 0 in order to avoid problems with the value of endOfSide1
//variables for list 2
int middleOfSide2 = (STRIP / 2); //string with 70 leds middle is 35
int endOfSide2 = (STRIP - 1); // increases the index of the end of the strip to make the effect of rain accumulating on the buttom
bool jAtEnd = false; // detects when j in rainfall for loop has reached 0 in order to avoid problems with the value of endOfSide1
/*
   nice colors
   gold           CHSV(27, 255, 55);
   bright blue    CHSV(150, 100, 100);
   dark blue      CHSV(27, 255, 55);
*/

byte hueRaindrop() {
  return 27;
}

byte satRaindrop() {
  return 255;
}

byte valRaindrop() {
  return 200;
}

int hueBackground(bool changeHue) {
  if (changeHue) {
    hue += 2;
  }
  if (hue > 255) {
    hue == 0;
  }
  if (hue < 0) {
    hue == 255;
  }
  //  Serial.print("background hue: ");
  //  Serial.println((int)hue);
  return (byte)hue;
}

byte satBackground(bool iAtEnd) {
  int sat = 255;

  return sat;
}

byte valBackground(bool iAtEnd) {
  int val = 100;
  //  val +=5;
  //  if(val > 255){val == 0;}
  return val;
}

// reduce the index so the color stays at the ends of the strip
int rainfallIndex_SingleColor() {

}

// 1 led goes down the chain and the other leds dont change color, the led drops down and stays and the strip slowly fills with the color
// 1 led goes down the chain while the other change color in a fade. the led fills the bottom that has another fade.
// list 1 led 0-34 right or left side of the mirror
void rainfall() {


  // the raindrop - single light that goes from middle of the strip towards the start
  for (int i = middleOfSide1; i >= endOfSide1; i--) {
    if (i == middleOfSide1) {
      changeHue = true;
      hueBackground(changeHue);
      Serial.println("true now");
    } else {
      changeHue = false;
      Serial.println("false now");
    }
    LED[i] = CHSV(hueRaindrop(), satRaindrop(), valRaindrop());  //chsv(hue sat val)
    if (i != middleOfSide1) {                                    //avoid coloring the first led of the other side
      LED[i + 1] = CHSV(hue, satBackground(iAtEnd), valBackground(iAtEnd)); //chsv(hue sat val)
    }
    LED[(middleOfSide2 + (middleOfSide1 - i))] = CHSV(hueRaindrop(), satRaindrop(), valRaindrop());    //using i to count the other side,
    if ((middleOfSide2 + (middleOfSide1 - i)) != middleOfSide2) {                                         // avoid coloring the first led of the other side
      LED[(middleOfSide2 + (middleOfSide1 - i)) - 1] = CHSV(hue, satBackground(iAtEnd), valBackground(iAtEnd));
    }
    FastLED.show();
    if (endOfSide1 == middleOfSide1) { //reset iAtEnd and endOfSide1 after display ends when both i and endOfSide1 equal 34
      endOfSide1 = 0;
      iAtEnd = false;
    }
    if (endOfSide1 == 0 && i == 0) { // increase endOfSide1 so the display shows the rain filling the end of the strip. needed to prevent the first led from being dark
      endOfSide1++;
      iAtEnd = true;
    }
    else if (endOfSide1 == i && iAtEnd) { // after i reached 0, when i = endOfSide1+1 increase endOfSide1
      endOfSide1++;
    }
    delay(50);
  }
}
#endif
