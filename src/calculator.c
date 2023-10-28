#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double addition(double firstOperand, double secondOperand);
double subtraction(double firstOperand, double secondOperand);
double multiplication(double firstOperand, double secondOperand);
double division(double firstOperand, double secondOperand);
void addLog(double input);
void resetLog();
void refreshPanel();
void calculatorHeader();
int logPanel();
int main();

#define MAX_LOG_ENTRIES 100 // Define the maximum number of log entries

double allResult[MAX_LOG_ENTRIES]; // Define the array size
int logCount;

void calculatorPanel()
{
    double firstOperand;

    system("clear");
    refreshPanel();
    calculatorHeader();
    printf("How to use\n - enter your first operand\n - enter operator\n - enter second operand\n\n");

    printf("Enter your first operand : ");
    scanf("%lf", &firstOperand);

    while (1)
    {
        system("clear");
        refreshPanel();
        calculatorHeader();

        char input;
        double secondOperand, summary;

        printf("Current result : %.2lf\n\n", firstOperand);
        printf("Choose which operator (+, -, *, /) or Choose other function (1, 2, 3)\n");
        printf("1. addition (+)\n2. subtraction (-)\n3. multiplication (*)\n4. division (/)\n\n or use these feature\n1. view log (input 1)\n2. back to main menu (input 2)\n3. exit program (input 3)\n\n");
        printf("Enter your option : ");
        scanf(" %c", &input);
        if (input == '1')
        {
            logPanel();
        }
        if (input == '2')
        {
            resetLog();
            main();
        }
        if (input == '3')
        {
            printf("program exited.");
            exit(0);
        }
        if (input == '+' || input == '-' || input == '*' || input == '/')
        {
            printf("\nEnter your second operand : ");
            scanf(" %lf", &secondOperand);

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
            }
            firstOperand = summary;
        }
    }
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

void resetLog()
{
    if (logCount < MAX_LOG_ENTRIES)
    {
        for (int i = 0; i < logCount; i++)
        {
            allResult[i] = 0;
        }
        logCount = 0;
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
    calculatorHeader();
    printf("Log entries:\n");
    for (int i = 0; i < logCount; i++)
    {
        printf("result #%d : %lf\n", i + 1, allResult[i]);
    }
    printf("\nEnter any letter to back to calculator\n");
    scanf(" %c", &input);
    if (isalpha(input))
    {
        return 0;
    }
}

void calculatorHeader()
{
    printf("-------------------- CALCULATOR TOOL --------------------\n\n");
}