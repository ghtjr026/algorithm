/**************************
문제의 핵심
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    vector<int> days;
    for(int idx = 0; idx < progresses.size(); idx++)
    {
        int day = 0;
        int remain = 100 - progresses[idx];
        day = remain / speeds[idx];
        if(remain % speeds[idx] != 0)
        {
            day++;
        }
        days.emplace_back(day);
    }

    int cnt = 1;
    int maxDay = days[0];
    for(int idx = 1; idx < days.size(); idx++)
    {
        if(maxDay >= days[idx])
        {
            cnt++;
        }
        else
        {
            answer.emplace_back(cnt);
            cnt = 1;
            maxDay = days[idx];
        }
    }
    answer.emplace_back(cnt);

    return answer;
}

int main()
{
    vector<int> progresses;
    progresses.emplace_back(93);
    progresses.emplace_back(30);
    progresses.emplace_back(55);

    vector<int> speeds;
    speeds.emplace_back(1);
    speeds.emplace_back(30);
    speeds.emplace_back(5);

    vector<int> results = solution(progresses, speeds);

    for(int &result : results)
    {
        cout << result;
    }

    return 0;
}