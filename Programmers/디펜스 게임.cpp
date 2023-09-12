/**************************
문제의 핵심
1. 최대힙 혹은 우선순위큐 를 사용하여 풀 수 있다는 것을 알아야 함

2. 주석처리된 예외처리가 없어야 성공함
-> 왜인지 모르겠음
-> sum의 type을 long long으로 한다면 범위 초과도 아님
-> 판정 오류가 아닌가 의심스러움
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    long long sum = accumulate(enemy.begin(), enemy.end(), 0);
    if(n >= sum || k >= enemy.size())
    {
        return enemy.size();
    }

    int answer = 0;
    priority_queue<int> pq;

    for(int e : enemy)
    {
        pq.push(e);
        n -= e;

        if(n >= 0)
        {
            answer++;
        }
        else
        {
            if(k != 0)
            {
                k--;
                n += pq.top();
                pq.pop();
                answer++;
            }
            else
            {
                break;
            }
        }
    }

    return answer;
}

int main()
{
    int n = 10;
    int k = 3;

    vector<int> enemy;
    enemy.emplace_back(3);
    enemy.emplace_back(4);

    int round = solution(n, k, enemy);

    cout << round;

    return 0;
}