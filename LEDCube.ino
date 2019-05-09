#include "Macro.h"
// Definition of interrupt names
#include <avr/io.h>

volatile int Button_1_Reading;
volatile int Button_2_Reading;
volatile int Button_3_Reading;
volatile int Button_4_Reading;
volatile int Button_5_Reading;
volatile int Box_Value = 1;
volatile char Axis_Value = XAxis;

void setup()
{
  // put your setup code here, to run once:
  InitDisplay();
  InitButtons();
  ClearCube();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(Button_1_Reading)
  {
    while(Button_1_Reading)
    {
      Box(Box_Value);
    }
    ClearCube();
    delay(50);
  }
  else if(Button_2_Reading)
  {
    Rain(10);
    ClearCube();
    delay(50);
  }
  else if(Button_3_Reading)
  {
    while(Button_3_Reading)
    {
      Spiral(Axis_Value, 10);
    }
    ClearCube();
    delay(50);
  }
  else if(Button_4_Reading)
  {
    SineWave(10);
    ClearCube();
    delay(50);
  }
  else if(Button_5_Reading)
  {
    Function_5(10);
    delay(50);
  }
  
}
