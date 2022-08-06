//RS485 setting
#define TXControl 53
#include <SPI.h>


//Machine pins

  #define PXSENSOR_UP 34
  #define PXSENSOR_DOWN 32
  #define PXSENSOR_OVERLOAD 30

  #define GAFFE_RAMP 26
  #define GATE_RAMP 28

  #define ENGINE_RIGHT 31
  #define ENGINE_LEFT 29
  #define ENGINE_SLOW 27

  //LED pins
  #define LED_START 11
  #define LED_ERROR 12
  #define LED_CARD 13



  //Engine settings
  #define OVERLOAD 200
  #define ENGINEDOWN 500
  #define ENGINESLOWDOWN 1900

//Timings and global variables
  int lockMAG=0;
  int brightness = 80;
  int waitUp = 1800;
  int lowering = 3000;
  int accelleration = 3000;
  int lightTime = 55;
  int callEmployee;
  int overloadCounter;
  int fallenCounter = 0;
  bool isFirst = true;
  int ret;
  int resendCounter = 0;

  int PXSENSOR[9] = {52, 50, 48, 46, 44, 42, 40, 38, 36};
  int MAG[9] = {51, 49, 47, 45, 43, 41, 39, 37,35}; // treba magnet pripojit na pi 25 z pinu 37
  int LED[9] = {2,3,4, 5, 6, 7, 8, 9, 10};




