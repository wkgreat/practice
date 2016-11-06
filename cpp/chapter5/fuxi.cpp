#include<iostream>

int fuxi6(void);

int main()
{
	using namespace std;
	int i;
	for(i=0;i<5;i++)
		cout << i;
	cout << endl;

	int j;
	for(j=0;j<11;j+=3)
		cout << j;
	cout << endl << j << endl;

	j=5;
	while(++j<9)
		cout << j++ << endl;

	int k=8;
	do
		cout << "k = " << k <<endl;
	while (k++ < 5);

	fuxi6();

	int x = (1, 024);
	cout << x << endl;

	int y;
	y = 1, 024;
	cout << y << endl;

	return 0;

}

int fuxi6(void)
{
	using namespace std;
	int i;
	for(i=1;i<=64;i*=2) cout << i << " ";
	cout << endl;
	return 0;
}
