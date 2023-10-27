#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double operand;
char unit[4];
char newUnit[3];
// int n_unit;
// int n_newUnit;
int unitCheck();

int lenghtPanel()
{
    while (1)
    {
        system("clear");
        printf("---------- LENGHT CONVERTER TOOL ----------\n\n");
        printf("Enter your number : ");
        scanf("%lf", &operand);

        printf("Unit (symbol) (use 1 for micro, use 2 for deka) : ");
        scanf("%s", unit);

        printf("To unit (symbol) (use 1 for micro, use 2 for deka): ");
        scanf("%s", newUnit);

        printf("old : %i\n", unitCheck(unit));
        printf("new : %i", unitCheck(newUnit));
        scanf("%s", &newUnit);
    }
}

int unitCheck(char c_unit[4])
{
    switch (c_unit[0])
    {
    case 'q':
        return -30;
        break;

    case 'r':
        return -27;
        break;

    case 'y':
        return -24;
        break;

    case 'z':
        return -21;
        break;

    case 'a':
        return -18;
        break;

    case 'f':
        return -15;
        break;

    case 'p':
        return -12;
        break;

    case 'n':
        return -9;
        break;

    case '1':
        return -6;
        break;

    case 'm':
        return -3;
        break;

    case 'c':
        return -2;
        break;

    case 'd':
        return -1;
        break;

    case '-':
        return 0;
        break;

    case '2':
        return 1;
        break;
    
    case 'h':
        return 2;
        break;

    case 'k':
        return 3;
        break;

    case 'M':
        return 6;
        break;

    case 'G':
        return 2;
        break;

    // default:
    //     printf("error");
    }
}