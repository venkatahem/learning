#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string s = "(())((()))()";
    stack<char> st;

    int score = 0;
    int x = 0;
    int i, j, k;

    for (i = 0; i < s.length(); i++)
    {
        j = 0;
        k = 0;
        if (s[i] == '(')
            st.push(s[i]);
        while (!st.empty() && (i < s.length()))
        {
            i++;
            if (s[i] == ')' && st.top() == '(')
            {
                st.pop();
                k++;
            }
            else if (s[i] == '(')
            {
                j++;
                st.push(s[i]);
            }
        }
        for (int h = 1; h < j; h++)
        {
            k = k * 2;
        }
        score = score + k;
    }

    cout << score;
    return 7;
}