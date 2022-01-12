#ifndef A_HEADER
#define A_HEADER

#include <FastLED.h>

#define Apin1 A6
#define Apin2 A7
//#define Dpin1 5
#define Dpin2 4
#define PL 5                           // LED pin
#define BUTTON_PIN 2                   // Interrupt button to switch mods
#define MIN_VAL 0                      //min CRGB val for LEDs
#define MAX_VAL 255                    //max CRGB val for LEDs
#define STRIP 70                       //num LED in strip
#define LEDTYPE WS2812B                //when changing strips
#define H_MINUTE (millis() / 30000)    //grows by 1 every half minute as long as its an int 
#define TEN_MINUTES 600000             //ten min in millisecs
#define GROUP_SIZE 2                   //size of groups in modes lagune and embers


//mode names
#define MODE_START 0
#define LAGUNE 1
#define EMBERS 2
#define RAINFALL 3
//#define MUSIC 4

//button variables
volatile bool buttonFlag;
long flagTime = 0;
int debounceTime = 300;
//int mode = 0;

//led variables
uint8_t hue = 0;
uint8_t sat = 255;
uint8_t val = 0;
bool hueup = true;
CRGB LED[STRIP]; //color information of each individual led in the strip
CHSV led = CHSV(hue, sat, val); //color informatin in chsv
unsigned int colorSetIndex = 0;                                                                     //static colors in the middle
int mode = RAINFALL;//MODE_START;
bool up = true;
bool alreadySet = false;                        //intializes MUSIC mode, done only once
bool even;

//LAGUNE and EMBERS variables
int led_groups_counter = ((STRIP / GROUP_SIZE )); //counts the number of led groups in mode lagune
int current_group = 0;
int last_group = 0;
int led_index = 0;
int groupShifter = 0; //the group shifter is sent to the laguneRangeSet function. and is changed inside waves function
int num_lagune_cases = 26;
int num_embers_cases = 12;
bool wave_valup = true;
long modeTimer = 0; //sets timer for when the mode was changed


#endif
