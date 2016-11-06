#include<iostream>
#include"bank.h"

Bank::Bank(const std::string name, const std::string id, const double balance)
{
	name_ = name;
	id_ = id;
	balance_ = balance;
}

void Bank::showInfo() const
{
	std::cout << "Name: " << name_ << std::endl;
	std::cout << "ID: " << id_ << std::endl;
	std::cout << "Balance: " << balance_ << std::endl;
}

