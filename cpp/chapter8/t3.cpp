#include<iostream>
#include<cctype>
#include<string>

using namespace std;

int func1(string & ps);

int main()
{
	string s;
	while(cin >> s)
	{
		func1(s);
		cout << s << endl;
	}
	return 0;
}

int func1(string & ps)
{
	for(int i=0; i<ps.length(); ++i)
		ps[i] = toupper(ps[i]);

	return 0;
}
