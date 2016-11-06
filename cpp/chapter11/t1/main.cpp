#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include"vector.h"


int rambler(double distance, double stepsize);

int main()
{
	rambler(100,20);
	return 0;
}

int rambler(double distance, double stepsize)
{
	using namespace std;
	using VECTOR::Vector;
	Vector step;

	std::srand(std::time(0));
	std::ofstream fout;
	fout.open("route.txt");
	
	Vector route;
	fout << route << endl;;
	std::cout << route << endl;;

	while(route.magval() < distance)
	{
		step.pol_mode();
		step.reset(stepsize, std::rand()*360);
		route = route + step;
		fout << route <<endl;
		std::cout << route << endl;
	}

	return 0;
}


