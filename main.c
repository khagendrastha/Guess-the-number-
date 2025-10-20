#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

void fill_time(char *, int);
void fill_date(char *);
int input_format();
void clear_screen();

int main()
{
    char time_str[50], date_str[100];
    int format = input_format();

    clear_screen(); // clear once at start

    while (1)
    {
        fill_time(time_str, format);
        fill_date(date_str);

        // Move cursor to top-left corner (no flicker)
        printf("\033[H");

        printf("=================================\n");
        printf("         DIGITAL CLOCK           \n");
        printf("=================================\n\n");
        printf("Current Time : %s\n", time_str);
        printf("Date         : %s\n", date_str);
        printf("\nPress Ctrl + C to exit.\n");

        fflush(stdout); // make sure output is printed immediately
        sleep(1);       // wait 1 second
    }
    return 0;
}

void fill_time(char *buffer, int format)
{
    time_t rawtime;
    struct tm *current_time;
    time(&rawtime);
    current_time = localtime(&rawtime);
    if (format == 1)
    {
        strftime(buffer, 50, "%H:%M:%S", current_time); 
    }
    else
    {
        strftime(buffer, 50, "%I:%M:%S %p", current_time); // 12-hour format
    }
}

int input_format()
{
    int format;
    printf("Choose the time format:\n");
    printf("1. 24-hour format\n");
    printf("2. 12-hour format\n");
    printf("Make a choice (1/2): ");
    scanf("%d", &format);
    return format;
}

void fill_date(char *buffer)
{
    time_t rawtime;
    struct tm *current_time;
    time(&rawtime);
    current_time = localtime(&rawtime);
    strftime(buffer, 100, "%A %B %d %Y", current_time);
}

void clear_screen()
{
    printf("\033[2J\033[H");
}
