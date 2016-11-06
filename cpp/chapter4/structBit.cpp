#include<iostream>

int main()
{
	using namespace std;

	struct B
	{
		unsigned b1: 1;
		unsigned b2: 1;
		unsigned b3: 1;
		unsigned b4: 1;
		unsigned b5: 1;
		unsigned b6: 1;
		unsigned b7: 1;
		unsigned b8: 1;
	};

	int pa = -1;

	B *pb = (B*)&pa;

	cout << pb->b1;
	cout << pb->b2;
	cout << pb->b3;
	cout << pb->b4;
	cout << pb->b5;
	cout << pb->b6;
	cout << pb->b7;
	cout << pb->b8 << endl;

	return 0;

}
