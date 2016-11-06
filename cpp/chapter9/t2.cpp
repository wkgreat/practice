#include<iostream>
#include<cstring>

static int theBuffer[10];

struct chaff
{
	char dross[20];
	int slag;
};

int main()
{
	chaff * c = new (theBuffer) chaff;
	std::strcpy(c->dross,"Wangke");
	c->slag = 10;

	std::cout << c->dross << ", " << c->slag << std::endl;
	return 0;

}

