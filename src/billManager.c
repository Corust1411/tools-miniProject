#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 15

struct Bill
{
    char *billName;
    float totalPrice;
    char memberName[MAX_CUSTOMERS][50];
    float memberTotal[MAX_CUSTOMERS];
    int memberCount;
};

struct memberResult
{
    char *name;
    float totalPrice;
    char **billNames;
    int billCount;
};

int main();
void billManagerHeader();
void refreshPanel();

void billPanel()
{
    int numBills;
    char input;

    system("clear");
    refreshPanel();
    billManagerHeader();
    printf("Enter the number of bills : ");
    scanf("%d", &numBills);

    struct Bill bills[numBills];

    for (int i = 0; i < numBills; i++)
    {
        printf("Bill #%d:\n", i + 1);

        bills[i].billName = (char *)malloc(50 * sizeof(char));
        printf("Enter Bill Name : ");
        scanf(" %[^\n]s", bills[i].billName);

        printf("Enter total Price : ");
        scanf("%f", &bills[i].totalPrice);

        printf("Enter the number of member for this bill : ");
        scanf("%d", &bills[i].memberCount);

        for (int j = 0; j < bills[i].memberCount; j++)
        {
            printf("Member #%d Name: ", j + 1);
            scanf(" %[^\n]s", bills[i].memberName[j]);
        }
    }

    struct memberResult memberResult[MAX_CUSTOMERS];
    int memberResultCount = 0;

    for (int i = 0; i < numBills; i++)
    {
        for (int j = 0; j < bills[i].memberCount; j++)
        {
            int found = 0;

            for (int k = 0; k < memberResultCount; k++)
            {
                if (strcmp(bills[i].memberName[j], memberResult[k].name) == 0)
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
                memberResult[memberResultCount].name = strdup(bills[i].memberName[j]);
                memberResult[memberResultCount].totalPrice = bills[i].totalPrice / bills[i].memberCount;
                memberResult[memberResultCount].billNames = (char **)malloc(sizeof(char *));
                memberResult[memberResultCount].billNames[0] = strdup(bills[i].billName);
                memberResult[memberResultCount].billCount = 1;
                memberResultCount++;
            }
        }
    }

    refreshPanel();
    billManagerHeader();
    printf("Each member's payment detail\n\n");
    for (int i = 0; i < memberResultCount; i++)
    {
        printf("Member's Name : %s\n", memberResult[i].name);
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

    printf("\n1.back to main menu (input 1)\n2.exit (input 2)\n\n");
    printf("select your option : ");
    scanf("%s", &input);
    if (input == '1')
    {
        main();
    }
    if (input == '2')
    {
        printf("program exited.");
        exit(0);
    }
}

void billManagerHeader()
{
    printf("-------------------- BILL MANAGER TOOL --------------------\n\n");
}