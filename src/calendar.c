#include <stdio.h>
#include <stdlib.h>

int main();
void refreshPanel();
void calendarHeader();

int get_1st_weekday(int year)
{
    int d;
    d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return d;
}

int calendarPanel()
{
    while (1)
    {
        char input = 0;
        int year, month, day, daysInMonth, weekDay = 0, startingDay;
        char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        refreshPanel();
        calendarHeader();
        printf("How to use\n - enter which year you want to see the whole year calendar\n\n");
        printf("Enter year : ");
        scanf("%d", &year);

        refreshPanel();
        calendarHeader();
        printf("\tCalendar of year %d\n", year);

        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            monthDay[1] = 29;

        startingDay = get_1st_weekday(year);

        for (month = 0; month < 12; month++)
        {

            daysInMonth = monthDay[month];
            printf("\n\n---------------%s-------------------\n", months[month]);
            printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

            for (weekDay = 0; weekDay < startingDay; weekDay++)
                printf("     ");

            for (day = 1; day <= daysInMonth; day++)
            {
                printf("%5d", day);

                if (++weekDay > 6)
                {
                    printf("\n");
                    weekDay = 0;
                }
                startingDay = weekDay;
            }
        }
        printf("\n\n1.use tool again (input 1)\n2.back to main menu (input 2)\n3.exit (input 3)\n\n");
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

void calendarHeader()
{
    printf("-------------------- CALENDAR TOOL --------------------\n\n");
}
