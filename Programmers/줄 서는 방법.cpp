/**************************
문제의 핵심
1. 변수 타입을 잘 확인할 것

2. 팩토리얼 문제이기 때문에 일정 규칙을 찾아낼 것
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void init(vector<long long> &dp)
{
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i < dp.size(); i++)
    {
        dp[i] = i * dp[i - 1];
    }
}

vector<int> solution(int n, long long k)
{
    vector<int> answer;

    vector<long long> dp(n+1);
    init(dp);

    vector<bool> visited(n+1, false);
    int cnt = 1;
    long long order = 0;
    while(answer.size() != n)
    {
        for(int i = 1; i <= n; i++)
        {
            if(visited[i])
            {
                continue;
            }

            if(k <= order + dp[n-cnt])
            {
                cnt++;
                answer.emplace_back(i);
                visited[i] = true;
                break;
            }
            else
            {
                order += dp[n - cnt];
            }
        }
    }

    return answer;
}

int main()
{
    int n  = 3;
    long long k = 4;

    vector<int> results = solution(n, k);

    for(int result : results)
    {
        cout << result << ' ';
    }

    return 0;
}