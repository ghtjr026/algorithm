/**************************
문제의 핵심 ( Blind kakao test)
1. deliveries / pickups를 역순으로 계산해야 함

2. 짐이 남아 있거나, 빈 공간이 남아 있을 때의 경우를 생각해야 함
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;

    vector<pair<int, int>> list; // deliveries, pickups
    for (int idx = 0; idx < n; idx++)
    {
        pair<int, int> home(deliveries[idx], pickups[idx]);
        list.emplace_back(home);
    }

    // int cntFinish = 0;
    while (!list.empty())
    {
        int currentCap = cap;
        pair<int, int> visitedHome = list.back();

        if (visitedHome.first == 0 && visitedHome.second == 0)
        {
            list.pop_back();
            continue;
        }

        // calculate distance
        answer += list.size() * 2;

        // check deliveries
        for(int idx = list.size() - 1; idx >= 0; idx--)
        {
            if(list[idx].first < currentCap)
            {
                currentCap -= list[idx].first;
                list[idx].first = 0;
            }
            else
            {
                list[idx].first -= currentCap;
                break;
            }
        }     
        
        currentCap = cap;
        // check pickups
        for(int idx = list.size() - 1; idx >= 0; idx--)
        {
            if(list[idx].second < currentCap)
            {
                currentCap -= list[idx].second;
                list[idx].second = 0;
            }
            else
            {
                list[idx].second -= currentCap;
                break;
            }
        }
    }

    return answer;
}

int main()
{
    int cap = 2;
    int n = 7;

    vector<int> deliveries;
    vector<int> pickups;

    // get deliveries & pickups
    deliveries.emplace_back(1);
    deliveries.emplace_back(0);
    deliveries.emplace_back(2);
    deliveries.emplace_back(0);
    deliveries.emplace_back(1);
    deliveries.emplace_back(0);
    deliveries.emplace_back(2);

    pickups.emplace_back(0);
    pickups.emplace_back(2);
    pickups.emplace_back(0);
    pickups.emplace_back(1);
    pickups.emplace_back(0);
    pickups.emplace_back(2);
    pickups.emplace_back(0);

    long long answer = solution(cap, n, deliveries, pickups);

    cout << answer << endl;

    return 0;
}