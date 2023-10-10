/**************************
문제의 핵심
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    int tempB = brown / 2 + 2;

    for(int num = 1; num < tempB; num++)
    {
        int num1 = tempB - num;

        if((num - 2) * (num1 - 2) == yellow)
        {
            answer.emplace_back(max(num, num1));
            answer.emplace_back(min(num, num1));
            break;
        }
    }

    return answer;
}

int main()
{
    vector<int> results = solution(10, 2);
    
    for(int &result : results)
    {
        cout << result << endl;
    }

    return 0;
}