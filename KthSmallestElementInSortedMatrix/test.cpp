#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	int index = 4;


	if(index == v.size())
		cout << v[index] << endl;
	else
		cout << v.size() << endl;

	return 0;
}