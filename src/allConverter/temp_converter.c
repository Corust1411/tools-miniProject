#include <stdio.h>
#include <stdlib.h>

void temperatureHeader();

int temp_converterPanel()
{

  while (1)
  {
    char input;
    char temp_unit_before;
    char temp_unit_after;
    double temp = 0;
    double temp_before = 0;
    double temp_after = 0;

    system("clear");
    refreshPanel();
    temperatureHeader();
    printf("Temperature units available\n\n\n1.Celsuis (C)\n\n2.Fahrenheit (F)\n\n3.Kelvin (K)\n\n\n");
    printf("Example : 273 K\n");
    printf("Please Enter your Temperature : ");
    scanf("%lf %s", &temp, &temp_unit_before);

    if (temp_unit_before == 'K')
    {
      temp_before = temp - 273;
    }
    if (temp_unit_before == 'F')
    {
      temp_before = (5.0 / 9.0) * (temp - 32);
    }

    printf("convert to (C, K or F): ");
    scanf("%s", &temp_unit_after);

    refreshPanel();
    temperatureHeader();

    if (temp_unit_after == 'C')
    {
      temp_after = temp_before;
    }
    if (temp_unit_after == 'K')
    {
      temp_after = temp_before + 273;
    }
    if (temp_unit_after == 'F')
    {
      temp_after = ((9.0 / 5.0) * temp_before) + 32;
    }
    printf("Result is : %.2lf %c", temp_after, temp_unit_after);

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

  return 0;
}

void temperatureHeader()
{
  printf("-------------------- TEMPERATURE CONVERTER --------------------\n\n\n");
  printf("=============================================================\n");
  printf("=============================================================\n\n\n");
}