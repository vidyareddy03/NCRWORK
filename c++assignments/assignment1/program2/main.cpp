#include<iostream>
#include<string.h>
using namespace std;

class Student
{
public:
	char *name;
	int grade, mark1, mark2, mark3;
};

class CollegeCourse:public Student
{ 
	float avg = 0;
public:
	void set_Data(char *n, int g, int m1, int m2, int m3)
	{
		int len = strlen(n);
		name = (char *)malloc((len +1)* sizeof(char*));
		strcpy(name, n);
		grade = g;
		mark1 = m1;
		mark2 = m2; 
		mark3 = m3;
	}
	void calculateAverage()
	{
		avg = ((mark1 + mark2 + mark3) / 3);

	}
	void computeGrade()
	{
		cout << "student progress is " << endl;
		if (mark1 >= 40 && mark2 >= 40 && mark3 >= 40)
		{
			if (avg >= 60)
			{
				cout << "first class" << endl;
			}
			else if (50 <= avg < 60)
			{
				cout << "second class" << endl;
			}
			else if (40 <= avg <= 50)
			{
				cout << "third class" << endl;
			}
		}
		else
		{
			cout << "fail" << endl;
		}
	}
	void display()
	{
		cout << "name = " << name<<endl;
		cout << "grade = " << grade << endl;
		cout << "marks are" << mark1 << endl << mark2 << endl << mark3 << endl;

	}
};

void main()
{
	CollegeCourse c1, c2;
	c1.set_Data("vidya", 10, 55, 30, 60);
	c1.display();
	c1.calculateAverage();
	c1.computeGrade();
	c2.set_Data("srilatha", 10, 55, 58, 60);
	c2.display();
	c2.calculateAverage();
	c2.computeGrade();
	system("pause");

}