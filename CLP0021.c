

/* 
 * File:   main.c
 * Author: ThinhVNHE141345
 * Purpose: Generate day of year, day of week and week of year from a string in date format.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: check a year whether is a leap year
 */
int checkLeapYear(int year) {
   

    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return 1; 
        //if the year is divisible by 400 or is divisible by 4 and is not divisible by 100, that year will be a leap year and return 1
    
        return 0; 
        // if the year don't satisfied then return 0  
}

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: calculate day of year
 */
int dayOfYear(int day, int month, int year) {
    
    int normalYear[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     // create an array for normal year
    int leapYear[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    //create an array for leap year
    int dayofyear = day; 
    //the dayofyear parameter was assigned equals the day parameter
    if (checkLeapYear(year) == 1) {
    //check whether year is a leap year 
        int i; 
        //the i parameter began from 1 to the previous month 
        for (i = 1; i < month; i++)
            dayofyear += leapYear[i - 1];
        //the new value of the dayofyear parameter was the total of the old value and each month from January to the previous month   
        return dayofyear;
    } else {
        int i; 
        //the i parameter began from 1 to the previous month
        for (i = 1; i < month; i++)
            dayofyear += normalYear[i - 1];
        //the new value of the dayofyear parameter was the total of the old value and each month from January to the previous month 
        return dayofyear;
    }
}

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: calculate day of week
 */
void dayOfWeek(int day, int month, int year) {
    
    long long alldays = 0; //the total days
    int i; 
    //the i parameter began from 1900 to the previous year
    for (i = 1900; i < year; i++) {
        if (checkLeapYear(i) == 1)
            //if that year is a leap year
            alldays += 366;
             //the total days was increased 366 days
        else
            //if that year isn't a leap year
            alldays += 365; 
            //the total days was increased 365 days
    }
    int days = dayOfYear(day, month, year) - 1; 
    //the total days from 1st January of this year to the previous day
    alldays += days; 
    //the total days from 1st January 1900 to the previous day
    int temp = alldays % 7; 
    // because the 1st January 1900 is Monday
    switch (alldays % 7) {
        case 0:
        {
            printf("Day of week: Monday\n");
            break;
        }
        case 1:
        {
            printf("Day of week: Tuesday\n");
            break;
        }
        case 2:
        {
            printf("Day of week: Wednesday\n");
            break;
        }
        case 3:
        {
            printf("Day of week: Thursday\n");
            break;
        }
        case 4:
        {
            printf("Day of week: Friday\n");
            break;
        }
        case 5:
        {
            printf("Day of week: Saturday\n");
            break;
        }
        case 6:
        {
            printf("Day of week: Sunday\n");
            break;
        }

    }
   
}


/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: calculate week of year
 */
int weekOfYear(int day, int month, int year) {

    int days1 = dayOfYear(day, month, year) - 1; 
    //the total days from 1st January of this year to the previous day  
    long long alldays = 0; 
    //the total days
    int i; 
    //the i parameter began from 1900 to the previous year
    for (i = 1900; i < year; i++) {
        if (checkLeapYear(i) == 1)
        //if that year is a leap year
            alldays += 366; 
            //the total days was increased to 366 days
        else
            alldays += 365;
             //the total days was increased to 365 days
    }
    int days = dayOfYear(1, 1, year) - 1;
    alldays += days; 
    //the total days from 1st January 1900 to 1st January of this year
    int temp = alldays % 7; 
    // because the 1st January 1900 is Monday
    int week = days1 / 7; 
    //calculate almost exactly the week of this year
    int weekofyear;
    if (temp <= 3) 
    //if this first day of this year is from Monday to Thursday
        weekofyear = week + 1;
         // the exact week of this year must been increased to 1

    else 
    //if this first day of this year is from Friday to Sunday
        weekofyear = week; 
        // the exact week of this year must been conserved

    return weekofyear;
}


/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: convert day from string to integer
 */
int transferDay(char input[]) {

   
    int day;
    char temp[2];
    int i;
    //the i parameter began from 0 to 1 in input string
    for (i = 0; i <= 1; i++)
        temp[i] = input[i]; 
    //each element of temp string was assigned from each element of string input at the same position 
    day = atoi(temp); 
    //convert string to integer
    return day;
}

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: convert month from string to integer
 */
int transferMonth(char input[]) {
    
    int month;
    char temp[2];
    int k = 3; 
    //the k parameter is initialized equals 3
    for (int i = 0; i < 2; i++) { 
    //the i parameter begin from 0 to 1 in temp string  
        for (int j = k; j <= 4; j++) {
        //the j parameter begin from the value of parameter k to 4 in input string
            temp[i] = input[j]; 
            //each element of temp string was assigned from each element of string input
            ++k; 
            //the k parameter was increased to 1
            break;
        }
    }
    month = atoi(temp);
     //convert string to integer
    return month;
}

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: convert year from string to integer
 */
int transferYear(char input[]) {
    
    char temp[4];
    int year;
    int k = 6; 
    //the k parameter is initialized equals 6
    for (int i = 0; i < 4; i++) {
    //the i parameter begin from 0 to 4 in temp string        
        for (int j = k; j <= 9; j++) {
        //the j parameter begin from the value of parameter k to 9 in input string
            temp[i] = input[j]; 
            //each element of temp string was assigned from each element of string input
            ++k; 
            //the k parameter was increased to 1
            break;
        }
    }
    year = atoi(temp);
     //convert string to integer
    return year;
}


/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: Check input string 
 */
int checkStringInput(char input[]) {
   
    if (strlen(input) != 10) 
    //check the length of the input string if not equals to 10 then the input string is invalid
        return 0;
    for (int h = 6; h <= 9; h++) {
    //the h parameter begin from 6 to 9 in temp string 
        if (input[h] <= '0' && input[h] >= '9')
    // check the year whether is valid
            return 0;
    }

    if (input[0] && input[1] && input[3] && input[4] <= '0' && input[0] && input[1] && input[3] && input[4] >= '9')// check the day and month whether is valid
        return 0;

    else if (input[2] && input[5] != '/')
    //check whether the position at 2 and 5 is '/'
        return 0;

    return 1;
}


/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: Check valid input
 */
int checkInput(char input[]) {
 

    if (checkStringInput(input) == 0)
    //Check whether the input string is valid
        return 0;
    else {//if the input string is valid then
        int day = transferDay(input); 
        //convert day from string to integer
        int month = transferMonth(input); 
        //convert month from string to integer
        int year = transferYear(input); 
        //convert year from string to integer
        int normalYear[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
         // create an array for normal year
        int leapYear[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
         // create an array for leap year
        if (checkLeapYear(year) == 1) { 
        //check whether year is a leap year
            if (day < 1 || day > leapYear[month - 1] || month < 1 || month > 12 || year < 1900)
                //check the day, month, leap year whether is valid
                return 0;
            else
                return 1;
        } else {
            if (day < 1 || day > normalYear[month - 1] || month < 1 || month > 12 || year < 1900)
                // check the day, month, normal year whether is valid
                return 0;
            else
                return 1;
        }
    }
}

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: display the result
 */
void display(char strDay[]) {
   
    int day, month, year;
    day = transferDay(strDay);
    month = transferMonth(strDay);
    year = transferYear(strDay);
    printf("Day of year: %d\n", dayOfYear(day, month, year));
    dayOfWeek(day, month, year);
    printf("Week of year: %d\n", weekOfYear(day, month, year));
}


/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: get the string when the user enter the input string
 */
char* getString(char str[]) {
    
    while (1) {
    //if the user enter the validly input string the while loop will end 
        printf("Please enter a date (dd/mm/yyyy):");
        scanf("%s", str);
        if (checkInput(str) == 0)
        //check whether the input string is valid
            printf("Invalid date\n");
        else
            return str;
    }
}

/*  Author: ThinhVNHE141345
 *  Date: 20/01/2020 (tuy theo ngay code)
 *  Purpose: to maintain the program when the user don't wanna stop
 */
void yesContinue(char str[]) {
  
    char t;
    while (1) {
        fpurge(stdin);
        printf("Enter y to continue or n to exit: ");
        scanf("%c", &t);
        if (t == 'y' || t == 'Y')
        //if the user enter 'y', the program will continue 
            display(getString(str));
        else if (t == 'n' || t == 'N')
        //if the user enter 'n', the program will end 
            break;
    }
}

int main(int argc, char** argv) {
    char s[10]; 
    //the s string was initialized has the 10 value
    display(getString(s));
    yesContinue(s);
}

