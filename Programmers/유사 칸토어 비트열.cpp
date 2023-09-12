/**************************
문제의 핵심
1. 전체 bit List를 구하면 시간초과가 걸림

2. 5개씩 묶음으로 자를 수 있음

3. 규칙은 11011 11011 0000 11011 11011 이 반복됨
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long calculateResult(int n, long long goal)
{
    vector<int> cnt= {1,2,2,3,4};
    long long count = 0;
    while(n != 1)
    {
        long long divide = pow(5, n - 1);
        long long multi = pow(4, n - 1);
        long long value = goal / divide;
        if(value < 3)
        {
            count += value * multi;
            goal = goal % divide;
            if(value == 2)
            {
                goal = 0;
            }
        }
        else
        {
            count += (value - 1) * multi;
            goal = goal % divide;
        }
        n--;
    }

    if(goal != 0)
    {
        count += cnt[goal - 1];
    }
    return count;
}

int solution(int n, long long l, long long r)
{
    long long cntLeft = calculateResult(n, l - 1);
    long long cntRight = calculateResult(n, r);

    return cntRight - cntLeft;
}

int main()
{
    int result = solution(2, 15, 15);

    return 0;
}