#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

#define INFO pair<int, pair<int, int>>

bool cmp(vector<int> rvalue, vector<int> lvalue)
{
    return rvalue.at(1) < lvalue.at(1);
}

vector<long long> solution(vector<vector<int>> program)
{
    vector<long long> answer(11, 0);

    stable_sort(program.begin(), program.end(), cmp);

    vector<INFO> thread;

    for(vector<int> info : program)
    {
        thread.emplace_back(make_pair(info[0], make_pair(info[1], info[2])));
    }

    priority_queue<INFO, vector<INFO>, greater<INFO>> pq;
    map<int, long long> result;
    long long currentTime = 0;
    int idx = 0;
    while(true)
    {
        if(idx == thread.size() && pq.empty())
        {
            break;
        }

        for(; idx < thread.size();)
        {
            if(currentTime >= thread[idx].second.first)
            {
                pq.push(thread[idx++]);
            }
            else
            {
                break;
            }
        }

        if(pq.empty())
        {
            currentTime++;
            continue;
        }

        INFO info = pq.top();
        {
            // calc waiting time
            result[info.first] += currentTime - info.second.first;
            currentTime += info.second.second;
            pq.pop();
        }
    }

    for(auto it = result.begin(); it != result.end(); it++)
    {
        answer[it->first] = it->second;
    }

    answer[0] = currentTime;

    return answer;
}

int main()
{
    vector<vector<int>> program;
    vector<int> thread;
    thread.emplace_back(3);
    thread.emplace_back(6);
    thread.emplace_back(4);
    program.emplace_back(thread);
    thread.clear();

    thread.emplace_back(4);
    thread.emplace_back(2);
    thread.emplace_back(5);
    program.emplace_back(thread);
    thread.clear();

    thread.emplace_back(1);
    thread.emplace_back(0);
    thread.emplace_back(5);
    program.emplace_back(thread);
    thread.clear();

    thread.emplace_back(5);
    thread.emplace_back(0);
    thread.emplace_back(5);
    program.emplace_back(thread);
    thread.clear();

    vector<long long> results = solution(program);

    for(long long result : results)
    {
        cout << result << endl;
    }

    return 0;
}