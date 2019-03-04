#include<iostream>
using namespace std;

int hexToDec(char num[])
{
		int i, len,r,hex=0;
	len = strlen(num);
	for (i = 0; num[i] != '\0'; i++)
	{
		len--;
		if (num[i] >= '0' && num[i] <= '9')
			r = num[i] - 48;
		else if (num[i] >= 'a' && num[i] <= 'f')
			r = num[i] - 87;
		else if (num[i] >= 'A' && num[i] <= 'F')
			r = num[i] - 55;
		hex += r * pow(16, len);
	}
	return hex;
	

}

void compliment(int n)
{
	int num = floor(log2(n)) + 1;
	int cal = ((1 << num) - 1) ^ n;
	cout << "1's compliment is " << cal;
}

void leftShift(int dec, int bits)
{
	dec = dec << bits;
	cout << endl << "after left shifting in decimal " << dec<<endl;
}

void rightShift(int dec, int bits)
{
	dec = dec >> bits;
	cout << endl << "after right shifting in decimal " << dec<<endl;
}

void bitAnd(int dec)
{
	char hex2[10];
	int dec2;
	cout << "enter some hex val ";
	cin >> hex2;
	dec2 = hexToDec(hex2);
	int res = (dec & dec2);
	cout << endl << "after performing bitwise and in decimal " << res<<endl;
}

void bitOr(int dec)
{
	char hex2[10];
	int dec2;
	cout << "enter some hex val ";
	cin >> hex2;
	dec2 = hexToDec(hex2);
	int res = (dec | dec2);
	cout << endl << "after performing bitwise or in decimal " << res<<endl;
}

void bitExOr(int dec)
{
	char hex2[10];
	int dec2;
	cout << "enter some hex val ";
	cin >> hex2;
	dec2 = hexToDec(hex2);
	int res = (dec ^ dec2);
	cout << endl << "after performing bitwise exclusive or in decimal " << res<<endl;
}

int main()
{
	char hex[5];
	int choice,choice2,bits,decval;
	cout << "enter hexa decimal value ";
	cin >> hex;
	decval = hexToDec(hex);
	cout << decval << endl;
	
		cout << "enter the choice" << endl << "1. 1's compliment" << endl << "2. masking" << endl << "3. shifting" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: compliment(decval); break;
		case 2: cout << "enter the choice" << endl << "1. bitwise and" << endl << "2. bitwise or" << endl << "3.bitwise exclusive or" << endl;
			cin >> choice2;
			switch (choice2)
			{
			case 1: bitAnd(decval); break;
			case 2: bitOr(decval); break;
			case 3: bitExOr(decval); break;
			default:cout << "entered the wrong choice"; exit(0);
			}
			break;
		case 3:cout << "enter the choice" << endl << "1. left shift" << endl << "2. right shift" << endl;
			cin >> choice2;
			cout << "enter number of bits ";
			cin >> bits;
			switch (choice2)
			{
			case 1:leftShift(decval,bits); break;
			case 2:rightShift(decval,bits); break;
			default:cout << "entered wrong choice"; exit(0);
			}
			break;
		default: cout << endl << "entered wrong choice"; exit(0);
		}
	
		system("pause");
}