//Contains Initilization code
#include <TimerOne.h>

void InitDisplay()
{
  //Set up timer for interrupt code to go off of
  Timer1.initialize(10000); //Happening every 10ms/.01s
  Timer1.attachInterrupt(Update);
  return;
}

void InitButtons()
{
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  pinMode(BUTTON_4, INPUT_PULLUP);
  pinMode(BUTTON_5, INPUT_PULLUP);
  Add_Pin_Change_Interrupts();
  return;
}



