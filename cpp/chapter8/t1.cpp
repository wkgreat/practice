#include<iostream>
#include<string>
using namespace std;
int count=0;
void printStr(string s, int n=0);

int main()
{
	string s = "The edge of glory!";
	printStr(s);
	printStr(s,0);
	printStr(s,1);
	printStr(s,1);
	printStr(s,1);
	printStr(s,1);
	printStr(s,1);
	return 0;
}

void printStr(string s, int n)
{
	++count;
	if(n>0)
	{
		for(int i=0; i<count; ++i) cout<<s;
	}
	else
	{
		cout<<s;
	}
	cout << endl;
}
