#include<iostream>
#include<cstring>

template<typename T>
T maxn(T ts[], int n);

template <> char* maxn<char*>( char* * strs, int n);

int main()
{
	int as[] = {5,6,7,1,2,3};
	double ds[] = {1.1, 2.2, 3.3, 9.9, 8.8};
	char *ss[] = {"abc", "abcd", "aaaaa", "asdf", "ddd"};

	std::cout << maxn(as,6) << std::endl;
	std::cout << maxn(ds,5) << std::endl;
	std::cout << maxn(ss,5) << std::endl;
	return 0;
}

template<typename T>
T maxn(T ts[], int n)
{
	T t = ts[0];
	for(int i=0; i<n; ++i)
		if(ts[i] > t)
			t = ts[i];

	return t;
}

template <> char* maxn<char*>( char* * strs, int n)
{
	char *s = strs[0];
	for(int i=0; i<n; ++i)
		if(std::strlen(strs[i]) > std::strlen(s))
			s = strs[i];

	return s;
}
