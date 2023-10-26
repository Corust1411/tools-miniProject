#include "stdio.h"
#include "calculator.c"

int main()
{
    char input = 0;
    printf("Welcome ! please select which tool do you want to use :\n");
    printf("1.calculator\n2.converter\n3.calendar\n4.bill\n5.exit\n");
    printf("select option :");
    scanf("%c", &input);
    switch (input)
    {
    case '1':
        calculatorPanel();
        break;
    case '2':
        printf("2");
        break;
    default:
        printf("Invalid option please select again.");
    }
}