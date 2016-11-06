#include<iostream>
#include<cstring>
#include"golf.h"

void setgolf(golf & g, const char * name, int hc)
{
	std::strcpy(g.fullname, name);
	g.handicap=hc;
}

int setgolf(golf & g)
{
	using namespace std;
	char fullname[Len];
	int hc;

	cout << "Fullname: ";
	cin.getline(fullname,Len);
	cout << "Handicap: ";
	(cin >> hc).get();
	if(strlen(fullname)==0) return 0;
	else
	{
		strcpy(g.fullname, fullname);
		g.handicap = hc;
		return 1;
	}
	
	
}

void handicap(golf & g, int hc)
{
	g.handicap=hc;
}

void showgolf(const golf & g)
{
	std::cout << "Fullname: " << g.fullname << std::endl;
	std::cout << "Handicap: " << g.handicap << std::endl;
}
