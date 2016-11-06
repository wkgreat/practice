#include<iostream>
#include<string>

struct Student
{
	std::string firstName;
	std::string lastName;
	char grade;
	unsigned int age;
};

Student* inputStudent();
int printStudent(Student);

int main()
{
	Student* pstu = inputStudent();
	printStudent(*pstu);
	return 0;
}

Student* inputStudent()
{
	using namespace std;
	Student *pstu = new Student;
	cout << "What is your first name? ";
	getline(cin,pstu->firstName);
	cout << "What is yout last name? ";
	getline(cin,pstu->lastName);
	cout << "What letter grade do you deserve? ";
	cin >> pstu->grade;
	cout << "What is your age? ";
	cin >> pstu->age;

	return pstu;
}

int printStudent(Student stu)
{
	using namespace std;
	cout << "Name: " << stu.lastName << ", " << stu.firstName << endl;
	cout << "Grade: " << stu.grade << endl;
	cout << "Age: " << stu.age << endl;

	return 0;
}
