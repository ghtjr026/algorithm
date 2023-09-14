/**************************
문제의 핵심 ( kakao tech internship )
1. vector의 erase를 사용하면 시간초과
-> erase는 O(n)의 시간이 걸린다고 함

2. 두 queue를 비교하면서 수 옮기기

3. queue에 포함된 값의 max가 10^9 기 떄문에 long long 사용
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    long long queue1Sum = accumulate(queue1.begin(), queue1.end(), 0);
    long long queue2Sum = accumulate(queue2.begin(), queue2.end(), 0);

    if((queue1Sum + queue2Sum) % 2 == 1)
    {
        return -1;
    }

    queue<int> qu1;
    queue<int> qu2;

    for(int idx = 0; idx < queue1.size(); idx++)
    {
        qu1.push(queue1.at(idx));
        qu2.push(queue2.at(idx));
    }
    
    int answer = 0;
    bool isPossible = true;
    while(queue1Sum != queue2Sum)
    {
        if(queue1Sum > queue2Sum)
        {
            int num = qu1.front();
            queue1Sum -= num;
            queue2Sum += num;
            qu1.pop();
            qu2.push(num);
            //queue1.erase(queue1.begin());
            //queue2.emplace_back(num);
        }
        else
        {
            int num = qu2.front();
            queue2Sum -= num;
            queue1Sum += num;
            qu2.pop();
            qu1.push(num);
            //queue2.erase(queue2.begin());
            //queue1.emplace_back(num);
        }
        answer++;

        if (qu1.empty() || qu2.empty())
        {
            isPossible = false;
            break;
        }

        if(answer >= (qu1.size() + qu2.size()) * 3)
        {
            isPossible = false;
            break;
        }
    }

    if(!isPossible)
    {
        return -1;
    }

    return answer;
}

int main()
{
    vector<int> queue1;
    //get queue1
    queue1.emplace_back(2);
    queue1.emplace_back(4);
    queue1.emplace_back(6);

    vector<int> queue2;
    //get queue2
    queue2.emplace_back(1);
    queue2.emplace_back(3);
    queue2.emplace_back(5);

    int result = solution(queue1, queue2);

    cout << result;

    return 0;
}