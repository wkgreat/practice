#include<iostream>

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

inline void func1(box b) 
{
	std::cout << b.maker;
	std::cout << b.height;
	std::cout << b.width;
	std::cout << b.length;
	std::cout << b.volume << std::endl;
}

inline void func2(box * pb)
{
	pb->volume = pb->height * pb->width * pb->length;
}

int main()
{
	struct box b = {"wk",1,2,3,1};
	func1(b);
	func2(&b);
	func1(b);
	return 0;
}
