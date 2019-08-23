#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int longestPalindrome(string s)
{
	unordered_map<char, int> m;
	int counter = 0;

	for(char c : s)
	{
		if(m.find(c) == m.end())
			m[c] = 1;
		else
		{
			m[c]++;
			if(m[c] % 2 == 0)
				counter++;
		}
	}
	counter *= 2;
	for(auto it = m.begin(); it != m.end(); ++it)
	{
		if(it->second == 1)
		{
			++counter;
			break;
		}
	}
	return counter;
}

int main()
{
	string s = "abccccdd";

	cout << "enter string: ";
	cin >> s;
	cout << "longestPalindrome: " << longestPalindrome(s) << endl;

	return 0;
}