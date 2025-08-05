#include <bits/stdc++.h>
using namespace std;
string rev(string s)
{
    int left = 0, right = s.size() - 1;
    while (left <= right)
    {
        if (s[left] == '(')
            s[left] = ')';
        else if (s[left] == ')')
            s[left] = '(';
        else if (s[right] == '(')
            s[right] = ')';
        else if (s[right] == ')')
            s[right] = '(';
        swap(s[left++], s[right--]);
    }
    return s;
}
int priority(char ch)
{
    switch (ch)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}
string intopr(string s)
{
    string ans = "";
    stack<char> st;
    s = rev(s);
    for (auto ch : s)
    {
        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9'))
            ans += ch;
        else if (ch == '(')
            st.push(ch);
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (ch == '^')
            {
                while (!st.empty() && priority(ch) <= priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && priority(ch) < priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(ch);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return rev(ans);
}

int main()
{
    string s = "(a+b)*c-d+f";
    cout << intopr(s);
    return 0;
}
