/**************************
문제의 핵심
1. end 기준으로 오름차순 정렬할 것

2. 비교함수 사요 시 등호를 사용하면 segment fault error 가 발생할 수 있음
-> 비교함수는 "동등한지"가 아닌 "첫번째 수가 두번째 수보다 큰지 혹은 작은지"임을 유의할 것
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
static const int START = 0;
static const int END = 1;

bool cmp(vector<int> &lvalue, vector<int> &rvalue)
{
    return lvalue[END] < rvalue[END];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;

    sort(targets.begin(), targets.end(), cmp);

    int start = -1;
    int end = -1;
    if(targets.size() != 0)
    {
        end = targets[0][END];
    }

    for(int idx = 1; idx < targets.size(); idx++)
    {
        start = targets[idx][START];
        if(end <= start)
        {
            end = targets[idx][END];
            answer++;
        }
        else
        {
            continue;
        }
    }

    return answer;
}

int main()
{
    int s = 0;
    int e = 0;
    vector<vector<int>> targets;

    while(true)
    {
        cin >> s >> e;
        if(s == -1 && e == -1)
        {
            break;
        }
        vector<int> target; // form : s,e
        target.emplace_back(s);
        target.emplace_back(e);

        targets.emplace_back(target);
    }    
    
    int count = solution(targets);

    return 0;
}