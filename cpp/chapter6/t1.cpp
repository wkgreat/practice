#include<iostream>
#include<cctype>

int main()
{
	using namespace std;
	char ch;

	while(cin.get(ch) && ch!='@')
	{
		if(isupper(ch)) cout.put(tolower(ch));
		else if(islower(ch)) cout.put(toupper(ch));
	}
	return 0;
}
