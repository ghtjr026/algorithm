/**************************
문제의 핵심 ( 2017 팁스타운 )
1. stack을 사용하면 O(n)으로 해결가능
**************************/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> st;

    int idx = 1;
    st.push(s[0]);
    while(idx != s.length())
    {
        st.push(s[idx++]);
        if(st.size() < 2)
        {
            continue;
        }
        char str1 = st.top();
        st.pop();
        char str2 = st.top();
        st.pop();

        if(str1 == str2)
        {
            continue;
        }
        else
        {
            st.push(str2);
            st.push(str1);
        }
    }

    if(st.empty())
    {
        return 1;
    }
    
    return 0;
}

int main()
{
    int result = solution("baccab");

    cout << result;

    return 0;
}