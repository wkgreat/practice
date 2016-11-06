#include<iostream>

template<typename T>
T theMax(T a, T b);

int main()
{
	int a=1,b=3;
	double da=1.0,db=2.0;
	std::cout << theMax(a,b) << std::endl;
	std::cout << theMax(da,db) << std::endl;
	return 0;
}

template<typename T>
T theMax(T a, T b)
{
	return (a>b)?a:b;
}
