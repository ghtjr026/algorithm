/**************************
문제의 핵심
1. 정렬을 다음과 같은 경우를 나눠서 할 것

2. 길이가 같은 두 수의 경우, 내림차순으로 정렬해야 함

3. 길이가 다른 두 수의 경우 아래와 같이 동작해야함
-> 두수를 붙였을 때, 더 큰 수가 되는 경우를 찾아야함
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int &lvalue, int &rvalue)
{
    string lstr = to_string(lvalue);
    string rstr = to_string(rvalue);
    if(lstr.length() == rstr.length())
    {
        return lvalue > rvalue;
    }
    else
    {
        if(stoi(lstr + rstr) > stoi(rstr + lstr))
        {
            return true;
        }
        else
        {
            return false;
        }
        // int minlen = min(lstr.length(), rstr.length());
        // int maxlen = max(lstr.length(), rstr.length());

        // if(lstr.length() == minlen)
        // {
        //     while(lstr.length() != maxlen)
        //     {
        //         lstr += lstr.back();
        //     }
        // }
        // else if(rstr.length() == minlen)
        // {
        //     while(rstr.length() != maxlen)
        //     {
        //         rstr += rstr.back();
        //     }
        // }

        // return stoi(lstr) > stoi(rstr);
    }
}

string solution(vector<int> numbers)
{
    string answer = "";

    sort(numbers.begin(), numbers.end(), cmp);

    for(int &num : numbers)
    {
        answer += to_string(num);
    }

    if(answer[0] == '0')
    {
        answer = '0';
    }

    return answer;
}

int main()
{
    vector<int> numbers;
    numbers.emplace_back(979);
    numbers.emplace_back(97);
    numbers.emplace_back(978);
    numbers.emplace_back(81);
    numbers.emplace_back(818);
    numbers.emplace_back(817);

    string result = solution(numbers);

    cout << result;

    return 0;
}