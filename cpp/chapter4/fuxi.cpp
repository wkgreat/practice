#include<iostream>
#include<array>
#include<string>
#include<vector>


using namespace std;

int main()
{


	array<char,30> actor;
	array<short,100> betsie;
	array<float,13> chuck;
	array<long double, 64> dipsea;


	int jishu[5] = {1,3,5,7,9};
	int even = jishu[0]+jishu[4];

	char s1[] = {"cheeseburger"};

	string s2 = "Waldorf Salad";

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << endl;

	struct Fish
	{
		string type;
		int weight;
		float length;
	};

	struct Fish fish = {"gold fish", 20, 3.5l};

	enum Response {Yes=1, No=0, Maybe=2};
	
	double ted=0;
	double *pted = &ted;
	cout << "ted: " << *pted << endl;
	
	float treacle[10] {1,0};
	float *ptreacle = treacle;
	cout << "treacle[0]: " << *ptreacle << 
		" treacle[last]: " << *(ptreacle+9) << endl;

	int maxLen;
	cout << "Enter maxLen:____\b\b\b\b";
	cin >> maxLen;
	cin.get();
	int *shuzu = new int[maxLen];
	vector<int> v(maxLen);

	cout << (int*)"Home of the jolly bytes" << endl;
	cout << "Home of the jolly bytes" << endl;

	Fish *pfish = new Fish;
	pfish->type = "black fish";
	pfish->weight = 10;
	pfish->length = 13.4;
	cout << pfish->type << endl;
	delete pfish;

	const int MaxSize = 50;
	char name[MaxSize];
	cout << "Enter a string: ";
	cin.getline(name,MaxSize);
	cout << "Name1: " << name << endl;
	cin.getline(name,MaxSize);
	cout << "Name2: "<< name << endl;

	const int TheLen = 10;
	std::vector<std::string> v2(TheLen);
	std::array<std::string, TheLen> a2;

	return 0;
}
