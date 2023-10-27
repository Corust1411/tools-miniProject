#include <stdio.h>
#include <allConverter/temp_converter.c>
#include <allConverter/area_converter.c>
#include <allConverter/volumn_converter.c>
#include <allConverter/weight_converter.c>
#include <allConverter/lenghtConverter.c>

int main();

void converterPanel()
{
    while (1)
    {
        system("clear");
        char input;

        printf("-------------------- UNIT CONVERSION TOOL --------------------\n\n");
        printf("Select which unit do you want to use !\n");
        printf("1.temperature unit converter\n2.length unit converter\n3.area unit converter\n4.volumn unit converter\n5.weight unit converter\n6.back to main menu\n\n");

        printf("select option : ");
        scanf("%c", &input);
        switch (input)
        {
        case '1':
            temp_converterPanel();
            break;
        case '2':
            lenghtPanel();
            break;
        case '3':
            area_converterPanel();
            break;
        case '4':
            volumn_converterPanel();
            break;
        case '5':
            weight_converterPanel();
            break;
        case '6':
            main();
        }
    }
}