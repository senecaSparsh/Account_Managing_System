#pragma once
#include <stdio.h>
#include "commonHelpers.h"
#ifndef header_h
#define header_h

struct Demographic
{
	int birthyear;
	double income;
	char country[30];

};

struct UserLogin
{
	char loginname[31];
	char accountHolder[11];
	char passward[9];
};

struct Account
{
	int accnum;
	char acctype;
	struct UserLogin login;
	struct Demographic demo;
};

void getAccount(struct Account* acc);

void getUserLogin(struct UserLogin* info);

void getDemographic(struct Demographic* demo);

void updateAccount(struct Account* acc);

void updateUserLogin(struct UserLogin* login);

void updateDemographic(struct  Demographic* demo);

#endif // !header_h



