#include<cstring>
#include"cow.h"

using std::strcpy;
using std::strlen;

Cow::Cow()
{	
	std::cout << "Create Cow.\n";
	strcpy(name,"Unkown");
	hobby = 0;
	weight = 0;
}
Cow::Cow(const char * nm, const char * ho, double wt)
{
	std::cout << "Create Cow.\n";
	strcpy(name, nm);

	hobby = new char[strlen(ho)+1];
	strcpy(hobby, ho);
	
	weight= wt;
}
Cow::Cow(const Cow & c)
{
	std::cout << "Copy Cow.\n";
	strcpy(name, c.name);

	hobby = new char[strlen(c.hobby)+1];
	strcpy(hobby, c.hobby);
	
	weight = c.weight;
}

Cow::~Cow()
{
	std::cout << "Destroy Cow\n";
	delete [] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
	std::cout << "Assign Cow\n";
	strcpy(name, c.name);

	hobby = new char[strlen(c.hobby)+1];
	strcpy(hobby, c.hobby);
	
	weight = c.weight;
	return *this;
}

void Cow::showCow() const
{
	std::cout << "Cow: "
		<< name << "/"
		<< hobby << "/"
		<< weight << ".\n";
}
