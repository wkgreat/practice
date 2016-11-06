#include<iostream>
#include<cstring>
#include"cd.h"

Cd::Cd(char * s1, char * s2, int n, double x)
{
	std::strcpy(performance, s1);
	std::strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & d)
{
	std::strcpy(performance, d.performance);
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	std::strcpy(performance, "Unknown");
	std::strcpy(label, "Unknown");
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd(){}

void Cd::Reprot() const
{
	std::cout
		<< "--Cd--\n"
		<< "|performance: " << performance 
		<< "|label: " << label 
		<< "|selections: " << selections 
		<< "|playtime: " << playtime << "|\n";
}

Cd & Cd::operator=(const Cd & d)
{
	if(this == &d) return *this;
	std::strcpy(performance, d.performance);
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic(char * s1, char * s2, int n, double x, char ** tns):Cd(s1,s2,n,x)
{
	tracknames = new char*[n];
	for(int i=0; i<n; ++i)
	{
		tracknames[i] = new char[std::strlen(tns[i])+1];
		std::strcpy(tracknames[i], tns[i]);
	}
}
Classic::Classic(const Classic & d):Cd(d)
{
	tracknames = new char*[d.getSelections()];
	for(int i=0; i<d.getSelections(); ++i)
	{
		tracknames[i] = new char[std::strlen(d.tracknames[i])+1];
		std::strcpy(tracknames[i], d.tracknames[i]);
	}
}

Classic::Classic():Cd()
{
	tracknames = 0;
}

Classic::~Classic()
{
	for(int i=0; i<Cd::getSelections(); ++i) delete [] tracknames[i];
	delete [] tracknames;
}

void Classic::Reprot() const
{
	std::cout << "----Classic:Cd----\n";
	Cd::Reprot();
	std::cout
		<< "--Tracknames:\n";
	for(int i=0; i<Cd::getSelections();++i)
		std::cout << "|" << tracknames[i] << "|";
	std::cout << std::endl;
}

Classic & Classic::operator=(const Classic & d)
{
	if(this==&d) return *this;
	Cd::operator=(d);

	if(tracknames!=0)
	{
		for(int i=0; i<Cd::getSelections(); ++i) delete [] tracknames[i];
		delete [] tracknames;
	}

	tracknames = new char*[d.getSelections()];
	for(int i=0; i<d.getSelections(); ++i)
	{
		tracknames[i] = new char[std::strlen(d.tracknames[i])+1];
		std::strcpy(tracknames[i], d.tracknames[i]);
	}
	return *this;
}
