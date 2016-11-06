#include<iostream>
#include"stack.h"

void theVisit(Element & e);

int main()
{
	Stack stack;
	Element e;
	Element e1{"wk", 1};
	Element e2{"qyq", 2};
	Element e3{"djz", 3};
	stack.append(e1);
	stack.append(e2);
	stack.append(e3);

	std::cout << "Visit:\n";
	stack.visit(theVisit);

	std::cout << "POP:\n";
	stack.pop(e);
	std::cout << e << std::endl;
	stack.pop(e);
	std::cout << e << std::endl;
	stack.pop(e);
	std::cout << e << std::endl;
	stack.pop(e);
	std::cout << e << std::endl;
	return 0;
}

void theVisit(Element & e)
{
	std::cout << e << std::endl;
}
