#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    stack<char> st;
    cout << "Enter a number : ";
    cin >> str;
    cout << "Entered string is : " << str << endl;

    for (int i = 0; i < str.length(); i++)
    {
        st.push(str[i]);
    }

    for (int i = 0; i < str.length(); i++)
    {
        str[i] = st.top();
        st.pop();
    }
    cout << "Reverse string is : " << str << endl;
    return 0;
}