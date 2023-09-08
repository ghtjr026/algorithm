/**************************
문제의 핵심
1. schedule을 ENDTime순으로 오름차순 정렬하여 비교

2. 방이 두개 이상 끝났을 때 현재 사용하고 있는 방과 이전에 최대값을 비교
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

static const int START = 0;
static const int END = 1;

static const string ENTER = "enter";
static const string EXIT = "exit";

string TimeToMin(string time, string type)
{
    int hour = stoi(time.substr(0, 2)) * 60;
    int min = stoi(time.substr(3, 2));

    if(type == "exit")
    {
        min += 10;
    }

    return to_string(hour + min);
}

bool cmpStart(vector<string> &lvalue, vector<string> &rvalue)
{
    return stoi(lvalue[START]) < stoi(rvalue[START]);
}

void sortTime(vector<vector<string>> &bookTime)
{
    for (int idx = 0; idx < bookTime.size(); idx++)
    {
        string startTime = TimeToMin(bookTime[idx][START], ENTER);
        string endTime = TimeToMin(bookTime[idx][END], EXIT);
        bookTime[idx][START] = startTime;
        bookTime[idx][END] = endTime;
    }

    sort(bookTime.begin(), bookTime.end(), cmpStart);
}

bool cmpEnd(vector<string> &lvalue, vector<string> &rvalue)
{
    return stoi(lvalue[END]) < stoi(rvalue[END]);
}

int solution(vector<vector<string>> bookTime)
{
    sortTime(bookTime);

    vector<vector<string>> schedule;
    schedule.emplace_back(bookTime[0]);
    int currentTime = stoi(bookTime[0][START]);
    int answer = 1;

    for(int idx = 1; idx < bookTime.size(); idx++)
    {
        vector<string> nextBookTime = bookTime[idx];
        currentTime = stoi(nextBookTime[START]);

        bool isExistExitRoom = false;

        for(int reservation = 0; reservation < schedule.size();)
        {   
            if(stoi(schedule[reservation][END]) <= currentTime)
            {
                isExistExitRoom = true;
                schedule.erase(schedule.begin() + reservation);
            }
            else
            {
                reservation++;
            }
        }

        schedule.emplace_back(nextBookTime);
        sort(schedule.begin(), schedule.end(), cmpEnd);

        int usingRoom = schedule.size();

        if(!isExistExitRoom)
        {
            answer = max(answer, usingRoom);
        }
    }

    return answer;
}

int main()
{
    vector<vector<string>> bookTime;

    vector<string>time;

    time.emplace_back("15:00");
    time.emplace_back("17:00");
    bookTime.emplace_back(time);
    time.emplace_back("16:40");
    time.emplace_back("18:20");
    bookTime.emplace_back(time);
    time.emplace_back("14:20");
    time.emplace_back("15:20");
    bookTime.emplace_back(time);
    time.emplace_back("14:10");
    time.emplace_back("19:20");
    bookTime.emplace_back(time);
    time.emplace_back("18:20");
    time.emplace_back("21:20");
    bookTime.emplace_back(time);

    int answer = solution(bookTime);

    cout << "answer = " << answer << endl;

    return 0;
}