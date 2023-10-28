#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double operand;
char unit[4];
char newUnit[3];
char input;

void volumnHeader();
int unitVolumnCheck();

void volumn_converterPanel()
{
  while (1)
    {
        system("clear");
        refreshPanel();
        volumnHeader();
        printf("Enter your number : ");
        scanf("%lf", &operand);

        printf("\nUnit (symbol) (use - for meter, use 1 for micro, use 2 for deka) : ");
        scanf("%s", unit);

        printf("\nTo unit (symbol) (use - for meter, use 1 for micro, use 2 for deka): ");
        scanf("%s", newUnit);

        refreshPanel();
        volumnHeader();

        printf("Result : %.2lf\n\n\n", operand*(pow(10.0,(double) (unitVolumnCheck(unit)-unitVolumnCheck(newUnit))*3)));
 
        printf("\n1.use tool again (input 1)\n2.back to main menu (input 2)\n3.exit (input 3)\n\n");
        printf("select your option : ");
        scanf("%s", &input);
        if (input == '1')
        {
          continue;
        }
        if (input == '2')
        {
          main();
        }
        if (input == '3')
        {
          printf("program exited.");
          exit(0);
        }
    }
}

int unitVolumnCheck(char c_unit[4])
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
        return 9;
        break;

    case 'T':
        return 12;
        break;

    case 'P':
        return 15;
        break;

    case 'E':
        return 18;
        break;

    case 'Z':
        return 21;
        break;

    case 'Y':
        return 24;
        break;

    case 'R':
        return 27;
        break;

    case 'Q':
        return 30;
        break;

    default:
        printf("error");
    }
}

void volumnHeader()
{
  printf("---------- VOLUMN CONVERTER TOOL ----------\n\n\n");
}