#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "commonHelpers.h"
#include <time.h>
// Uses the time.h library to obtain current year information
// Get the current 4-digit year from the system
int currentYear(void)
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}

// Empty the standard input buffer
void clearStanadardInputBuffer(void)
{
	while (getchar() != '\n')
	{
		; // On purpose: do nothing
	}
}

int getInteger(void)
{

	int value;
	char newline = 'x';
	int flag = 1;

	do
	{
		scanf("%d%c", &value, &newline);
		if (newline == '\n')
		{

			flag = 0;
		}
		else
		{
			clearStanadardInputBuffer();
			printf("ERROR: Value must be an integer: ");

		}
	} while (flag == 1);
	return value;

}


int getPositiveInteger(void)
{

	int value;
	char newline = 'x';
	int flag = 1;

	do
	{
		scanf("%d%c", &value, &newline);
		if (newline == '\n')
		{
			if (value <= 0)
			{
				printf("ERROR: Value must be a positive integer greater than zero: ");
			}
			else if (value > 0)
			{
				flag = 0;
			}

		}
		else
		{
			clearStanadardInputBuffer();
			printf("ERROR: Value must be an integer: ");

		}
	} while (flag == 1);
	return value;

}

int  getIntFromRange(int lownum, int uppernum)
{
	int value;
	char newline = 'x';
	int flag = 1;

	do
	{
		value = 0;
		newline = 'x';
		flag = 1;
		scanf("%d%c", &value, &newline);
		
		if (newline == '\n')
		{
			if (value < lownum || value > uppernum)
			{
				
				printf("ERROR: Value must be between %d and %d inclusive: ", lownum, uppernum);

			}
			else if (value >= lownum || value <= uppernum)
			{
				flag = 0;
			}
		}
		else
		{
			clearStanadardInputBuffer();
			printf("ERROR: Value must be an integer: ");

		}

	} while (flag == 1);
	return value;

}

double getDouble(void)
{
	double value;
	char newline = 'x';
	int flag = 1;

	do
	{
		scanf("%lf%c", &value, &newline);
		if (newline == '\n')
		{
			flag = 0;
		}
		else
		{
			clearStanadardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");

		}
	} while (flag == 1);
	return value;
}

double getPositiveDouble(void)
{
	double value;
	char newline = 'x';
	int flag = 1;

	do
	{
		scanf("%lf%c", &value, &newline);
		if (newline == '\n')
		{
			if (value <= 0.0)
			{
				printf("ERROR: Value must be a positive double floating-point number: ");

			}
			else
			{
				flag = 0;
			}
		}
		else
		{
			clearStanadardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");

		}
	} while (flag == 1);
	return value;

}

char getCharOption(const char string[])
{
	char a[10] = { 0 };
	int i, c = 0;
	int flag = 1;

	do
	{
		scanf("%10s", a);
		clearStanadardInputBuffer();

		c = 0;
		for (i = 0; a[i] != '\0'; i++)
		{
			c = c + 1;
		}
		if (c > 1)
		{
			printf("ERROR: Character must be one of [");

			printf("%s", string);

			printf("]: ");
		}
		else
		{
			for (i = 0; string[i] != '\0' && flag == 1; i++)
			{

				if (a[0] == string[i])
				{
					flag = 0;
				}
			}
			if (flag != 0)
			{
				printf("ERROR: Character must be one of [");

				printf("%s", string);

				printf("]: ");
			}

		}

	} while (flag == 1);
	return a[0];
}

void getCString(char string[], int minchar, int maxchar)
{
	int i = 0, b = 0, c = 0;
	char a[150] = { 0 };
	int flag = 1;
	do
	{

		scanf("%150[^\n]", a);
		clearStanadardInputBuffer();

		c = 0;
		for (i = 0; a[i] != '\0'; i++)
		{
			c = c + 1;
		}

		if (c >= minchar && c <= maxchar)
		{
			for (b = 0; b < c + 1; b++)
			{
				string[b] = a[b];
			}
			flag = 0;
		}

		else if ((c < minchar || c > maxchar) && (maxchar == minchar))
		{

			printf("ERROR: String length must be exactly %d chars: ", maxchar);
			flag = 1;

		}
		else if ((c > maxchar) && (maxchar != minchar))
		{

			printf("ERROR: String length must be no more than %d chars: ", maxchar);
			flag = 1;
		}
		else
		{

			printf("ERROR: String length must be between %d and %d chars: ", minchar, maxchar);
			flag = 1;
		}

	} while (flag == 1);

	return;
}

