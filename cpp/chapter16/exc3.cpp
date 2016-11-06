#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<iterator>

void upperString( std::string & s);
int main()
{
	std::string s("Hello, world!");
	upperString(s);
	std::cout << std::endl;
	return 0;
}

void upperString( std::string & s)
{
	using namespace std;
	copy( s.begin(), s.end(), s.begin());
	transform( s.begin(), s.end(), s.begin(), static_cast<int(*)(int)>(toupper) );
	copy( s.begin(), s.end(), std::ostream_iterator<char, char>(cout));
}
