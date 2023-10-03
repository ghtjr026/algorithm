/**************************
문제의 핵심 ( Summer/Winter Coding(2019) )
1. 두 점을 지나는 직선의 방정식 구하기
-> y - y1 = y2 - y1 / x2 - x1 * ( x - x1 )
(0, 0) / (w, h)
w = -8 / y = 12
(x1, y1) / (x2, y2)

y - 0 = 12 - 0 / -8 - 0 * ( x - 0 )

2. h/w * i 로 하면 6번 테스트 케이스가 실패함을 유의할 것
-> 곱셈 후 나눗셈으로 해결
**************************/
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int w,int h)
{
    long long answer = 0;
    for(int i = 1; i < w; i++)
    {
        long long num = (long long)((double)h * i / w);
        answer += num;
    }

    answer *= 2;

    return abs(answer);
}

int main()
{
    long long answer = solution(4, 8);

    cout << answer;

    return 0;
}