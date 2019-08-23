/*
Good morning! Here's your coding interview problem for today.

This problem was recently asked by Google.

Given a list of numbers and a number k, return whether 

any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return 

true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool addTwo(vector<int> v, int k)
{
	unordered_map<int, int> myMap;

	for(auto it = v.begin(); it != v.end(); ++it)
	{
		if(myMap.find(*it) != myMap.end())
		{
			return true;
		}
		myMap[abs(k - *it)] = 1;
	}

	// didn't find two adds
	return false;

}

int main()
{
	vector<int> v;
	v.push_back(9);
	v.push_back(15);
	v.push_back(3);
	v.push_back(7);

	int k = 22;

	(addTwo(v, k)) ? cout << "true\n" : cout << "false\n";

	return 0;
}




