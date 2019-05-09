//These will have common functions to change display
#include "Arduino.h"

//Globals
volatile unsigned char Leds[SIZEOFCUBE][SIZEOFCUBE][SIZEOFCUBE];
volatile unsigned int LayerNum = 0;

//Updates the Display - Change to interrupt happen every .01 sec
void Update()
{
  //cycle through layers and change arrays

  //Turns off current Layer
  Layers(LayerNum-1, LOW);

  //cycle through array assigning values
  for(int x = 0; x < SIZEOFCUBE; x++)
  {
    for(int y = 0; y < SIZEOFCUBE; y++)
    {
      if(y < 2)
      {
        //SR2
        ShiftRegister(SR2, Leds[x][y][LayerNum]);
      }
      else
      {
        //SR1
        ShiftRegister(SR1, Leds[x][y][LayerNum]);
      }
    }
  }

  Latch(SR1);
  Latch(SR2);
  Layers(LayerNum, HIGH);
  LayerNum++;
  
  //Resets the layers once gone fully through
  if (LayerNum == 4)
  {
    LayerNum = 0;
  }
  
  return;
}

void Layers(unsigned int LayerNum, int Value)
{
  digitalWrite(LAYERONEPIN, LOW);
  digitalWrite(LAYERTWOPIN, LOW);
  digitalWrite(LAYERTHREEPIN, LOW);
  digitalWrite(LAYERFOURPIN, LOW);
  switch (LayerNum)
  {
    case LAYER1:
    digitalWrite(LAYERONEPIN, Value);
    break;

    case LAYER2:
    digitalWrite(LAYERTWOPIN, Value);
    break;

    case LAYER3:
    digitalWrite(LAYERTHREEPIN, Value);
    break;

    case LAYER4:
    digitalWrite(LAYERFOURPIN, Value);
    break;
  }
}

void ShiftRegister(unsigned int Number, unsigned int Value)
{
  switch(Number)
  {
    case SR1:
    //Write Data
    digitalWrite(DATA1, Value);

    //Change Clock
    digitalWrite(CLK1, HIGH);
    digitalWrite(CLK1, LOW);

    digitalWrite(DATA1, LOW);
    break;

    case SR2:
    //Write Data
    digitalWrite(DATA2, Value);

    //Change Clock
    digitalWrite(CLK2, HIGH);
    digitalWrite(CLK2, LOW);

    digitalWrite(DATA2, LOW);
    break;
  }
  return;
}

void Latch(unsigned int Number)
{
  if(Number == SR1)
  {
    digitalWrite(LATCH1, HIGH);
    digitalWrite(LATCH1, LOW);
  }
  else
  {
    digitalWrite(LATCH2, HIGH);
    digitalWrite(LATCH2, LOW);
  }
  return;
}




