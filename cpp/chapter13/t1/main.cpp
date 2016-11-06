#include"cd.h"

int main()
{
	Cd cd("perform1", "label1", 5, 2);
	cd.Reprot();
	char* tracks[5] = {"Hello", "World", "Good", "Bye", "Fine"};
	Classic cla1("perform2", "label2", 5, 2, tracks);
	cla1.Reprot();
	Classic cla2 = cla1;
	cla2.Reprot();
	return 0;
}
