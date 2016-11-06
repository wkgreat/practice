#include"bank.h"

int main()
{
	Bank b("Wangke", "141302097", 100000);
	b.showInfo();
	b.save(1234);
	b.showInfo();
	b.withdraw(1000);
	b.showInfo();
	return 0;
}
