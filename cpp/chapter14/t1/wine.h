#ifndef WINE_H_
#define WINE_H_
#include<valarray>
#include"pair.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt,ArrayInt> PairArray;

class Wine
{
	private:
		char * label;
		int year;
		PairArray yb;

	public:
		Wine();
		Wine(const char * l, int y, const int yr[], const int bot[]);
		Wine(const char * l, int y);
		~Wine();
		void getBottles();
		char * getLabel() const { return label; }
		int sum() { return yb.getsecond().sum(); }
		void show();
};


#endif

