/**************************
문제의 핵심
1. dfs parameter
-> from : 출발지
by : 경유지
to : 목적지

2. 핵심정리
a. 1번 기둥(출발지)에서 가장 큰 원판(제일 밑의 원판)을 3번 기둥(목적지) 맨 밑으로 깔아야 함
b. 그러기 위해선 나머지 원판을 2번 기둥(경유지)에 깔아야함
c. 이 과정을 반복해야함
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> col(3);

void print(int from, int to)
{
    col[to - 1].emplace_back(col[from - 1].back());
    col[from - 1].pop_back();

    for (int idx = 0; idx < 3; idx++)
    {
        cout << idx << ':';
        for (int num : col[idx])
        {
            cout << num << ' ';
        }
        cout << endl;
    }
}

void dfs(int n, int from, int by, int to, vector<vector<int>> &answer)
{
    if (n == 1)
    {
        print(from, to);
        vector<int> temp;
        temp.emplace_back(from);
        temp.emplace_back(to);
        answer.emplace_back(temp);
    }
    else
    {
        dfs(n - 1, from, to, by, answer);

        print(from, to);
        vector<int> temp;
        temp.emplace_back(from);
        temp.emplace_back(to);
        answer.emplace_back(temp);
        
        dfs(n - 1, by, from, to, answer);
    }

    return;
}

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer;

    for(int i = n; i > 0; i--)
    {
        col[0].emplace_back(i);
    }

    dfs(n, 1, 2, 3, answer);

    return answer;
}

int main()
{
    vector<vector<int>> results = solution(4);

    for(vector<int> result : results)
    {
        for(int num : result)
        {
            cout << num << ' ';
        }
        cout << endl;
    }

    return 0;
}