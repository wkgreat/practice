#include<iostream>
#include<list>
#include<string>
#include<iterator>
#include<algorithm>

int main()
{
	std::list<std::string> matfriends;
	std::list<std::string> patfriends;
	std::string s;
	std::cout << "Mat's Friends:\n";
	std::cin.clear();
	while(getline(std::cin,s) && s!="@")
	{
		matfriends.push_back(s);
	}

	std::cout << "Pat's Friends:\n";
	std::cin.clear();
	while(getline(std::cin,s) && s!="@")
	{
		patfriends.push_back(s);
	}

	std::cout << "Mat's: ";
	std::copy(matfriends.begin(),matfriends.end(),std::ostream_iterator<std::string>(std::cout," "));
	std::cout << std::endl;

	std::cout << "Pat's: ";
	std::copy(patfriends.begin(),patfriends.end(),std::ostream_iterator<std::string>(std::cout," "));
	std::cout << std::endl;

	matfriends.sort();
	patfriends.sort();
	matfriends.merge(patfriends);
	matfriends.unique();
	std::cout << "Merge's: ";
	std::copy(matfriends.begin(),matfriends.end(),std::ostream_iterator<std::string>(std::cout," "));
	std::cout << std::endl;

	

	return 0;
}
