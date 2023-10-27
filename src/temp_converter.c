#include <stdio.h>
#include <stdlib.h>


int temp_converterPanel(){
  

  while (1)
  {
    system("clear");

    char input;
    char temp_unit_before;
    char temp_unit_after;
    double temp = 0;
    double temp_before = 0;
    double temp_after = 0;

    printf("---------- TEMPERATURE CONVERTER ----------\n\n\n");
    printf("=============================================================\n");
    printf("=============================================================\n\n\n");

    printf("Temperature units available\n\n\n1.Celsuis (C)\n\n2.Fahrenheit (F)\n\n3.Kelvin (K)\n\n\n");
    printf("Example : 273 K\n");
    printf("Please Enter your Temperature : ");
    scanf("%lf %s", &temp, &temp_unit_before);


    if (temp_unit_before == 'K')
    {
        temp_before = temp-273;
    }
    if (temp_unit_before == 'F')
    {
        temp_before = (5.0/9.0)*(temp-32);
    }

    printf("convert to (C, K or F): ");
    scanf("%s", &temp_unit_after);

    printf("\n\n\n=============================================================\n");
    printf("=============================================================\n\n\n");


    if (temp_unit_after == 'C'){
      temp_after = temp_before;
    }
    if (temp_unit_after == 'K'){
      temp_after = temp_before+273;
    }
    if (temp_unit_after == 'F'){
      temp_after = ((9.0/5.0)*temp_before)+32;
    }
    printf("Result is : %.2lf %c", temp_after, temp_unit_after);

    printf("\n\n1.reset? (r)");
    printf("\n\n2.quit? (q)");
    printf("\n\n3.back to main menu (y)");

    printf("\n\nselect your option : ");
    scanf("%s", &input);

    if(input == 'y'){
      main();
    }
    if(input == 'r'){
      system("clear");
    }
    if(input == 'q'){
      exit(0);
    }
  }

  return 0;
}