/**************************
문제의 핵심
1. 수를 비트로 변환했을 때 우측을 기준으로 0이 가장 처음 나오는 자리를 확인할 것

2. 0이 처음 나오는 자리의 한자리 밑의 수를 더하면 가장 작은 수가 나옴
-> e.g. 
11011 -> 11011 + 00010 = 11101
01111 -> 01111 + 01000 = 10111
101 -> 101 + 001 = 110
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getZero(long long num)
{
    int cnt = 0;
    while(num != 0)
    {
        int remain = num % 2;
        num /= 2;
        if(remain == 0)
        {
            break;
        }
        cnt++;
    }
    return cnt;
}

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for(long long num : numbers)
    {
        if(num % 2 == 0)
        {
            answer.emplace_back(num + 1);
            continue;
        }
        
        int count = getZero(num);
        answer.emplace_back(num + pow(2, count - 1));
    }

    return answer;
}

int main()
{
    vector<long long> numbers;
    numbers.emplace_back(13);

    vector<long long> results = solution(numbers);

    for(long long &result : results)
    {
        cout << result << endl;
    }

    return 0;
}