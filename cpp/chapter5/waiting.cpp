#include<iostream>
#include<ctime>

void sleep(float secs);

int main()
{
	using namespace std;
	//cout << "Enter the delay time, in seconds: ";
	//float secs;
	//cin >> secs;

	for(int i=0; i<100; ++i)
	{
		cout << "\r" << i << "%" << flush;
		sleep(0.1);
	}
	cout << endl;

	return 0;
}

void sleep( float secs )
{

	clock_t delay = secs * CLOCKS_PER_SEC;
	clock_t start = clock();	
	while(clock()-start < delay);
}

