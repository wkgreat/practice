#ifndef STAKE_H_
#define STAKE_H_
#include<string>
#include<iostream>


class Customer
{
	private:
		std::string fullname;
		double payment;
	public:
		Customer(std::string fn="Unknown", double pm=10);
		void show() const;
		std::string getFullname() const;
		double getPayment() const;
		friend std::ostream & operator<<(std::ostream & os, const Customer & customer);

};

typedef Customer Element;

class Stack
{
	private:
		static const int Maxsize = 30;
		int size = 0;
		Element data[Maxsize];

	public:
		Stack();
		bool append(const Element & e);
		bool pop(Element & e);
		int isempty() const;
		int isfull() const;
		bool showAll() const;
		void visit(void (*pf)(Element &));
};


#endif
