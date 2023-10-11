#include <stdio.h>
#include "main.h"

/**
* print_remaining_days - takes a date and prints how many days are
* left in the year, taking leap years into account
* @month: month in number format
* @day: day of month
* @year: year
* Return: void
*/

void print_remaining_days(int month, int day, int year)
{
		/* Check if the year is a leap year. Leap years have 366 days. */
	if (year % 4 == 0 || (year % 400 == 0 && !(year % 100 == 0)))
	{
			/**
			 * If it's a leap year and the month is greater
			 * than or equal to February (2),
			*/
			/* increment the 'day' by 1 to account for February 29.*/
		if (month >= 2)
		{
			day++;
		}

		/* Print the day of the year, which is the 'day' value. */
		printf("Day of the year: %d\n", day);

		/**
		 * Calculate and print the remaining days in the leap year,
		 * which is 366 - 'day'.
		*/
		printf("Remaining days: %d\n", 366 - day);
	}
	else
	{
			/* If it's not a leap year, handle differently. */
			/**
			 * Check if the date is February 29 (day 60),
			 * which is invalid for non-leap years.
			*/
		if (month == 2 && day == 60)
		{
				/*Print an error message indicating an invalid date.*/
			printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
		}
		else
		{
				/**
				 * If it's a non-leap year, print the day of the year,
				 * which is the 'day' value.
				*/
			printf("Day of the year: %d\n", day);

			/**
			 * Calculate and print the remaining days in a non-leap year,
			 * which is 365 - 'day'.
			*/
			printf("Remaining days: %d\n", 365 - day);
		}
	}
}

