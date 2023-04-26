/**************************
이 문제의 핵심
1. DP라는 것을 파악하는 것
 1)DP의 식
 Ax = A(x-1) + 2A(x-2) + 5A(x-3) + 2A(x-4) + 2A(x-5) + 4A(x-6) + ...

2. 위 식에서 -4 부터 2, 2, 4 가 반복됨
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define DIV 1000000007

vector<unsigned long long> dp(100001, 0);
vector<unsigned long long> sum(100001, 0);

int solution(int n) {
    sum[1] = dp[1] = 1;
    sum[2] = dp[2] = 3;
    sum[3] = dp[3] = 10;

    for(int i = 4; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2] * 2 + dp[i - 3] * 5) % DIV;
        if(i > 4) dp[i] = (dp[i] + sum[i - 4] * 2) % DIV;
        if(i > 5) dp[i] = (dp[i] + sum[i - 5] * 2) % DIV;
        if(i > 6) dp[i] = (dp[i] + sum[i - 6] * 4) % DIV;
        if(i % 3 == 1) dp[i] = (dp[i] + 2) % DIV;
        else if(i % 3 == 2) dp[i] = (dp[i] + 2) % DIV;
        else if(i % 3 == 0) dp[i] = (dp[i] + 4) % DIV;
        sum[i] = (sum[i - 3] + dp[i]) % DIV;
    }

    for(int i = 1; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;

    for(int i = 1; i <= n; i++)
    {
        cout << sum[i] << " ";
    }
    cout << endl;
    return dp[n] % DIV;
}

int main() {
    int n = 10;
    cout << solution(n) << endl; // expected output: 396
    return 0;
}