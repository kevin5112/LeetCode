#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generateAllSubstring(vector<string>& v, string s, string temp)
{
	if(s.empty())
	{
		v.push_back(s);
		return;
	}
	
	
}

int main()
{
	string s = "abcabc";
	vector<string> v;
	string temp = "";


	generateAllSubstring(v, s, temp);
	return 0;
}