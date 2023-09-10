/**************************
문제의 핵심
1. DP 식을 알아차려야 할 것

문제 방법
1. x에 n을 더함

2. x에 2를 곱함

3. x에 3을 곱함
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(int x, int y, int n)
{
    int answer = 0;

    if(x != y)
    {
        vector<int> dp(y + 1, INT_MAX);
        dp[x] = 0;

        for(int idx = x; idx < y + 1; idx++)
        {
            if(dp[idx] == INT_MAX)
            {
                continue;
            }

            if(idx + n <= y)
            {
                dp[idx + n] = min(dp[idx + n], dp[idx] + 1);
            }

            if(idx * 2 <= y)
            {
                dp[idx * 2] = min(dp[idx * 2], dp[idx] + 1);
            }

            if(idx * 3 <= y)
            {
                dp[idx * 3] = min(dp[idx * 3], dp[idx] + 1);
            }
        }

        if(dp[y] == INT_MAX)
        {
            answer = -1;
        }
        else
        {
            answer = dp[y];
        }
    }

    return answer;
}

int main()
{
    int x;
    int y;
    int n;

    //get x, y, n

    int count = solution(x, y, n);

    cout << count;

    return 0;
}