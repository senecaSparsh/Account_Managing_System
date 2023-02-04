
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "account.h"
#include "accountTicketingUI.h"
#include "commonHelpers.h"


void displayAccountSummaryHeader(void)
{
    printf("Acct# Acct.Type Birth\n");
    printf("----- --------- -----\n");

}

void displayAccountDetailHeader(void)
{
    printf("Acct# Acct.Type Birth Income      Country    Disp.Name       Login      Password\n");
    printf("----- --------- ----- ----------- ---------- --------------- ---------- --------\n");

}

void displayAccountSummaryRecord(struct Account* account)
{
    char AGENT[6] = "AGENT";
    char CUSTOMER[10] = "CUSTOMER";
    // Give this formatting to the student


    if (account->acctype == 'A')
    {
        printf("%05d %-9s %5d", account->accnum, AGENT, account->demo.birthyear);
        printf("\n");
    }
    else
    {
        printf("%05d %-9s %5d", account->accnum, CUSTOMER, account->demo.birthyear);
        printf("\n");
    }


}


void displayAccountDetailRecord(struct Account* account)
{
    char AGENT[6] = "AGENT";
    char CUSTOMER[10] = "CUSTOMER";
    // Give this formatting to the student
    account->login.passward[1] = '*';
    account->login.passward[3] = '*';
    account->login.passward[5] = '*';
    account->login.passward[7] = '*';

    if (account->acctype == 'A')
    {
        printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %8s", account->accnum, AGENT, account->demo.birthyear, account->demo.income, account->demo.country, account->login.loginname, account->login.accountHolder, account->login.passward);
        printf("\n");
    }
    else
    {
        printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %8s", account->accnum, CUSTOMER, account->demo.birthyear, account->demo.income, account->demo.country, account->login.loginname, account->login.accountHolder, account->login.passward);
        printf("\n");
    }

}

void applicationStartup(struct  AccountTicketingData* data)
{
    int i = 0, flag = 0, b=0;
    do
    {
        i = menuLogin(data->accounts, data->ACCOUNT_MAX_SIZE);

        if (data->accounts[i].acctype == 'A')
        {
            printf("\n");
            menuAgent(&data, &data->accounts[i]);
            
        }
        else if (data->accounts[i].acctype == 'C')
        {
            printf("\n");
            printf("CUSTOMER: home menu currently unavailable…\n");
            printf("\n");
            pauseExecution();
            flag = 0;
        }
        else if (i == -1)
        {
            flag = 1;
        }
    } while (flag == 0 );

}

int menuLogin(struct Account acc[], int maxNum)
{
    int i=0, a = 0,b = 0, flag = 0, d =0, c=0;
    char enter[10] = { 0 };
    do
    {
        i = 0;
        a = 0;
        b = 0;
        d = 0;
        c = 0;
       
        flag = 0;
        char enter[10] = { 0 };
        printf("==============================================\n");
        printf("Account Ticketing System - Login\n");
        printf("==============================================\n");
        printf("1) Login to the system\n");
        printf("0) Exit application\n");
        printf("----------------------------------------------\n");
        printf("\n");
    
    
        printf("Selection: ");
        i = getIntFromRange(0, 1);
        printf("\n");
       

        if (i == 1)
        {
            printf("Enter your account#: ");
            d = getInteger();

            for (b = 0; b < maxNum; b++)
            {
                if (d == acc[b].accnum)
                {
                    c = b;
                    a = 1;

                }
            }
           
            if ( a != 1)
            {
                printf("\n");
                printf("ERROR:  Access Denied.\n");
                printf("\n");
                pauseExecution();
            }
            else
            {
                
                flag = 1;
            }
        }
        else if (i == 0)
        {
            printf("Are you sure you want to exit? ([Y]es|[N]o): ");
            enter[0] = getCharOption("yYnN");
            printf("\n");
            if (enter[0] == 'y' || enter[0] == 'Y')
            {
                printf("==============================================\n");
                printf("Account Ticketing System - Terminated\n");
                printf("==============================================\n");
                flag = 1;
                c = -1;
            }
            else if (enter[0] == 'n' || enter[0] == 'N')
            {

                flag = 0;
                
            }
        }

    } while (flag == 0);

    return c;
}

