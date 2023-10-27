#include "stdio.h"
#include "stdlib.h"
#include "calculator.c"
#include "converter.c"
#include "calendar.c"
int main()
{
    while (1)
    {
        system("clear");
        char input = 0;
        printf("Select which tool do you want to use :\n");
        printf("1.calculator\n2.converter\n3.calendar\n4.bill\n5.exit\n");
        printf("select option :");
        scanf("%c", &input);
        switch (input)
        {
        case '1':
            calculatorPanel();
            break;
        case '2':
            converterPanel();
            break;
        case '3':
            calendarPanel();
            break;
        case '4':
            billCalculator();
            break;
        case '5':
            exit(0);
        default:
            printf("Invalid option, please select again.");
        }
    }
}