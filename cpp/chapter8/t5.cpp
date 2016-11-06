#include<iostream>

template<typename T> 
T max5(T ts[]);

int main()
{
	int as[5] = {6,3,7,1,3};
	double bs[5] = {3.14, 5.28, 23.1, 0.65, 4.6};
	std::cout << max5(as) << std::endl;
	std::cout << max5(bs);
	return 0;
}

template<typename T>
T max5(T ts[])
{
	T t = ts[0];
	for(int i=0; i<5; ++i)
		if(ts[i] > t)
			t = ts[i];

	return t;

}
