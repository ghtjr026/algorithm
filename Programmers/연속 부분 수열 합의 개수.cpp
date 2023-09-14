/**************************
문제의 핵심
1. 완탐 or DP로 풀것
-> 해당 문제에서는 elements의 길이의 max가 1000이라 완탐이 가능함
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements)
{
    int originSize = elements.size();
    set<int> subSum;

    for(int i = 0; i < originSize; i++)
    {
        elements.emplace_back(elements[i]);
        subSum.insert(elements[i]);
    }

    for(int i = 2; i < originSize; i++)
    {
        for(int idx = 0; idx < originSize; idx++)
        {
            int sum = 0;
            for(int next = 0; next < i; next++)
            {
                sum += elements[idx + next];
            }
            subSum.insert(sum);
        }
    }

    return subSum.size() + 1;
}

int main()
{
    vector<int> elements;
    elements.emplace_back(7);
    elements.emplace_back(9);
    elements.emplace_back(1);
    elements.emplace_back(1);
    elements.emplace_back(4);

    int result = solution(elements);

    cout << result;

    return 0;
}