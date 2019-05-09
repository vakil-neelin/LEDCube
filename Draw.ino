/*This file will contain all the code used to illuminate different LEDs*/
#include "Arduino.h"

//Globals
extern volatile unsigned char Leds[SIZEOFCUBE][SIZEOFCUBE][SIZEOFCUBE];

//Plots single point at X, Y, Z with value of n
void plot(unsigned int X, unsigned int Y, unsigned int Z, unsigned int n)
{
  Leds[X][Y][Z] = n;
  return;
}

//Fills area with value n
void plotFill(unsigned int X1, unsigned int X2, unsigned int Y1, unsigned int Y2, unsigned int Z1, unsigned int Z2, unsigned int n)
{
  unsigned int test = 0;
  //Check if values are in correct order
  if(X1 > X2)
  {
    test = X1;
    X1 = X2;
    X2 = test;
  }

  if(Y1 > Y2)
  {
    test = Y1;
    Y1 = Y2;
    Y2 = test;
  }

  if(Z1 > Z2)
  {
    test = Z1;
    Z1 = Z2;
    Z2 = test;
  }

  //Plot values
  for(int x = X1; x < X2; x++)
  {
    for(int y = Y1; y < Y2; y++)
    {
      for(int z = Z1; z < Z2; z++)
      {
        plot(x, y, z, n);
      }
    }
  }
  
  return;
}

void ClearCube()
{
  plotFill(0,0,0,3,3,3,0);
}

//Plots horizantal line at Y, Z
void plotHorizantal(unsigned int Y, unsigned int Z, unsigned int n)
{
  for(int X = 0; X < SIZEOFCUBE; X++)
  {
    plot(X, Y, Z, n);
  }
  return;
}

//Plots vertical line at X, Y
void plotVertical(unsigned int X, unsigned int Y, unsigned int n)
{
  for(int Z = 0; Z < SIZEOFCUBE; Z++)
  {
    plot(X, Y, Z, n);
  }
  return;
}

//Plots depth line at X, Z
void plotDepth(unsigned int X, unsigned int Z, unsigned int n)
{
  for(int Y = 0; Y < SIZEOFCUBE; Y++)
  {
    plot(X, Y, Z, n);
  }
  return;
}


