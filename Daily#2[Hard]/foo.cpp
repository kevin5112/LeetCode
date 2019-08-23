/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Uber.

Given an array of integers, return a new array such that 

each element at index i of the new array is the product 

of all the numbers in the original array except the one 

at i.

For example, if our input was [1, 2, 3, 4, 5], the 

expected output would be [120, 60, 40, 30, 24]. If 

our input was [3, 2, 1], the expected output would 

be [2, 3, 6].

Follow-up: what if you can't use division?
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


vector<int> addArray(vector<int> v)
{
	vector<int> newVec;
	unordered_map<int, int> myMap;

	for(int i = 0; i < v.size(); ++i)
	{			
		int prev = 1;
		if(i > 0)
		{
			for(int k = 0; k < i; ++k)
			{
				prev *= v[k];
			}
		}

		for(int j = i + 1; j < v.size(); ++j)
		{
			prev *= v[j]; 
		}
		myMap[i] = prev;
	}

	for(int i = 0; i < v.size(); ++i)
	{
		newVec.push_back(myMap[i]);
	}

	return newVec;
}

vector<int> addArray2(vector<int> v)
{
	int num = 1;
	for(auto it = v.begin(); it != v.end(); ++it)
	{
		num *= *it;
	}

	vector<int> newVec;
	for(auto it = v.begin(); it!= v.end(); ++it)
	{
		newVec.push_back(num / *it);
	}
	return newVec;
}

vector<int> addArray3(vector<int> v)
{
	int num = 1;
	for(auto it = v.begin(); it != v.end(); ++it)
	{
		num *= *it;
	}

	vector<int> newVec;
	for(auto it = v.begin(); it!= v.end(); ++it)
	{
		int carry, partialSum, a = num, b = *it;
		do {
			partialSum = a ^ b;
			carry = (a & b) << 1;
			a = partialSum;
			b = carry;
		} while(carry != 0);
		newVec.push_back(partialSum);
	}
	return newVec;
}


int main()
{	
	vector<int> myVec;

	myVec.push_back(1);
	myVec.push_back(2);
	myVec.push_back(3);
	myVec.push_back(4);
	myVec.push_back(5);

	for(auto it = myVec.begin(); it != myVec.end(); ++it)
	{
		cout << *it << ' ';
	}
	cout << endl;

	vector<int> n;
	n = addArray3(myVec);

	for(auto it = n.begin(); it != n.end(); ++it)
	{
		cout << *it << ' ';
	}
	cout << endl;

	return 0;
}


