#include <stdio.h>
void main()
{
	int num, sum,n=0,min=0,max=0;
	float avg;
	printf("Enter positive numbers (0 or -ve number to stop):\n");
	sum = 0;
	scanf_s("%d", &num);
	min = num;
	max = num;
	while (num > 0)
	{    
		n++;
		if (num >= max)
		{
			max = num;
		}
		if (num <= min)
		{
			min = num;
		}
		sum += num;
		scanf_s("%d", &num);
	}
	avg = (float)sum / n;
	printf_s("Sum = %d  avg = %f min = %d max = %d \n", sum,avg,min,max);
	getch();
}