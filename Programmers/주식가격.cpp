/**************************
문제의 핵심
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;

    for(int time = 0; time < prices.size(); time++)
    {
        int idx = time + 1;
        for(; idx < prices.size(); idx++)
        {
            if(prices[time] > prices[idx])
            {
                break;
            }
        }
        if(idx == prices.size())
        {
            answer.emplace_back(idx - time - 1);
        }
        else
        {
            answer.emplace_back(idx - time);
        }
    }

    return answer;
}

int main()
{
    vector<int> prices;
    prices.emplace_back(1);
    prices.emplace_back(2);
    prices.emplace_back(3);
    prices.emplace_back(2);
    prices.emplace_back(3);

    vector<int> results = solution(prices);

    for(int &time : results)
    {
        cout << time << endl;
    }

    return 0;
}