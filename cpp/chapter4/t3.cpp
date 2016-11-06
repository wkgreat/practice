#include<iostream>
#include<cstring>

char* getFullName();

int main()
{
	getFullName();
	return 0;
}

char* getFullName()
{
	using namespace std;

	const int MaxSize = 1024;

	char firstName[MaxSize];
	char secondName[MaxSize];

	cin.getline(firstName, MaxSize);
	cin.getline(secondName, MaxSize);

	char* fullName = new char[strlen(firstName)+strlen(secondName)+2];

	strcat(fullName, firstName);
	strcat(fullName, ", ");
	strcat(fullName, secondName);

	cout << fullName << endl;

	return 0;
}
