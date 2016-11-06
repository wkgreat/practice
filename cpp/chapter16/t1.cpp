#include<iostream>
#include<fstream>
#include<string>
#include<iterator>
#include<algorithm>

bool isHuiwen(std::string & s);
std::ofstream fout("temp.txt");

template<typename T>
class AnyUnequal
{
	private:
		bool b;
	public:
		AnyUnequal(){ b=true; }
		bool get() { return b; }
		operator bool() { return b; }
		bool operator()(const T & t1, const T & t2) 
		{
			return (t1==t2);
		}
};

int main()
{
	std::string s;
	while(std::getline(std::cin, s) && (s!="\n"))
	{
		std::cout << s << ":"<< isHuiwen(s) << std::endl;
	}
	return 0;
}

bool isHuiwen(std::string & s)
{
	AnyUnequal<char> aue;
	std::transform( s.rbegin(), s.rend(), s.begin(), std::ostream_iterator<bool,char>(fout," "), aue);
	//std::cout << "aue: " << aue.get() << std::endl;
	return aue.get();
}



