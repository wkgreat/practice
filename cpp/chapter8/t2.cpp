#include<iostream>
#include<cstring>

struct CandyBar
{
	char brand[20];
	double weigth;
	int calories;
};

void func1( CandyBar* const pcb, const char* brand="Millennium Munch", const double weigth=2.85, const int calories=350);
void func2( const CandyBar* pcb);

int main()
{
	CandyBar cb;
	func1(&cb, "MMM");
	func2(&cb);
	return 0;
}

void func1( CandyBar* const pcb, const char* brand, const double weigth, const int calories)
{
	std::strcpy(pcb->brand, brand);
	pcb->weigth=weigth;
	pcb->calories=calories;
}

void func2( const CandyBar* pcb)
{
	std::cout << pcb->brand << " " 
		<< pcb->weigth << " " 
		<< pcb->calories << std::endl;
}
