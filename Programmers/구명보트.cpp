/**************************
문제의 핵심
1. deque를 사용해야 한다는 것을 인지할 것

2. dq의 앞/뒤 값을 뺄 때, empty 인지를 체크할 것
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(int &rvalue, int &lvalue)
{
    return rvalue > lvalue;
}

int solution(vector<int> people, int limit)
{
    int answer = 0;
    
    sort(people.begin(), people.end(), cmp);

    deque<int> dq;
    for(int &w : people)
    {
        dq.push_back(w);
    }

    while(!dq.empty())
    {
        answer++;
        int front = dq.front();
        dq.pop_front();
        int back = 0;
        if(!dq.empty())
        {
            back = dq.back();
            dq.pop_back();
        }

        if(limit >= front + back)
        {
            continue;
        }
        else
        {
            if(back != 0)
            {
                dq.push_back(back);
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> people;
    people.emplace_back(70);
    people.emplace_back(80);
    people.emplace_back(50);

    int limit = 100;

    int result = solution(people, limit);

    cout << result << endl;

    return 0;
}