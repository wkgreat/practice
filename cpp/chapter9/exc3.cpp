#include<iostream>


int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	double x;
	cout << "Enter Value: ";
	while(! (cin >> x))
	{
		cout << "Bad Input. Please enter a number: ";
		cin.clear();
		while( cin.get() != '\n') continue;
	}

	cout << "Value = " << x << endl;
	return 0;
}
