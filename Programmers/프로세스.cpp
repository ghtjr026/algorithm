/**************************
문제의 핵심
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    queue<pair<int, int>> process;
    
    int number = 0;
    int maxPriority = -1;
    map<int, int> priorityCnt;
    for(int &priority : priorities)
    {
        process.push({priority, number++});
        priorityCnt[priority]++;
        maxPriority = max(maxPriority, priority);
    }

    while(!process.empty())
    {
        if(priorityCnt[maxPriority] == 0)
        {
            while(maxPriority--)
            {
                if(priorityCnt[maxPriority] != 0)
                {
                    break;
                }
            }
        }

        pair<int, int> current = process.front();
        process.pop();

        if(current.first == maxPriority)
        {
            answer++;
            if(current.second == location)
            {
                break;
            }
            priorityCnt[maxPriority]--;
            continue;
        }
        process.push(current);
    }

    return answer;
}

int main()
{
    vector<int> priorities;
    priorities.emplace_back(2);
    priorities.emplace_back(1);
    priorities.emplace_back(3);
    priorities.emplace_back(2);

    int location = 2;

    int result = solution(priorities, location);

    cout << result;

    return 0;
}