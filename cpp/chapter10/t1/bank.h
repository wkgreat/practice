#ifndef bank_h_
#define bank_h_
#include<string>

class Bank
{
	private:
		std::string name_;
		std::string id_;
		double balance_;

	public:
		Bank(const std::string name = "unknown", const std::string id="00000", const double balance=0);
		void showInfo() const;
		void save(const double balance) { balance_ += balance; }
		void withdraw(const double balance) { balance_ -= balance; }
};

#endif
