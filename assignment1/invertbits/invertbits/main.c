#include<stdio.h>
void main()
{
	int n,p,b, RESULT;
	int invert(int, int, int);
	
	printf("ENTER ANY INTEGER TO INVERT (n) :  ");
	scanf_s("%d", &n);
	printf("ENTER THE START POSITION TO INVERT (P) : ");
	scanf_s("%d", &p);
	printf("ENTER THE LENGTH TO INVERT (b) : ");
	scanf_s("%d", &b);
	printf("CONVERTED BINARY VALUE OF %d IS \t", n);
	RESULT = invert(n, p, b);
	printf("\nINVERTED INTEGER IN DECIMAL FORM IS \t%d", RESULT);
	getch();
}

int invert(int n, int P, int b)
{
	int I, Y, LIMIT, LEN, BIN[15];
	LEN = 0;
	while (n>0)
	{
		BIN[LEN] = n % 2;
		n = n/ 2;
		LEN++;
	};

	for (I = LEN - 1; I>-1; I--)
	{
		printf("%d ", BIN[I]);
	}
	printf("\n");
	LIMIT = P + b;
	if (LIMIT < LEN)
	{
		for (I = P - 1; I<P + b - 1; I++)
		{
			if (BIN[I] == 0)
				BIN[I] = 1;
			else
				BIN[I] = 0;
		}
	}
	

	printf("INVERTED INTEGER IN BINARY FORM IS \t");
	for (I = LEN - 1; I>-1; I--)
	{
		printf("%d ", BIN[I]);
	}
	Y = 0;
	for (I = LEN - 1; I >= 0; I--)
	{
		Y = Y * 2 + BIN[I];
	}
	return Y;
}