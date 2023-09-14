/**************************
문제의 핵심
1. 그룹을 모두 구하고 내림차순으로 정렬

2. 주의할 점 그룹이 하나일 때를 대비하여 미리 0을 넣어둠
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

int solution(vector<int> cards)
{
    vector<bool> visited(cards.size(), false);
    vector<int> group;
    group.emplace_back(0);

    for(int idx = 0; idx < cards.size(); idx++)
    {
        int groupCnt = 0;
        if(!visited[idx])
        {
            groupCnt++;
            visited[idx] = true;
            int current = cards[idx] - 1;
            while(!visited[current])
            {
                visited[current] = true;
                current = cards[current] - 1;
                groupCnt++;
            }
        }
        group.emplace_back(groupCnt);
    }

    sort(group.begin(), group.end(), cmp);

    return group[0] * group[1];
}

int main()
{
    vector<int> cards;
    cards.emplace_back(8);
    cards.emplace_back(6);
    cards.emplace_back(3);
    cards.emplace_back(7);
    cards.emplace_back(2);
    cards.emplace_back(5);
    cards.emplace_back(1);
    cards.emplace_back(4);

    int result = solution(cards);

    cout << result;

    return 0;
}