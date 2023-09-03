/**************************
문제의 핵심
1. 정렬을 제대로 할 것

2. 반례가 있음
-> 과제가 끝났을 때 시간이 남는다면 여러 과제를 끝낼 수 있음
ex) 10분의 시간이 남고, delay된 과제가 5, 5, 5 분씩 남았을 때, 2개의 과제를 끝낼 수 있음을 알아야할 것
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

static const int START = 1;
static const int PLAYTIME = 2;

bool cmp(vector<string> &lvalue, vector<string> &rvalue)
{
    return stoi(lvalue[START]) < stoi(rvalue[START]);
}

string TimeToMin(string time)
{
    int hour = stoi(time.substr(0, 2)) * 60;
    int min = stoi(time.substr(3, 2));

    return to_string(hour + min);
}

void sortPlans(vector<vector<string>> &plans)
{
    for (int idx = 0; idx < plans.size(); idx++)
    {
        string maxMin = TimeToMin(plans[idx][START]);
        plans[idx][START] = maxMin;
    }

    sort(plans.begin(), plans.end(), cmp);
}

vector<string> solution(vector<vector<string>> plans)
{ 
    vector<string> answer;

    sortPlans(plans);

    stack<vector<string>> schedule;
    schedule.push(plans[0]);

    /*
    push current job in schedule

    compare next job to current_job

    if - current job is done before starting next job
        current job pop and store answer
    else - currnet job is not done before starting next job
        push next job in schedule and change current job
    */

    int idx = 1;
    int currentTime = stoi(plans[0][START]);
    while (!schedule.empty() && idx < plans.size())
    {
        vector<string> job = schedule.top();
        schedule.pop();

        if (currentTime + stoi(job[PLAYTIME]) == stoi(plans[idx][START]))
        {
            answer.emplace_back(job[0]);
            schedule.push(plans[idx++]);
            currentTime += stoi(job[PLAYTIME]);
        }
        else if(currentTime + stoi(job[PLAYTIME]) > stoi(plans[idx][START]))
        {
            int workingTime = stoi(plans[idx][START]) - currentTime;
            job[PLAYTIME] = to_string(stoi(job[PLAYTIME]) - workingTime);
            schedule.push(job);
            schedule.push(plans[idx]);
            currentTime = stoi(plans[idx++][START]);
        }
        else
        {
            answer.emplace_back(job[0]);
            currentTime = stoi(job[START]) + stoi(job[PLAYTIME]);
            while(!schedule.empty() && currentTime != stoi(plans[idx][START]))
            {
                vector<string> remainJob = schedule.top();
                schedule.pop();
                
                if(currentTime + stoi(remainJob[PLAYTIME]) <= stoi(plans[idx][START])) // finish remainJob
                {
                    answer.emplace_back(remainJob[0]);
                    currentTime += stoi(remainJob[PLAYTIME]);
                }
                else // do not finish remainJob
                {
                    remainJob[PLAYTIME] = to_string(stoi(remainJob[PLAYTIME]) - (stoi(plans[idx][START]) - currentTime));
                    currentTime = stoi(plans[idx][START]);
                    schedule.push(remainJob);
                }
            }
            
            if(schedule.empty())
            {
                currentTime = stoi(plans[idx][START]);
                schedule.push(plans[idx++]);
            }
        }
    }

    while(!schedule.empty())
    {
        vector<string> job = schedule.top();
        answer.emplace_back(job[0]);
        schedule.pop();
    }

    return answer;
}

int main()
{
    vector<vector<string>> plans;
    string name;
    string time;
    string playTime;

    while (true)
    {
        cin >> name >> time >> playTime;
        if (name.compare("stop") == 0)
        {
            break;
        }

        vector<string> project;
        project.emplace_back(name);
        project.emplace_back(time);
        project.emplace_back(playTime);

        plans.emplace_back(project);
    }

    vector<string> answer = solution(plans);

    return 0;
}