#include<iostream>
#include"golf.h"

int main()
{
	using namespace std;
	golf g1;
	golf g2;

	setgolf(g1, "Wangke", 30);
	showgolf(g1);
	while(!setgolf(g2)) cout << "Fullname CANNOT be Empty. Enter again!" << endl;
	showgolf(g2);
	handicap(g1,0);
	showgolf(g1);


	return 0;
}
