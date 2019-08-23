#include<iostream>
#include<stack>
#include<string>
using namespace std;

string removeOuterParentheses(string S) {
        if(S.empty()) return S;
        
        stack<char> myStack;
        int begIndex = 0;
        int endIndex;
        string newS = "";

        for(int i = 0; i < S.size(); ++i)
        {   
            if(S[i] == '(')
            {
                myStack.push(S[i]);
            }
            else
            {
                myStack.pop();
            }
            if(myStack.empty())
            {
                endIndex = i;
                newS.append(S.substr(begIndex + 1, endIndex - begIndex - 1));
                begIndex = ++endIndex;
            }
        }
        return newS;        
}

int main()
{
    string S = "()()";

    cout << S << endl;

    S = removeOuterParentheses(S);

    cout << S << endl;

    return 0;
}
