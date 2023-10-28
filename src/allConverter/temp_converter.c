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
    printf("Temperature units available\n\n1.Celsuis (C)\n2.Fahrenheit (F)\n3.Kelvin (K)\n\n");
    printf("Example : 273 K\n");
    printf("Enter Temperature : ");
    scanf("%lf %s", &temp, &temp_unit_before);

    if (temp_unit_before == 'K' || temp_unit_before == 'k')
    {
      temp_before = temp - 273;
    }
    if (temp_unit_before == 'F' || temp_unit_before == 'f')
    {
      temp_before = (5.0 / 9.0) * (temp - 32);
    }

    printf("\nconvert to (C, K or F): ");
    scanf("%s", &temp_unit_after);

    refreshPanel();
    temperatureHeader();

    if (temp_unit_after == 'C' || temp_unit_before == 'c')
    {
      temp_after = temp_before;
    }
    if (temp_unit_after == 'K' || temp_unit_before == 'k')
    {
      temp_after = temp_before + 273;
    }
    if (temp_unit_after == 'F' || temp_unit_before == 'f')
    {
      temp_after = ((9.0 / 5.0) * temp_before) + 32;
    }
    printf("Convert from : %.2lf %s\n", temp, temp_unit_before);
    printf("Result is : %.2lf %c\n\n", temp_after, temp_unit_after);

    printf("1.use tool again (input 1)\n2.back to main menu (input 2)\n3.exit (input 3)\n\n");
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
  printf("-------------------- TEMPERATURE CONVERTER --------------------\n\n");
}