#include<iostream>
using namespace std;
void del(char str[], char ch) {
	int i, j = 0;
	char ch1;
	char str1[10];

	for (i = 0; i < strlen(str); i++) {
		if (str[i] != ch) {
			ch1 = str[i];
			str1[j] = ch1;
			j++;
		}
	}
	str1[j] = '\0';

	cout<<"\ncorrected string is "<<str1<<endl;
}

void main() {
	char str[10];
	char ch;

	cout << "enter the string ";
	cin.getline(str,50);

	cout<<endl<<"Enter character which you want to delete : ";
	cin >> ch;

	del(str, ch);
	system("pause");
}