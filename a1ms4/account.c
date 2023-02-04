#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "account.h"
#include "commonHelpers.h"
#include "accountTicketingUI.h"

void getAccount(struct Account* acc, int max)
{

    printf("New Account Data (Account#:%d)\n",max+1);
    acc->accnum = max + 1;
    printf("----------------------------------------\n");
    printf("Enter the account type (A=Agent | C=Customer): ");
    acc->acctype = getCharOption("AC");
    printf("\n");

}

void getUserLogin(struct UserLogin* info)
{

    int valid = 0;
    int IsSpace = 0;
    int i = 0;
    int counter = 0;
    char strtemp[15 + 1] = { 0 };
    printf("User Login Data Input\n");
    printf("----------------------------------------\n");
    int c = 0, i = 0;
    while (!valid)
    {
        printf("Enter user login(10 chars max) : ");
       
        getCString(strtemp, 1, 15);
        i = 0;
        IsSpace = 0;
        counter = 0;
        while (strtemp[i] != 0 && IsSpace != 1)
        {
            if (strtemp[i] == ' ')
            {
                IsSpace = 1;
            }
            else
            {
                counter++;
                i++;
            }
        }
        if (1 == IsSpace)
        {
            printf("ERROR:  The user login must NOT contain whitespace characters.\n");
        }
        else
        {
            valid = 1;
        }
    }

    for (i = 0; i <= counter; i++)
    {
        info->accountHolder[i] = strtemp[i];
    }


    printf("Enter the display name (30 chars max): ");
    getCString(info->loginname, 1, 30);


    printf("Enter the password (must be %d chars in length): ", 8);
    char strtemp[15 + 1] = { 0 };
    int hasSpecialChar = 0;
    int hasNumber = 0;
    int hasUpper = 0;
    int hasLower = 0;
    int counter = 0;
    int valid = 0;
    int i = 0;
    while (!valid)
    {
        printf("Enter the password (must be %d chars in length): ", 8);
        getCString(strtemp, 8, 8);
        i = 0;
        hasSpecialChar = 0;
        counter = 0;
        hasSpecialChar = 0;
        hasLower = 0;
        hasUpper = 0;
        hasNumber = 0;
        while (strtemp[i] != 0)
        {
            if (strtemp[i] == '!' || strtemp[i] == '@' || strtemp[i] == '#' || strtemp[i] == '$' || strtemp[i] == '%' || strtemp[i] == '^' || strtemp[i] == '&' || strtemp[i] == '*')
            {
                hasSpecialChar++;
            }
            else if (strtemp[i] >= 'a' && strtemp[i] <= 'z')
            {
                hasLower++;
            }
            else if (strtemp[i] >= 'A' && strtemp[i] <= 'Z')
            {
                hasUpper++;
            }
            else if (strtemp[i] >= '0' && strtemp[i] <= '9')
            {
                hasNumber++;
            }
            i++;
            counter++;
        }
        if (2 == hasSpecialChar && 2 == hasLower && 2 == hasNumber && 2 == hasUpper)
        {
            valid = 1;
        }
        else
        {
            for (i = 0; i < 15 + 1; i++)
            {
                strtemp[i] = 0;
            }
            printf("SECURITY: Password must contain 2 of each:\n");
            printf("          Digit: 0-9\n");
            printf("          UPPERCASE character\n");
            printf("          lowercase character\n");
            printf("          symbol character: !@#$%%^&*\n");
        }
        for (i = 0; i <= counter; i++)
        {
            info->passward[i] = strtemp[i];
        }
    }
    printf("\n");

}

void getDemographic(struct Demographic* demo)
{
    printf("Demographic Data Input\n");
    printf("----------------------------------------\n");

    int year = 0, min_year = 0, max_year = 0;
    year = currentYear();
    max_year = year - 18;
    min_year = year - 110;
    char strtemp[30 + 1] = { 0 };
    const char INTERVAL = 'a' - 'A';
    int i = 0;

    // Add the necessary code to get user input for each Demographic member:
    printf("Enter birth year (current age must be between 18 and 110): ");

    demo->birthyear = getIntFromRange(min_year, max_year);

    printf("Enter the household Income: $");
    demo->income = getPositiveDouble();

    
    printf("Enter the country (%d chars max.): ", 30);
    getCString(strtemp, 1, 30);
    i = 0;
    while (demo->country[i] != 0)
    {
        demo->country[i] = 0;
        i++;
    }
    i = 0;
    while (strtemp[i] != 0)
    {
        demo->country[i] = (strtemp[i] >= 'a' && strtemp[i] <= 'z') ? strtemp[i] - INTERVAL : strtemp[i];
        i++;
    }
    printf("\n");


}

void updateAccount(struct Account* acc)
{ 
    int i = 0, flag =0;

    do
    {
        flag = 0;
        printf("\n");
        printf("Account: %05d - Update Options\n", acc->accnum);
        printf("----------------------------------------\n");
        printf("1) Update account type (current value: %c)\n", acc->acctype);
        printf("2) Login\n");
        printf("3) Demographics\n");
        printf("0) Done\n");
        printf("Selection: ");
        i = getIntFromRange(0, 3);

        if (i == 1)
        {
            printf("\n");
            printf("Enter the account type (A=Agent | C=Customer): ");
            acc->acctype = getCharOption("AC");
        }

        if (i == 2)
        {
            printf("\n");
            updateUserLogin(&acc->login);

        }
        if (i == 3)
        {
            printf("\n");
            updateDemographic(&acc->demo);

        }
        if (i == 0)
        {
            flag = 1;

        }
    } while (flag == 0);

}

void updateUserLogin(struct UserLogin* login)
{
    int flag = 0;
    while (flag == 0)
    {
        int i = 0;
        printf("\n");
        printf("User Login: %s - Update Options\n", login->accountHolder);
        printf("----------------------------------------\n");
        printf("1) Display name (current value: %s)\n", login->loginname);
        printf("2) Password\n");
        printf("0) Done\n");
        printf("Selection: ");

        i = getIntFromRange(0, 2);

        if (i == 1)
        {
            printf("\n");
            printf("Enter the display name (30 chars max): ");
            getCString(login->loginname, 1, 30);
            flag = 0;
        }
        else if (i == 2)
        {
            printf("\n");
            printf("Enter the password (must be %d chars in length): ", 8);
            getCString(login->passward, 8, 8);
            flag = 0;
        }
        else if (i == 0)
        {
            printf("\n");
            flag = 1;
        }
    }
   return;
}

void updateDemographic(struct  Demographic* demo)
{
    int flag = 0;
    do
    {
        int i = 0;
       
        
        printf("\n");
        printf("Demographic Update Options\n");
        printf("----------------------------------------\n");
        printf("1) Household Income (current value: $%.2lf)\n", demo->income);
        printf("2) Country (current value: %s)\n", demo->country);
        printf("0) Done\n");
        printf("Selection: ");

        i = getIntFromRange(0, 2);

        if (i == 1)
        {
            printf("\n");
            printf("Enter the household Income: $");
            demo->income = getPositiveDouble();
            flag = 0;
        }
        else if (i == 2)
        {
            printf("\n");
            printf("Enter the country (30 chars max.): ");
            getCString(demo->country, 1, 30);
            flag = 0;
        }
        else if (i == 0)
        {
            printf("\n");
            flag = 1;
            
        }
    } while (flag == 0);
    return;
}