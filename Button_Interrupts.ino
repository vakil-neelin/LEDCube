//================================================================================
// PCINT Definitions
//================================================================================
// ISR interrupt service routine
#include <avr/interrupt.h>

void Add_Pin_Change_Interrupts()
{
  cli();
  PCICR |= 0b00000001;    // turn on port b
  PCMSK0 |= 0b00000001;    // turn on pin PB0, which is PCINT0, physical pin 12
  PCMSK0 |= 0b00000010;    // turn on pin PB1, which is PCINT1, physical pin 13
  PCMSK0 |= 0b00000100;    // turn on pin PB2, which is PCINT2, physical pin 14
  PCMSK0 |= 0b00001000;    // turn on pin PB3, which is PCINT3, physical pin 15
  PCMSK0 |= 0b00010000;    // turn on pin PB4, which is PCINT4, physical pin 16
  sei();
}

ISR(PCINT0_vect){ // Port B, PCINT0 - PCINT7
  //Buttons have pull-up resistors
  //Connect to ground
  //Pressed equals zero value
  if(!digitalRead(BUTTON_1))
  {
    if(Button_1_Reading && Box_Value == 1)
    {
      Box_Value = 2;
    }
    else if(Button_1_Reading && Box_Value == 2)
    {
      Box_Value = 1;
    }
    Button_1_Reading = 1;
    Button_2_Reading = 0;
    Button_3_Reading = 0;
    Button_4_Reading = 0;
    Button_5_Reading = 0;
  }
  else if(!digitalRead(BUTTON_2))
  {
    Button_1_Reading = 0;
    Button_2_Reading = 1;
    Button_3_Reading = 0;
    Button_4_Reading = 0;
    Button_5_Reading = 0;
  }
  else if(!digitalRead(BUTTON_3))
  {
    if(Button_3_Reading)
    {
      if(Axis_Value == XAxis)
      {
        Axis_Value = YAxis;
      }
      else if(Axis_Value == YAxis)
      {
        Axis_Value = ZAxis;
      }
      else if(Axis_Value == ZAxis)
      {
        Axis_Value = XAxis;
      }
    }
    Button_1_Reading = 0;
    Button_2_Reading = 0;
    Button_3_Reading = 1;
    Button_4_Reading = 0;
    Button_5_Reading = 0;
  }
  else if(!digitalRead(BUTTON_4))
  {
    Button_1_Reading = 0;
    Button_2_Reading = 0;
    Button_3_Reading = 0;
    Button_4_Reading = 1;
    Button_5_Reading = 0;
  }
  else if(!digitalRead(BUTTON_5))
  {
    Button_1_Reading = 0;
    Button_2_Reading = 0;
    Button_3_Reading = 0;
    Button_4_Reading = 0;
    Button_5_Reading = 1;
  }
  return;
}    
