#include<iostream>
using namespace std;
class Student
{
	int rollno;
	char name[20];
	int m1, m2, m3,tot;
	float grade;
public:
	friend ostream& operator<<(ostream& cout, Student s);
	friend istream& operator>>(istream& cin, Student &s);
	friend void generate_details(Student s[], int n);
};
ostream& operator<<(ostream& cout, Student s)
{
	cout << "rool no is " << s.rollno << endl;
	cout << "name is " << s.name << endl;
	cout << "total marks is " << s.tot<<endl;//s.m1 + s.m2 + s.m3 << endl;
	cout << "grade is " << s.grade << endl;//(s.m1 + s.m2 + s.m3) / 3 << endl;
	return (cout);

}
istream& operator>>(istream& cin, Student &s1)
{
	cin >> s1.rollno;
	cin >> s1.name;
	cin >> s1.m1 >> s1.m2 >> s1.m3;
	return (cin);

}
void generate_details(Student s[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{ 
		s[i].tot = s[i].m1 + s[i].m2 + s[i].m3;
		s[i].grade = s[i].tot / 3;
	}
}

void main()
{
	Student s[3];
	int i;
	for(i=0;i<3;i++)
	cin >> s[i];
	generate_details(s, 3);
	for(i=0;i<3;i++)
	cout << s[i];
	system("pause");
}