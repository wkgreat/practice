#include<iostream>
#include<cstring>
#include"wine.h"

Wine::Wine(){}
Wine::Wine(const char * l, int y, const int yr[], const int bot[])
{
	label = new char[std::strlen(l)+1];
	std::strcpy(label, l);
	year = y;
	yb = PairArray(ArrayInt(year), ArrayInt(year));
	for(int i=0; i<year; ++i)
	{
		yb.getfirst()[i]=yr[i];
		yb.getsecond()[i]=bot[i];
	}
}
Wine::Wine(const char * l, int y)
{
	label = new char[std::strlen(l)+1];
	std::strcpy(label, l);
	year = y;
}

Wine::~Wine()
{
	delete [] label;
}

void Wine::getBottles()
{
	yb = PairArray(ArrayInt(year),ArrayInt(year));
	for(int i=0; i<year; ++i)
	{
		std::cout << i+1 <<" Enter the year and bottles: ";
		std::cin >> yb.getfirst()[i];
		std::cin >> yb.getsecond()[i];
	}
}

void Wine::show()
{
	std::cout << "Label: " << label << std::endl;
	for(int i=0; i<year; ++i)
	{
		std::cout << yb.getfirst()[i] << " "
			<< yb.getsecond()[i] << "\n";
	}
}

