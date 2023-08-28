/**************************
문제의 핵심
1. 두 점 사이의 거리를 구하는 공식을 알아야 하는것

2. 내부 원의 테두리에 걸치는 점은 내부 점이라는 사실
**************************/
#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

long long GetInsidePoint(int x, int round, string rName);

/*
루트((x2 - x1)^2 + (y2 - y1)^2)
*/
long long solution(int r1, int r2)
{
    long long answer = 0;

    // 반지름 내부 점의 수
    for(int x = 1; x < r2; x++)
    {
        if(x < r1)
        {
            //r2 - r1
            answer += GetInsidePoint(x, r2, "r2") - GetInsidePoint(x, r1, "r1");
        }
        else
        {
            answer += GetInsidePoint(x, r2, "r2");
        }
        cout << answer << endl;
    }

    answer *= 4;

    //선에 있는 점
    answer += ((r2 - r1 + 1) * 4);

    return answer;
}

long long GetInsidePoint(int x, int round, string rName)
{
    double maxY = sqrt((1.0*round*round) - (1.0*x*x));
    long long maxToInt = (int)maxY;

    if(rName.compare("r1") == 0 && maxY - maxToInt == 0.0)
    {
        maxToInt -= 1;
    }

    return maxToInt;
}

int main()
{
    long long answer = 0;

    while(true)
    {
        answer = 0;
        
        int r1 = 0;
        int r2 = 0;
        cin >> r1 >> r2;

        if((r1 == -1) && (r2 == -1))
        {
            break;
        }

        answer = solution(r1, r2);
        cout << answer << endl;
    }

    return 0;
}