#pragma once
#include <string.h>
#include "account.h"
#include "ticket.h"
#ifndef account_h
#define account_h

void displayAccountSummaryHeader(void);

void displayAccountSummaryRecord(struct Account* account);

void displayAccountDetailHeader(void);

void displayAccountDetailRecord(struct Account* account);

void applicationStartup(struct  AccountTicketingData* data);

int menuLogin(struct Account acc[], int maxNum);

void  menuAgent(struct  AccountTicketingData* data, struct Account* account);

int findAccountIndexByAcctNum(int accNum, struct Account acc[], int maxNum, int i);

void displayAllAccountSummaryRecords(struct Account acc[], int maxNum);

void displayAllAccountDetailRecords(struct Account acc[], int maxNum);

void pauseExecution(void);

struct AccountTicketingData
{
	struct Account* accounts; // array of accounts 
	const int ACCOUNT_MAX_SIZE; // maximum elements for account array
	
	struct Ticket* tickets; // array of tickets
	const int TICKET_MAX_SIZE; // maximum elements for ticket array 
};

#endif // !account_h

