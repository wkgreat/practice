#ifndef PAIR_H_
#define PAIR_H_
#include<iostream>

template<typename T1, typename T2>
class Pair
{
	private:
		T1 _first;
		T2 _second;
	public:
		Pair() {}
		Pair(T1 first, T2 second) { _first=first; _second=second;}
		~Pair() {}
		T1 & getfirst() { return _first; }
		T2 & getsecond() { return _second; }
		template<typename operT1, typename operT2> 
			friend std::ostream & operator<<(std::ostream & os, const Pair<operT1,operT2> & pair);
};


template<typename operT1, typename operT2>
std::ostream & operator<<(std::ostream & os, const Pair<operT1,operT2> & pair)
{
	return os << "Pair(" << "First:"<< pair._first << ", " << "Second:"<< pair._second << ")";
}


#endif
