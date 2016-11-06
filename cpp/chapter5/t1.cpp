#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cout << "Please enter two number: ";
	cin >> a >> b;

	int i, sum=0;
	for(i=a; i<=b; ++i)
		sum+=i;
	cout << "Result: " << sum << endl;
	return 0;
}
