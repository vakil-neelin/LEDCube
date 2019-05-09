//Functions that will be called to draw patterns

#include "Arduino.h"

//Globals
extern volatile unsigned char Leds[SIZEOFCUBE][SIZEOFCUBE][SIZEOFCUBE];

//Draws a wire box
void Box(int Size)
{
  switch(Size)
  {
    //Outside Box
    case 1:
    plotFill(0, 0, 0, 3, 3, 3, 1);
    plotFill(0, 1, 1, 3, 2, 2, 0);
    plotFill(1, 0, 1, 2, 3, 2, 0);
    plotFill(1, 1, 0, 2, 2, 3, 0);
    break;
    
    //Both Boxes
    case 2:
    //Outer
    plotFill(0, 0, 0, 3, 3, 3, 1);
    plotFill(0, 1, 1, 3, 2, 2, 0);
    plotFill(1, 0, 1, 2, 3, 2, 0);
    plotFill(1, 1, 0, 2, 2, 3, 0);
    
    //Inner
    plotFill(1, 1, 1, 2, 2, 2, 1);
    
    break;
  }
  return;
}

//Creates Rain falling in the cube
void Rain(unsigned int Speed)
{
  unsigned int Drops[4][3];

  //Add first four drops
  for(int i = 0; i<4;i++)
    {
        //Calculate new drop location
        int newPosition = random(16);
        int x = newPosition * .25;
        int y = newPosition % 4;
        //Write over old value
        Drops[i][0] = x;
        Drops[i][1] = y;
        Drops[i][2] = 3;

        for(int j = 0; j<i;j++)
        {
          //Moves previous drops down a level
          Drops[j][2]--;
        }
      //Plot new drop
      plot(Drops[i][0],Drops[i][1],Drops[i][2], 1);
      delay(Speed);
    }  

  //Continuous Rain Fall
  while(Button_2_Reading)
  {
    for(int i = 0; i<4;i++)
    {
      //Remove old drop
      plot(Drops[i][0],Drops[i][1],Drops[i][2], 0);
  
      //See if drop hit bottom
      if(Drops[i][2] == 0)
      {
        //Calculate new drop location
        int newPosition = random(16);
        int x = newPosition * .25;
        int y = newPosition % 4;
        //Write over old value
        Drops[i][0] = x;
        Drops[i][1] = y;
        Drops[i][2] = 3;
      }
      else
      {
        Drops[i][2]--;
      }
      //Plot new drop
      plot(Drops[i][0],Drops[i][1],Drops[i][2], 1);
    }
    delay(Speed);
  }
  
  return;
}

//Creates spinning Spiral around a certain axis
void Spiral(char Axis, unsigned int Speed)
{
  unsigned const int Spoints[8][8] = { {0,3,1,2,2,1,3,0},
                                 {0,1,1,1,2,1,3,1},
                                 {0,0,1,1,2,2,3,3},
                                 {2,0,2,1,2,2,2,3},
                                 {0,3,1,2,2,1,3,0},
                                 {0,2,1,2,2,2,3,2},
                                 {0,0,1,1,2,2,3,3},
                                 {1,0,1,1,1,2,1,3}
                                };
  
  switch(Axis)
  {
    case XAxis:
    //Move through cube and plots points
    for(int i = 0; i < 8; i++)
    {
      //Clear Cube
      ClearCube();
      //Plot new points
      plotHorizantal(Spoints[i][0], Spoints[i][1], 1);
      plotHorizantal(Spoints[i][2], Spoints[i][3], 1);
      plotHorizantal(Spoints[i][4], Spoints[i][5], 1);
      plotHorizantal(Spoints[i][6], Spoints[i][7], 1);
      //Sleep speed
      delay(Speed);
    }
    break;

    case YAxis:
    //Move through cube and plots points
    for(int i = 0; i < 8; i++)
    {
      //Clear Cube
      ClearCube();
      //Plot new points
      plotDepth(Spoints[i][0], Spoints[i][1], 1);
      plotDepth(Spoints[i][2], Spoints[i][3], 1);
      plotDepth(Spoints[i][4], Spoints[i][5], 1);
      plotDepth(Spoints[i][6], Spoints[i][7], 1);
      //Sleep speed
      delay(Speed);
    }
    break;

    case ZAxis:
    //Move through cube and plots points
    for(int i = 0; i < 8; i++)
    {
      //Clear Cube
      ClearCube();
      //Plot new points
      plotVertical(Spoints[i][0], Spoints[i][1], 1);
      plotVertical(Spoints[i][2], Spoints[i][3], 1);
      plotVertical(Spoints[i][4], Spoints[i][5], 1);
      plotVertical(Spoints[i][6], Spoints[i][7], 1);
      //Sleep speed
      delay(Speed);
     }
    break;
  }
  return;
}

void SineWave(unsigned int Speed)
{
  unsigned const int Points[6][4][2] = { {{3,3},{2,2},{1,1},{0,0}},
                                      {{2,2},{1,1},{0,0},{1,1}},
                                      {{1,1},{0,0},{1,1},{2,2}},
                                      {{0,0},{1,1},{2,2},{3,3}},
                                      {{1,1},{2,2},{3,3},{2,2}},
                                      {{2,2},{3,3},{2,2},{1,1}} 
                                    };

  //Happen T Times
  while(Button_4_Reading)
  {
    //Cycle through points array plotting each
    for(int i=0;i<6;i++)
    {
      //Clear Cube
      ClearCube();
      //Plot new points
      plotDepth(Points[i][0][0], Points[i][0][1], 1);
      plotDepth(Points[i][1][0], Points[i][1][1], 1);
      plotDepth(Points[i][2][0], Points[i][2][1], 1);
      plotDepth(Points[i][3][0], Points[i][3][1], 1);
      delay(Speed);
    }
  }
  return;
}

void Function_5(unsigned int Speed)
{
  //Make another function
  delay(Speed);
  return;
}

