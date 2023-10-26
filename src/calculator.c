#include "stdio.h"

void calculatorPanel()
{
    char input = "";
    printf("Choose which operatore you want to use :\n");
    printf("1.addition\n2.subtraction\n3.multiplication\n4.division\n5.back to main menu\n");
    switch (input)
    {
    case '1':
        addition();
        break;
    case '2':
        addition();
        break;
    case '3':
        addition();
        break;
    case '4':
        addition();
        break;
    case '5':
        main();
        break;
    default:
        printf("Invalid option !");
        break;
    }
}
void addition()
{
    printf("You select addition");
}

void subtraction()
{
    printf("You select subtraction");
}

void multiplication()
{
    printf("You select multiplication");
}

void division()
{
    printf("You select division");
}