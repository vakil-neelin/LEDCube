//Includes all the used function delcarations

void InitDisplay();

//Display.c - update display
void Layers(unsigned int LayerNum, int Value);
void Update();
void ShiftRegister(unsigned int Number, unsigned int Value);
void Latch(unsigned int Number);

//Draw.c - drawing functions
void plot(unsigned int X, unsigned int Y, unsigned int Z, unsigned int n);
void plotFill(unsigned int X1, unsigned int X2, unsigned int Y1, unsigned int Y2, unsigned int Z1, unsigned int Z2, unsigned int n);
void ClearCube();
void plotDepth(unsigned int X, unsigned int Z, unsigned int n);
void plotVertical(unsigned int X, unsigned int Y, unsigned int n);
void plotHorizantal(unsigned int Y, unsigned int Z, unsigned int n);

//Functions.c - Draw patterns
void Box(int Size);
void Rain(unsigned int Speed);
void Spiral(char Axis, unsigned int Speed, unsigned int Times);
void SineWave(unsigned int Speed, unsigned int Times);
