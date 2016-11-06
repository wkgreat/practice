#include<iostream>
using namespace std;

int main()
{
	double numbers[10]{0};
	int i=0;
	while(i<10 && cin >> numbers[i]) ++i;
	for(double d:numbers) cout << d << " ";
	return 0;
}
