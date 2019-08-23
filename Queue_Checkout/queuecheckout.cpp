#include <iostream>
#include <vector>
using namespace std;

void printArray(int array[], int elems)
{
	for(int i = 0; i < elems; ++i)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
}

void printVector(vector<int> v)
{
	for(int i : v)
	{
		cout << i << ' ';
	}
	cout << endl;
}

int queueCheckout(vector<int> v, int n)
{
	if(v.empty()) return 0;
	if(v.size() == 1) return v[0];

	int array[n];
	int counter = 0;
	printVector(v);

	for(int i = 0; i < n; ++i)
	{
		array[i] = v.front();
		v.erase(v.begin());
	}

	while(true)
	{
		for(int i = 0; i < n; ++i)
		{
			if(array[i] == 0)
			{
				array[i] = v.front();
				v.erase(v.begin());
			}
			else
			{
				array[i]--;
			}
		}
		if(v.empty())
			break;
		counter++;

	}

	return counter;
}

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);

	cout << queueCheckout(v, 2) << endl;

	return 0;
}