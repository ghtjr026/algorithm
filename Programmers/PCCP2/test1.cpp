#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> ability, int number)
{
    int answer = 0;
   
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int info : ability)
    {
        pq.push(info);
    }

    for(int n = 0; n < number; n++)
    {
        int sum = pq.top();
        pq.pop();
        sum += pq.top();
        pq.pop();

        pq.push(sum);
        pq.push(sum);
    }

    while(!pq.empty())
    {
        answer += pq.top();
        pq.pop();
    }

    return answer;
}

int main()
{


    return 0;
}