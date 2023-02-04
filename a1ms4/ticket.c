#include "accountTicketingUI.h"

void displayListTicketDetail(const Ticket* dispTickets, int sizeOfTicketArray, const Account* accounts, int sizeOfAccountArray, int option)
{
	int exitLoop = 0;
	while (dispTickets != NULL && exitLoop == 0)
	{
		int i = 0;
		int sub_menu_selection = -1;

		displayListTicketHeader();
		while (dispTickets[i].ticketNo != 0 && i < sizeOfTicketArray)
		{
			if (1 == dispTickets[i].statusIndicator && dispTickets[i].counter == 1 && option == 1)

			{
				displayTicketDetail(&dispTickets[i], accounts, sizeOfAccountArray);
			}
			else if (1 == dispTickets[i].statusIndicator && option == 0)
			{
				displayTicketDetail(&dispTickets[i], accounts, sizeOfAccountArray);
			}
			else if (0 == dispTickets[i].statusIndicator && option == -1)
			{
				displayTicketDetail(&dispTickets[i], accounts, sizeOfAccountArray);
			}
			i++;
		}
		printf("------ ----- --------------- ------ ------------------------------ --------\n\n");
		printf("Enter the ticket number to view the messages or\n");
		printf("0 to return to previous menu: ");

		sub_menu_selection = getPositiveInteger();
		int foundTicket = findTicketByNum(sub_menu_selection, dispTickets, sizeOfTicketArray);
		if (sub_menu_selection != 0 && foundTicket > -1)
		{
			printf("\n");
			displayMessageHeader(&dispTickets[foundTicket]);
			displayMessageContent(dispTickets[foundTicket].arrayMessage);
		}
		else if (foundTicket == -1)
		{
			printf("\nERROR: Invalid ticket number.\n\n");
			pauseExecution();
		}
		else
		{
			printf("\n");
			exitLoop = 1;
		}
	}

	return;
}

void displayTicketDetail(const Ticket* dispTicket, const Account* accounts, int sizeOfArray)
{
	int index = findAccountIndexByAcctNum(dispTicket->customerAccountTicket, accounts, sizeOfArray, 0);
	if (index > -1)
	{
		//printf("------ ----- --------------- ------ ------------------------------ --------\n");
		printf("%06d %05d %-15s %-6s %-25s %10d\n", dispTicket->ticketNo, dispTicket->customerAccountTicket, accounts[index].userInfo.customer_account, (dispTicket->statusIndicator == 1) ? "OPEN" : "CLOSED", dispTicket->subjectLine, dispTicket->counter);
	}

	return;
}

void displayListTicketHeader(void)
{
	printf("------ ----- --------------- ------ ------------------------------ --------\n");
	printf("Ticket Acct# Display Name    Status Subject                        Messages\n");
	printf("------ ----- --------------- ------ ------------------------------ --------\n");
	//printf("------ ----- --------------- ------ ------------------------------ --------\n");
	return;
}

void displayMessageHeader(const Ticket* dispTicket)
{

	printf("================================================================================\n");
	printf("%06d (%s) Re: %-25s\n", dispTicket->ticketNo, (dispTicket->statusIndicator == 1) ? "OPEN" : "CLOSED", dispTicket->subjectLine);
	printf("================================================================================\n");
	//printf("------ ----- --------------- ------ ------------------------------ --------\n");
	return;
}

void displayMessageContent(const Message* dispMessage)
{
	int i = 0;
	while (dispMessage != NULL && dispMessage[i].authorAccountType != 0 && i < NUM_MESSAGE_ARRAY)
	{
		printf("%s (%s):\n", dispMessage[i].authorAccountType == 'A' ? "AGENT" : "CUSTOMER", dispMessage[i].dispayName);
		printf("   %-s\n\n", dispMessage[i].message);
		i++;
	}
	pauseExecution();
	return;
}

int findTicketByNum(int ticketNo, const Ticket* tickets, int sizeOfTicketArray)
{
	int i = 0;
	int found = 0;
	int returnValue = -1;
	while (tickets != NULL && 0 == found && i < sizeOfTicketArray)
	{
		if (tickets[i].ticketNo == ticketNo)
		{
			found = 1;
		}
		else
		{
			i++;
		}
	}
	returnValue = (found == 1) ? i : -1;
	return returnValue;
}
void displayClientTicketHeader(void)
{
	printf("Ticket Status Subject                        Messages\n");
	printf("------ ------ ------------------------------ --------\n");
	return;
}

void displayClientTicketList(const Ticket* dispTickets, int sizeOfTicketArray, const Account* clientAccount)
{
	int exitLoop = 0;
	while (dispTickets != NULL && clientAccount != NULL && exitLoop == 0)
	{
		int i = 0;
		int sub_menu_selection = -1;

		displayClientTicketHeader();

		while (dispTickets[i].ticketNo != 0 && i < sizeOfTicketArray)
		{
			if (dispTickets[i].customerAccountTicket == clientAccount->account_num)
			{
				printf("%06d %-6s %-25s %10d\n", dispTickets[i].ticketNo, (dispTickets[i].statusIndicator == 1) ? "OPEN" : "CLOSED", dispTickets[i].subjectLine, dispTickets[i].counter);
			}
			i++;
		}
		printf("------ ------ ------------------------------ --------\n\n");
		printf("Enter the ticket number to view the messages or\n");
		printf("0 to return to previous menu: ");

		sub_menu_selection = getPositiveInteger();
		int foundTicket = findTicketByNum(sub_menu_selection, dispTickets, sizeOfTicketArray);
		if (sub_menu_selection != 0 && foundTicket > -1)
		{
			printf("\n");
			displayMessageHeader(&dispTickets[foundTicket]);
			displayMessageContent(dispTickets[foundTicket].arrayMessage);
		}
		else if (foundTicket == -1)
		{
			printf("\nERROR: Invalid ticket number.\n\n");
			pauseExecution();
		}
		else
		{
			printf("\n");
			exitLoop = 1;
		}
	}
	return;
}