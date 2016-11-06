#include<iostream>
#include"complex.h"

int main()
{
	Complex c1(1,1);
	Complex c2(2,2);

	std::cout << c1 << " " << c2 << std::endl;

	Complex c3 = c1+c2;
	std::cout << "c3: " << c3 << std::endl;

	Complex c4 = 5;
	std::cout << "c4: " << c4 << "\n";

	Complex c5 = c1 + 10;
	std::cout << "c5: " << c5 << "\n";

	Complex c6;
	std::cout << "Enter a Complex: ";
	std::cin >> c6;
	std::cout << c6;
	return 0;
}
