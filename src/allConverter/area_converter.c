#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double operand;
char unit[3];
char newUnit[3];
char input;

void areaHeader();
int unitAreaCheck();

void area_converterPanel()
{
    while (1)
    {
        system("clear");
        refreshPanel();
        areaHeader();
        printf("Unit symbol (Metric system prefixes)\n");
        printf("1.quecto (q)\t11.centi (c)\t21.exa (E)\n");
        printf("2.ronto (r)\t12.deci (d)\t22.zetta (Z)\n");
        printf("3.yocto (y)\t13.metre (-)\t23.yotta (Y)\n");
        printf("4.zepto (z)\t14.deka (=)\t24.ronna (R)\n");
        printf("5.atto (a)\t15.hecto (h)\t25.quetta (Q)\n");
        printf("6.femto (f)\t16.kilo (k)\n");
        printf("7.pico (p)\t17.mega (M)\n");
        printf("8.nano (n)\t18.giga (G)\n");
        printf("9.micro (.)\t19.tera (T)\n");
        printf("10.milli (m)\t20.peta (P)\n\n");

        printf("Enter number : ");
        scanf("%lf", &operand);

        printf("Enter number's unit : ");
        scanf("%s", unit);

        printf("Enter unit to convert to : ");
        scanf("%s", newUnit);

        refreshPanel();
        areaHeader();
        printf("Result : %lf\n\n", operand * (pow(10.0, (double)(unitAreaCheck(unit) - unitAreaCheck(newUnit)) * 2)));

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

int unitAreaCheck(char c_unit[4])
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

    case '.':
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

    case '=':
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

void areaHeader()
{
    printf("-------------------- AREA CONVERTER TOOL --------------------\n\n\n");
}