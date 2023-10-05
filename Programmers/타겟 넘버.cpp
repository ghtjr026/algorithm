/**************************
문제의 핵심
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(int idx, vector<int> numbers, int target, int current, int &answer)
{
    if(idx == numbers.size())
    {
        if(current == target)
        {
            answer++;
        }
        return;
    }

    dfs(idx + 1, numbers, target, current + numbers.at(idx), answer);
    dfs(idx + 1, numbers, target, current - numbers.at(idx), answer);
    return;
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    vector<bool> visited(numbers.size(), false);

    dfs(0, numbers, target, 0, answer);

    return answer;
}

int main()
{
    vector<int> numbers;
    numbers.emplace_back(1);
    numbers.emplace_back(1);
    numbers.emplace_back(1);
    numbers.emplace_back(1);
    numbers.emplace_back(1);
    int target = 3;

    int result = solution(numbers, target);

    cout << result;

    return 0;
}