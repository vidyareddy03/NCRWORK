#include<stdio.h>
struct Date
{
	int year, month, date;
};
int calculateDays(struct Date d1)
{
	int a, i, days = 0;
	a = d1.month;
	if (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12)
		days = days + 31 - d1.date;
	else
		days = days + 30 - d1.date;
	for (i = d1.month + 1; i <= 12; i++)
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			days = days + 31;
		else
			days = days + 30;
	return days;
}
int calculateDays2(struct Date d1)
{
	int a, i, days = 0;
	a = d1.month;
	days = d1.date - 1;
	for (i = 1; i < d1.month; i++)
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			days = days + 31;
		else
			days = days + 30;
	return days;
}
int calculateDays3(struct Date d1, struct Date d2)
{
	int a, i, days = 0;
	a = d1.month;
	if (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12)
		days = days + 31 - d1.date;
	else
		days = days + 30 - d1.date;
	days = days + d2.date - 1;
	for (i = d1.month + 1; i < d2.month; i++)
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			days = days + 31;
		else
			days = days + 30;
	return days;
}
int main()
{
	int year, i, days = 0, a;
	/*printf("enter year\n");
	scanf("%d", &year);
	if (((year % 4 == 0) && (year % 100 != 0)) || ((year%4==0) && (year%100==0) &&(year % 400 == 0)))
	printf("Leap year\n");
	else
	printf("Not a leap year\n");*/
	struct Date d1, d2;
	printf("enter date-1\n");
	scanf("%d%d%d", &d1.date, &d1.month, &d1.year);
	printf("enter date-2\n");
	scanf("%d%d%d", &d2.date, &d2.month, &d2.year);
	if (d1.year != d2.year)
	{
		for (i = d1.year + 1; i < d2.year; i++)
			if (((i % 4 == 0) && (i % 100 != 0)) || ((i % 4 == 0) && (i % 100 == 0) && (i % 400 == 0)))
				days = days + 366;
			else
				days = days + 355;
		days = days + calculateDays(d1) + calculateDays2(d2);


	}
	else if (d1.month != d2.month)
	{
		days = calculateDays3(d1, d2);
	}
	else
		days = d2.date - d1.date;
	printf("Days = %d", days);
	return 0;
}