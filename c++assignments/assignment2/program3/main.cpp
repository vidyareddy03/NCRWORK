#include<iostream>
using namespace std;
class Employee
{
	int empno, sal;
	char name[20];
public:
	/*Employee()
	{
		empno = 0;
		sal = 0;
		strcpy_s(name, NULL);
	}*/
	void get_data()
	{
		cin >> empno;
		cin >> name;
		cin >> sal;

	}
	friend ostream& operator<<(ostream& cout, Employee e);
};
ostream& operator<<(ostream& cout, Employee e)
{
	cout << e.empno << endl;
	cout << e.name << endl;
	cout << e.sal << endl;
	return cout;
}
void main()
{
	Employee e[5];
	
	int i;
	for (i = 0; i < 5; i++)
	{
		e[i].get_data();
	}
	for (i = 0; i<5; i++)
		cout << e[i];
	system("pause");

}