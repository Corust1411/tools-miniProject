#include <stdio.h>
#include <stdlib.h>

double addition(double firstOperand, double secondOperand);
double subtraction(double firstOperand, double secondOperand);
double multiplication(double firstOperand, double secondOperand);
double division(double firstOperand, double secondOperand);
void addLog(double input);
int logPanel();
int main();

#define MAX_LOG_ENTRIES 100 // Define the maximum number of log entries

double allResult[MAX_LOG_ENTRIES]; // Define the array size
int logCount;

int calculatorPanel()
{
    double firstOperand;
    system("clear");
    printf("---------- CALCULATOR TOOL ----------\n\n");
    printf("Enter your first operand: ");
    scanf("%lf", &firstOperand);

    while (1)
    {
        system("clear");
        printf("---------- CALCULATOR TOOL ----------\n\n");

        char input;
        double secondOperand, summary;

        printf("Current result : %lf\n\n", summary);
        printf("Choose which operator (+, -, *, /)\n");
        printf("1. addition (+)\n2. subtraction (-)\n3. multiplication (*)\n4. division (/)\n5. view log (input 5)\n6. back to main menu (input 6)\n7. exit program (input 7)\n\nExample : + 69\n");
        printf("Enter your option : ");
        scanf("%c %lf", &input, &secondOperand);
        if (input == '5')
        {
            logPanel();
        }
        if (input == '6')
        {
            main();
        }
        if (input == '7')
        {
            exit(0);
        }

        if (input != '+' && input != '-' && input != '*' && input != '/')
        {
            continue;
        }

        switch (input)
        {
        case '+':
            summary = addition(firstOperand, secondOperand);
            break;
        case '-':
            summary = subtraction(firstOperand, secondOperand);
            break;
        case '*':
            summary = multiplication(firstOperand, secondOperand);
            break;
        case '/':
            summary = division(firstOperand, secondOperand);
            break;
        default:
            printf("Invalid operator, please select again.\n\n");
            continue;
        }
        firstOperand = summary;
    }
    return 0;
}

double addition(double firstOperand, double secondOperand)
{
    double result = firstOperand + secondOperand;
    addLog(result);
    return result;
}

double subtraction(double firstOperand, double secondOperand)
{
    double result = firstOperand - secondOperand;
    addLog(result);
    return result;
}

double multiplication(double firstOperand, double secondOperand)
{
    double result = firstOperand * secondOperand;
    addLog(result);
    return result;
}

double division(double firstOperand, double secondOperand)
{
    if (secondOperand == 0)
    {
        printf("Error: Division by zero\n");
        return firstOperand;
    }

    double result = firstOperand / secondOperand;
    addLog(result);
    return result;
}

void addLog(double input)
{
    if (logCount < MAX_LOG_ENTRIES)
    {
        allResult[logCount] = input;
        logCount++;
    }
    else
    {
        printf("Log is full. Cannot add more entries.\n");
    }
}

int logPanel()
{
    char input;

    system("clear");
    printf("---------- CALCULATOR TOOL ----------\n");
    printf("Log entries:\n");
    for (int i = 0; i < logCount; i++)
    {
        printf("result %d: %lf\n", i + 1, allResult[i]);
    }
    while (1)
    {
        printf("Enter any letter to back to calculator\n");
        scanf(" %c", &input);
        if (input == 'Y' || 'y')
        {
            return 0;
        }
        else if (input == 'N' || 'n')
        {
            exit(0);
        }
        else
        {
            printf("Invalid option, please select again.\n\n");
        }
    }
}