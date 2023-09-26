/**************************
문제의 핵심
1. stack을 활용한다는 것을 인지할 것
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    int originSize = s.length();
    s += s;

    for (int idx = 0; idx < originSize; idx++)
    {
        stack<char> brackets;
        for (int cnt = 0; cnt < originSize; cnt++)
        {
            if (brackets.empty())
            {
                brackets.push(s[idx + cnt]);
                if ((s[idx + cnt] == ']') ||
                    (s[idx + cnt] == '}') ||
                    (s[idx + cnt] == ')'))
                {
                    break;
                }
                continue;
            }

            char bracket = brackets.top();
            if (((bracket == '[') && (s[idx + cnt] == ']')) ||
                ((bracket == '{') && (s[idx + cnt] == '}')) ||
                ((bracket == '(') && (s[idx + cnt] == ')')))
            {
                brackets.pop();
                continue;
            }

            brackets.push(s[idx + cnt]);
        }

        if (brackets.empty())
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    cout << solution("[](){}");

    return 0;
}