/**************************
문제의 핵심 ( Summer/Winter Coding(~2018) )
1. 유의사항 없음
**************************/
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    while(n != 0)
    {
        if(n % 2 == 0)
        {
            n /= 2;
            continue;
        }
        else
        {
            n -= 1;
            ans++;
            continue;
        }
    }

    return ans;
}

int main()
{
    int result = solution(6);

    cout << result;

    return 0;
}