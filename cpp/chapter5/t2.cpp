#include<iostream>
#include<array>

using namespace std;

int main()
{
	array<long double, 16> jiecheng = {1L, 1L};
	int i;
	for(i=2; i<16; ++i)
		jiecheng[i] = i*jiecheng[i-1];
	for(i=0; i<16; ++i)
		cout << i << "!=" << jiecheng[i] << endl;
	return 0;
}
