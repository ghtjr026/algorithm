/**************************
문제의 핵심
1. DP 식을 알아차려야 할 것

2. count(first, last, target)
-> first 부터 last 전까지를 의미
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights)
{
    long long answer = 0;

    vector<int> seatWeights(4001, 0);

    for(int idx = 0; idx < weights.size(); idx++)
    {
        int dis2 = weights[idx] * 2;
        int dis3 = weights[idx] * 3;
        int dis4 = weights[idx] * 4;

        answer += seatWeights[dis2];
        answer += seatWeights[dis3];
        answer += seatWeights[dis4];

        // weights.begin() ( include ) - weights.begin() + idx ( exclude )
        int cntSameWeights = count(weights.begin(), weights.begin() + idx, weights[idx]);
        if(0 < cntSameWeights) // because 0
        {
            answer -= cntSameWeights * 2;
        }

        seatWeights[dis2]++;
        seatWeights[dis3]++;
        seatWeights[dis4]++;
    }

    return answer;
}

int main()
{
    vector<int> weights;

    //get weights
    weights.emplace_back(100);
    weights.emplace_back(180);
    weights.emplace_back(360);
    weights.emplace_back(100);
    weights.emplace_back(270);

    long long cntPair = solution(weights);

    cout << cntPair;

    return 0;
}