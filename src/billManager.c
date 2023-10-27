#include "stdio.h"

void billPanel()
{
    system("clear");
    printf("---------- BILL MANAGER TOOL ----------\n\n");
    printf("How to use\n- enter your first operand\n- enter operator\n- enter second operand\n\n");

    struct bill
    {
        /* data */
    };

    while (1)
    {
        system("clear");
        printf("\n---------- BILL MANGER TOOL ----------\n\n");

        char input;

        printf("1. addition (+)\n2. subtraction (-)\n3. multiplication (*)\n4. division (/)\n5. view log (input 5)\n6. back to main menu (input 6)\n7. exit program (input 7)\n\n");
        printf("Enter your option : ");
        scanf(" %c", &input);
        if (input == '5')
        {
            logPanel();
        }
        if (input == '6')
        {
            resetLog();
            main();
        }
        if (input == '7')
        {
            printf("exit program.");
            exit(0);
        }
    }
}