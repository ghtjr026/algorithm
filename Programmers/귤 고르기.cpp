/**************************
문제의 핵심
1. 정렬을 잘 할 것
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &lvalue, pair<int, int> &rvalue)
{
    return lvalue.first > rvalue.first;
}

int solution(int k, vector<int> tangerine)
{
    int answer = 0;

    vector<pair<int, int>> cnt;

    for(int idx = 0; idx < tangerine.size(); idx++)
    {
        int num = count(tangerine.begin(), tangerine.end(), tangerine[idx]);

        bool isExist = false;
        for(auto &type : cnt)
        {
            if(tangerine[idx] == type.second)
            {
                isExist = true;
                break;
            }
        }

        if(!isExist)
        {
            cnt.emplace_back(make_pair(num, tangerine[idx]));
        }
    }

    sort(cnt.begin(), cnt.end(), cmp);

    for(auto &tan : cnt)
    {
        if(0 >= k)
        {
            break;
        }

        k -= tan.first;
        answer++;
    }

    return answer;
}

int main()
{
    int k = 6;

    vector<int> tangerine;
    tangerine.emplace_back(1);
    tangerine.emplace_back(3);
    tangerine.emplace_back(2);
    tangerine.emplace_back(5);
    tangerine.emplace_back(4);
    tangerine.emplace_back(5);
    tangerine.emplace_back(2);
    tangerine.emplace_back(3);

    int result = solution(k, tangerine);

    cout << result;

    return 0;
}