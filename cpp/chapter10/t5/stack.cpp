#include<iostream>
#include"stack.h"

Customer::Customer(std::string fn, double pm)
{
	fullname = fn;
	payment = pm;
}

void Customer::show() const
{
	std::cout << "|Fullname: "<< fullname << "\t|\t" << "Payment: " << payment << std::endl;
}

std::string Customer::getFullname() const
{
	return fullname;
}
double Customer::getPayment() const
{
	return payment;
}


Stack::Stack(){}

bool Stack::append(const Element & e)
{
	if(isfull())
	{
		std::cout << "Stack is FULL!\n";
		return 0;
	}
	else
	{
		data[size++] = e;
		return 1;
	}
}

bool Stack::pop(Element & e)
{
	if(isempty())
	{
		std::cout << "Stack is EMPTY!\n";
		return 0;
	}
	else
	{
		e = data[--size];
		return 1;
	}
}

int Stack::isempty() const
{
	if(size==0) return 1;
	else return 0;
}

int Stack::isfull() const
{
	if(size==Maxsize) return 1;
	else return 0;
}

void Stack::visit(void (*pf)(Element &))
{
	for(int i=0; i<size; ++i)
		(*pf)(data[i]);
}

std::ostream & operator<<(std::ostream & os, const Customer & customer)
{
	std::cout << "| Fullname: " << customer.fullname << " | Payment: " << customer.payment << " |";
	return std::cout;
}
