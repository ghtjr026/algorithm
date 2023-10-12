/**************************
문제의 핵심
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;

    deque<int> bridge;
    for(int idx = 0 ; idx < bridge_length; idx++)
    {
        bridge.push_front(0);
    }

    int truckIdx = 0;
    int currentWeight = 0;

    while(truckIdx < truck_weights.size())
    {
        answer++;
        int arrive = bridge.back();
        bridge.pop_back();
        currentWeight -= arrive;

        if(truck_weights[truckIdx] <= weight - currentWeight)
        {
            bridge.push_front(truck_weights[truckIdx]);
            currentWeight += truck_weights[truckIdx++];
        }
        else
        {
            bridge.push_front(0);
        }
    }

    while(!bridge.empty())
    {
        answer++;
        bridge.pop_back();
    }

    return answer;
}

int main()
{
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights;
    truck_weights.emplace_back(7);
    truck_weights.emplace_back(4);
    truck_weights.emplace_back(5);
    truck_weights.emplace_back(6);

    int result = solution(bridge_length, weight, truck_weights);

    cout << result;

    return 0;
}