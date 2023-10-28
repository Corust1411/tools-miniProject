#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double operand;
double weight;
char unit_weight;
char newUnit_weight;
char input;

void weightHeader();
int unitweightHeader();

void weight_converterPanel()
{
  while (1)
  {
    system("clear");
    refreshPanel();
    weightHeader();

    printf("Weight Units available\n\n");
    printf("1.Grams (g)\n2.Kilograms (k)\n3.Milligrams (m)\n4.Tonne (t)\n5.Pound (p)\n6.Ounce (o)\n");

    printf("Enter your number : ");
    scanf("%lf", &operand);

    printf("\nUnit (symbol) : ");
    scanf("%s", &unit_weight);

    printf("\nTo unit (symbol) : ");
    scanf("%s", &newUnit_weight);

    refreshPanel();
    weightHeader();

    if (unit_weight == 'g')
    {
      weight = operand;
    }
    if (unit_weight == 'k')
    {
      weight = operand * ((double)(pow(10, 3)));
    }
    if (unit_weight == 'm')
    {
      weight = operand * ((double)(pow(10, -3)));
    }
    if (unit_weight == 't')
    {
      weight = operand * ((double)(pow(10, 6)));
    }
    if (unit_weight == 'p')
    {
      weight = operand * 453.592;
    }
    if (unit_weight == 'o')
    {
      weight = operand * 28.35;
    }

    if (newUnit_weight == 'g')
    {
      printf("Result : %.2lf %c", weight, newUnit_weight);
    }
    if (newUnit_weight == 'k')
    {
      printf("Result : %.2lf %c", weight * ((double)(pow(10, -3))), newUnit_weight);
    }
    if (newUnit_weight == 'm')
    {
      printf("Result : %.2lf %c", weight * ((double)(pow(10, 3))), newUnit_weight);
    }
    if (newUnit_weight == 't')
    {
      printf("Result : %.2lf %c", weight * ((double)(pow(10, -6))), newUnit_weight);
    }
    if (newUnit_weight == 'p')
    {
      printf("Result : %.2lf %c", weight / 453.592, newUnit_weight);
    }
    if (newUnit_weight == 'o')
    {
      printf("Result : %.2lf %c", weight / 28.35, newUnit_weight);
    }

    printf("\n\n\n1.use tool again (input 1)\n2.back to main menu (input 2)\n3.exit (input 3)\n\n");
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

void weightHeader()
{
  printf("---------- WEIGHT CONVERTER TOOL ----------\n\n\n");
}