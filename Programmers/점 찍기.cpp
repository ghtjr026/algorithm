/**************************
문제의 핵심
1. 원 둘레안의 점의 수를 구하는 것이 핵심
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long GetInsidePoint(int x, int round, int k)
{
    double maxY = sqrt((1.0*round*round) - (1.0*x*x));
    long long maxToInt = (int)maxY;

    long long result = maxToInt / k;

    return result + 1;
}

long long solution(int k, int d)
{
    long long answer = 0;

    answer = GetInsidePoint(0, d, k);
    for(int x = k, idx = 2; x <= d; idx++)
    {
        answer += GetInsidePoint(x, d, k);
        x = k * idx;
    }

    return answer;
}

int main()
{
    int k = 2;
    int d = 4;

    long long result = solution(k, d);

    cout << result;

    return 0;
}