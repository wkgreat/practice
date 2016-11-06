#include<iostream>

using namespace std;

int func1();

int main()
{
	func1();
	return 0;
}

int func1()
{
	static int count = 0;
	++count;
	cout << count << endl;
	if(count < 10) func1();
	return 0;
}
