#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBER 15

struct Bill
{
    char *billName;
    float totalPrice;
    char memberNames[MAX_MEMBER][50];
    float memberTotals[MAX_MEMBER];
    int memberCount;
};

struct MemberResult
{
    char *name;
    float totalPrice;
    char **billNames;
    int billCount;
};

void refreshPanel();

void billPanel()
{

    char input;
    int numBills;
    struct Bill bills[numBills];
    struct MemberResult memberResult[MAX_MEMBER];
    int memberResultCount = 0;

    refreshPanel();
    printf("---------- BILL MANAGER TOOL ----------\n\n");
    printf("How to use\n - enter number of bills\n - enter bill's detail (total price, member for the bill)\n\n");
    printf("Enter the number of bills : ");
    scanf("%d", &numBills);

    for (int i = 0; i < numBills; i++)
    {
        printf("Bill #%d:\n", i + 1);
        bills[i].billName = (char *)malloc(50 * sizeof(char));
        printf("Enter Bill Name : ");
        scanf(" %[^\n]s", bills[i].billName);

        printf("Enter Total Price : ");
        scanf("%f", &bills[i].totalPrice);

        printf("Enter the number of member for this bill: ");
        scanf("%d", &bills[i].memberCount);

        for (int j = 0; j < bills[i].memberCount; j++)
        {
            printf("Member's name #%d : ", j + 1);
            scanf(" %[^\n]s", bills[i].memberNames[j]);
        }
    }
    for (int i = 0; i < numBills; i++)
    {
        for (int j = 0; j < bills[i].memberCount; j++)
        {
            int found = 0;
            for (int k = 0; k < memberResultCount; k++)
            {
                if (strcmp(bills[i].memberNames[j], memberResult[k].name) == 0)
                {
                    memberResult[k].totalPrice += bills[i].totalPrice / bills[i].memberCount;
                    memberResult[k].billNames = (char **)realloc(memberResult[k].billNames, (memberResult[k].billCount + 1) * sizeof(char *));
                    memberResult[k].billNames[memberResult[k].billCount] = strdup(bills[i].billName);
                    memberResult[k].billCount++;
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                memberResult[memberResultCount].name = strdup(bills[i].memberNames[j]);
                memberResult[memberResultCount].totalPrice = bills[i].totalPrice / bills[i].memberCount;
                memberResult[memberResultCount].billNames = (char **)malloc(sizeof(char *));
                memberResult[memberResultCount].billNames[0] = strdup(bills[i].billName);
                memberResult[memberResultCount].billCount = 1;
                memberResultCount++;
            }
        }
    }

    refreshPanel();
    printf("---------- BILL MANAGER TOOL ----------\n\n");
    printf("Each member's payment detail\n\n");
    for (int i = 0; i < memberResultCount; i++)
    {
        printf("Customer Name : %s\n", memberResult[i].name);
        printf("Total price : %.2f\n", memberResult[i].totalPrice);
        printf("List of bills\n");
        for (int j = 0; j < memberResult[i].billCount; j++)
        {
            printf(" - %s\n", memberResult[i].billNames[j]);
            free(memberResult[i].billNames[j]);
        }
        free(memberResult[i].billNames);
        free(memberResult[i].name);
        printf("\n");
    }
    for (int i = 0; i < numBills; i++)
    {
        free(bills[i].billName);
    }

    printf("\n1.reset (input 1)\n2.back to main menu (input 2)\n3.exit (input 3)\n\n");
    printf("select your option : ");
    scanf("%s", &input);
    switch (input)
    {
    case '1':
        printf("reset");
        break;
    case '2':
        main();
        break;
    case '3':
        printf("program exited.");
        exit(0);
    }
}