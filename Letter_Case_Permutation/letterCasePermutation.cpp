#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
using namespace std;

vector<string> generateStr(string S, int count, int size)
{
    vector<string> v;
    int swap = 0;
    bool bSwap = true;
    
    for(int i = 0; i < S.size(); ++i)
    {
        if(isalpha(S[i]))
        {
            swap = pow(2, --count);
            for(int j = 0; j < size; ++j)
            {
                if(bSwap)
                {
                    if(swap <= 0)
                    {
                        bSwap = false;
                    }
                    v[j].push_back(toupper(S[i]));
                    swap--;
                }
                else
                {
                    if(swap > 4)
                    {
                        bSwap = true;
                    }
                    v[j].push_back(tolower(S[i]));
                    swap++;
                }
            }
        }
        else
        {
            for(int j = 0; j < size; ++j) {
                v[j].push_back(S[i]);
            }
        }
    }
    return v;
    
}

vector<string> letterCasePermutation(string S) {
    vector<string> v;
    int countChar = 0;
    
    if(S.empty())
    {
        v.push_back(S);
        return v;
    }
    
    for(char c : S)
    {
        if(isalpha(c)) ++countChar;
    }
    
    if(countChar == 0)
    {
        v.push_back(S);
        return v;
    }
    
    int size = pow(2, countChar);
    v = generateStr(S, countChar, size);
    return v;
}


int main()
{
    string s = "abc";
    vector<string> v;

    v = letterCasePermutation(s);
    for(auto it : v)
    {
        cout << '[' << it << ' ';
    }
    cout << ']' << endl;

    return 0;
}