void menuAgent(struct  AccountTicketingData* data, struct Account* account)
{
    char enter[10] = { 0 };
    
    int flag = 0, flag1 = 0;;
    do
    {
        int i = 0, a = 0, b = 0, c = 0,d = 0, flag1 = 0,max = 0;
      
        printf("AGENT: %s (%d)\n", account->login.loginname, account->accnum);
        printf("==============================================\n");
        printf("Account Ticketing System - Agent Menu\n");
        printf("==============================================\n");
        printf("1) Add a new account\n");
        printf("2) Modify an existing account\n");
        printf("3) Remove an account\n");
        printf("4) List accounts: summary view\n");
        printf("5) List accounts: detailed view\n");
        printf("----------------------------------------------\n");
        printf("6) List new tickets\n");
        printf("7) List active tickets\n");
        printf("8) Manage a ticket\n");
        printf("9) Archive closed tickets\n");
        printf("----------------------------------------------\n");
        printf("0) Logout\n");
        printf("\n");
        printf("Selection: ");
        i = getIntFromRange(0, 5);
        printf("\n");
        if (i == 1)
        {
            for (b = 0; b < data->ACCOUNT_MAX_SIZE && flag1 == 0; b++)
            {
                if (data->accounts[b].accnum == 0)
                {
                    c = b;
                    flag1 = 1;
                }
            }
            max = data->accounts[0].accnum;
            for (b = 0; b < data->ACCOUNT_MAX_SIZE && flag1 == 0; b++)
            {
                if (data->accounts[b].accnum > max)
                {
                    max = data->accounts[b].accnum;
                }
             

            }
            if (flag1 == 1)
            {
                
                getAccount(&data->accounts[c], max);

                getUserLogin(&data->accounts[c].login);

                getDemographic(&data->accounts[c].demo);

                printf("*** New account added! ***\n");
                printf("\n");
                pauseExecution();
                
                
            }
            else if (flag1 == 0)
            {
                printf("ERROR: Account listing is FULL, call ITS Support!\n");
            }
        }
        else if (i == 2)
        {
            d = 0;
            d = findAccountIndexByAcctNum(account->accnum, data->accounts, data->ACCOUNT_MAX_SIZE, 2);

            if (d == -1)
            {

                printf("ERROR: Access Denied.\n");
                printf("\n");

            }
            else if (d != -1)
            {

                updateAccount(&data->accounts[d]);
            }

        }
        else if (i == 3)
        {
            char ba = 0;
            printf("Enter your account#: ");
            d = getInteger();
            if (d == account->accnum)
            {
                printf("\n");
                printf("ERROR: You can't remove your own account!\n");
                printf("\n");
                pauseExecution();

            }
            else
            {
                d = findAccountIndexByAcctNum(d, data->accounts, data->ACCOUNT_MAX_SIZE, 0);
                displayAccountDetailHeader();
                displayAccountDetailRecord(&data->accounts[d]);
                printf("\n");
                printf("Are you sure you want to remove this record? ([Y]es|[N]o): ");
                ba = getCharOption("YN");
                if (ba == 'N')
                {
                    printf("\n");
                    printf("*** No changes made! ***\n");
                    printf("\n");
                    pauseExecution();

                }
                else 
                {
                  
                    data->accounts[d].accnum = 0;
                    data->accounts[d].acctype = 0;
                    data->accounts[d].demo.birthyear = 0;
                    data->accounts[d].demo.income = 0;
                    for (i = 0; i < 30; i++)
                    {
                        data->accounts[d].demo.country[i] = 0;
                    }
                    for (i = 0; i < 10; i++)
                    {
                        data->accounts[d].login.accountHolder[i] = 0;
                    }
                    for (i = 0; i < 30; i++)
                    {
                        data->accounts[d].login.loginname[i] = 0;
                    }
                    for (i = 0; i < 8; i++)
                    {
                        data->accounts[d].login.passward[i] = 0;
                    }
                    printf("\n");
                    printf("*** Account Removed! ***\n");
                    printf("\n");

                    pauseExecution();

                }
              
            }
        }
        else if (i == 4)
        {
        displayAllAccountSummaryRecords(data->accounts, data->ACCOUNT_MAX_SIZE);
        }
        else if (i == 5)
        {
        displayAllAccountDetailRecords(data->accounts, data->ACCOUNT_MAX_SIZE);
        }
        else if (i == 0)
        {
        printf("\n");
        printf("### LOGGED OUT ###\n");
        printf("\n");

        flag = 1;

        }
    } while (flag == 0);
    return;

}



int findAccountIndexByAcctNum(int accNum, struct Account acc[], int maxNum, int i)
{
    int a = 0, b = 0, c = 0, d = 0, flag= 0;
    if (i == 0)
    {
      
        for (b = 0; b < maxNum; b++)
        {
            if (accNum == acc[b].accnum)
            {
                c = b;
                a = 1;

            }
        }
        if (a == 0)
        {
            c = -1;
        }
    }
    else
    {
         
         printf("Enter your account#: ");
         d = getInteger();

         for (b = 0; b < maxNum; b++)
         {
             if (d == acc[b].accnum)
             {
                 c = b;
                 a = 1;

             }
         }
         if (a == 0)
         {

             c = -1;

         }
    }
    return c;
}

void displayAllAccountSummaryRecords(struct Account acc[], int maxNum)
{ 
    int i = 0;
    displayAccountSummaryHeader();

    for (i = 0; i < maxNum; i++)
    {
        if (acc[i].accnum != 0)
        {
            displayAccountSummaryRecord(&acc[i]);
        }

    }
    printf("\n");
    pauseExecution();
    /*printf("Acct# Acct.Type Birth\n");
    printf("----- --------- -----\n");
    int i = 0;
    char AGENT[6] = "AGENT";
    char CUSTOMER[10] = "CUSTOMER";
    // Give this formatting to the student

    for (i = 0; i < maxNum; i++)
    {
        if (acc[i].acctype == 'A')
        {
            printf("%05d %-9s %5d", acc[i].accnum, AGENT, acc[i].demo.birthyear);
            printf("\n");
        }
        else
        {
            printf("%05d %-9s %5d", acc[i].accnum, CUSTOMER, acc[i].demo.birthyear);
            printf("\n");
        }
    }*/
}

void displayAllAccountDetailRecords(struct Account acc[], int maxNum)
{
    int i = 0;
    displayAccountDetailHeader();

    for (i = 0; i < maxNum; i++)
    {
        if (acc[i].accnum != 0)
        {
            displayAccountDetailRecord(&acc[i]);
        }
    }
    printf("\n");
    pauseExecution();

}

void pauseExecution(void)
{
    printf("<< ENTER key to Continue... >> ");
    clearStanadardInputBuffer();
    putchar('\n');
}