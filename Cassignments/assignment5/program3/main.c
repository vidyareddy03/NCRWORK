#include<stdio.h>
#include<conio.h>
enum oper{add=1,sub,mul,div };
void main()
{
	float n1, n2;
	int choice;
	printf( "enter two numbers ");
	scanf_s("%f %f", &n1, &n2);
	printf("enter choice \n 1.add \n 2.sub \n 3.mul \n 4.div\n");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case add: printf("addition is %f", n1 + n2);
		break;
	case sub: printf("subtraction is %f ", n1 - n2);
		break;
	case mul:printf("multiplication is %f", n1*n2);
		break;
	case div:printf("division is %f", n1 / n2);
		break;
	}
	_getch();

}