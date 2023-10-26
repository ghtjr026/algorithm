/**************************
문제의 핵심 ( 2017 팁스타운 )
1. 유의사항 없음

2. 다른 방법이 얼마든지 있을 것 같음
**************************/
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    bool isdone = true;
    while(isdone)
    {
        answer++;
        queue<int> temp(q);
        queue<int> temp1;
        while(!temp.empty())
        {
            int num = temp.front();
            temp.pop();
            int num1 = temp.front();
            temp.pop();

            if (((num == a) && (num1 == b)) ||
                ((num == b) && (num1 == a)))
            {
                isdone = false;
                break;
            }

            if(num == a || num == b)
            {
                temp1.push(num);
            }
            else if(num1 == a || num1 == b)
            {
                temp1.push(num1);
            }
            else
            {
                temp1.push(num);
            }
        }
        q = temp1;
    }

    return answer;
}

int main()
{
    int n = 8;
    int a = 4;
    int b = 7;

    int result = solution(n, a, b);

    cout << result;

    return 0;
}

