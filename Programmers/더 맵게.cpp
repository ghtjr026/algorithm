/**************************
문제의 핵심
1. priority_queue 사용해야 한다는 것을 인지할 것
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int calcScoville(int hot, int hot1)
{
    return hot + hot1 * 2;
}

int solution(vector<int> scoville, int K) 
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int &hot : scoville)
    {
        pq.push(hot);
    }

    while (!pq.empty())
    {
        if (pq.size() == 1)
        {
            if (K > pq.top())
            {
                pq.pop();
            }
            break;
        }

        if (K <= pq.top())
        {
            break;
        }

        int hot = pq.top();
        pq.pop();
        int hot1 = pq.top();
        pq.pop();

        pq.push(calcScoville(hot, hot1));
        answer++;
    }

    if(pq.empty())
    {
        answer = -1;
    }

    return answer;
}

int main()
{
    vector<int> scoville;
    scoville.emplace_back(1);
    scoville.emplace_back(2);
    scoville.emplace_back(3);
    scoville.emplace_back(9);
    scoville.emplace_back(10);
    scoville.emplace_back(12);
    
    int k = 7;

    int result = solution(scoville, k);

    cout << result;

    return 0;
}