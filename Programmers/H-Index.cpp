/**************************
문제의 핵심
1. 유의사항 없음

2. 아래 코드에서 주석은 두번째 방법으로 풀었을 때임
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int &lvalue, int &rvalue)
{
    return lvalue > rvalue;
}

int solution(vector<int> citations)
{
    sort(citations.begin(), citations.end(), cmp);

    int answer = citations.size();

    for(int idx = 0; idx < citations.size(); idx++)
    {
        if(citations[idx] <= idx + 1)
        {
            answer = idx;
            break;
        }
    }

    return answer;

    // vector<int> thesis;
    // for(int idx = 0; idx < citations.size(); idx++)
    // {
    //     if(citations[idx] <= thesis.size())
    //     {
    //         break;
    //     }
    //     thesis.emplace_back(citations[idx]);
    // }

    // return thesis.size();
}

int main()
{
    vector<int> citations;
    citations.emplace_back(9);
    citations.emplace_back(9);
    citations.emplace_back(1);
    citations.emplace_back(9);
    citations.emplace_back(9);

    int result = solution(citations);

    cout << result;

    return 0;
}