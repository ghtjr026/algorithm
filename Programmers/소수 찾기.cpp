/**************************
문제의 핵심
1. next_permutation은 해당 수가 '반드시' 오름차순으로 정렬되어 있어야함을 유의
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

void makeNum(string numbers, set<int> &allNum)
{
    for(int i = 1; i < numbers.size() + 1; i++)
    {
        do
        {
            string temp = "";
            for(int idx = 0; idx < i; idx++)
            {
                temp += numbers[idx];
            }
            
            if(temp != "")
            {
                allNum.insert(stoi(temp));
            }

        } while (next_permutation(numbers.begin(), numbers.end()));
    }
}

bool isDecimal(int num)
{
    bool isDecimal = true;

    if(num == 2 || num == 3)
    {
        return isDecimal;
    }

    for (int i = 2; i <= sqrt(num) + 1; i++)
    {
        if (num % i == 0)
        {
            isDecimal = false;
            break;
        }
    }

    return isDecimal;
}

int solution(string numbers)
{
    int answer = 0;

    set<int> allNum;

    sort(numbers.begin(), numbers.end());
    makeNum(numbers, allNum);

    for(auto &num : allNum)
    {
        if(num > 1 && isDecimal(num))
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    int result = solution("4321");

    cout << result;

    return 0;
}