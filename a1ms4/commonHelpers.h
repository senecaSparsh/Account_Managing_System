#pragma once
#include <stdio.h>
#include <time.h>
#ifndef header
#define header

int currentYear(void);
void clearStanadardInputBuffer(void);


int getInteger(void);

int getPositiveInteger(void);

double getDouble(void);

double getPositiveDouble(void);

int  getIntFromRange(int lownum, int uppernum);

char getCharOption(const char string[]);

void getCString(char string[], int minchar, int maxchar);

#endif // !header

