#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int solution(vector<int> menu, vector<int> order, int k)
{
    int answer = 0;

    vector<int> exit(order.size(), 0);

    int maxTime = 0;
    exit[0] = menu[order[0]];
    for(int idx = 1; idx < order.size(); idx++)
    {
        if(exit[idx - 1] > idx * k)
        {
            exit[idx] = exit[idx - 1] + menu[order[idx]];
        }
        else
        {
            exit[idx] = idx * k + menu[order[idx]];
        }
        maxTime = max(maxTime, exit[idx]);
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    int curTime = -1;
    int people = 0;
    while(curTime != maxTime)
    {
        answer = max(answer, (int)pq.size());
        curTime++;
        if(!pq.empty())
        {
            if(pq.top() == curTime)
            {
                pq.pop();
            }
        }

        if(curTime % k == 0 && people < exit.size())
        {
            pq.push(exit[people++]);
        }
    }

    return answer;
}

int main()
{
    vector<int> menu;
    menu.emplace_back(5);
    menu.emplace_back(12);
    menu.emplace_back(30);

    vector<int> order;
    order.emplace_back(1);
    order.emplace_back(2);
    order.emplace_back(0);
    order.emplace_back(1);

    int k = 10;

    int result = solution(menu, order, k);

    cout << result;

    return 0;
}