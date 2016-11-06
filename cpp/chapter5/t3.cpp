#include<iostream>

using namespace std;

int main()
{
	int i, sum=0;
	do
	{
		cin >> i;
		sum += i;
		cout << "sum: " << sum << endl;
	}while(i!=0);

	return 0;
}
