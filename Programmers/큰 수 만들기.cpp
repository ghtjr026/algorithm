/**************************
문제의 핵심
1. number를 다 돌았을 때, k가 0이 아닐 때를 주의
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k)
{
    string answer;
    stack<char> list;

    for(char &str : number)
    {
        if(list.empty() || k == 0)
        {
            list.push(str);
            continue;
        }

        while(!list.empty())
        {
            if(k == 0)
            {
                break;
            }

            char num = list.top();
            if(num < str)
            {
                list.pop();
                k--;
            }
            else
            {
                break;
            }
        }

        list.push(str);
    }

    if(k != 0)
    {
        list.pop();
        k--;
    }

    while(!list.empty())
    {
        answer += list.top();
        list.pop();
    }
    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{
    string num = "4177252841";
    int k = 4;

    string result = solution(num, k);

    cout << result;

    return 0;
}