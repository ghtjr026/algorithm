/**************************
문제의 핵심
1. 10개씩 확인
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;

    //per 10
    for (int i = 0; i < discount.size() - 9; i++)
    {
        bool isPossible = true;
        for (int idx = 0; idx < number.size(); idx++)
        {
            if (number[idx] != count(discount.begin() + i, discount.begin() + i + 10, want[idx]))
            {
                isPossible = false;
                break;
            }
        }
        
        if(isPossible)
        {
            answer++;
        }
    }

    return answer;
}

int main()
{


    return 0;
}