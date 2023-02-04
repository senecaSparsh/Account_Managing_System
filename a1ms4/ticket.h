#include "account.h"

#pragma once
#define ticket_h
#ifndef ticket_h

struct Message
{
	char loginname[31];
	char accountHolder[11];
	char message[150];

};

struct ticket
{

	int ticket_no;
	int c_acc_num;
	int acc_status;
	char subject[30];
	int num_message;
	struct Message message[20];
};

#endif // !ticket_h

