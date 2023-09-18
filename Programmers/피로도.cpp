/**************************
문제의 핵심
1. BFS / DFS 문제인 것을 알아차릴 것

2. DP로도 된다고 하는데 DFS / BFS가 훨씬 간단해 보임
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//fatigue
static const int MINNEED = 0;
static const int MINUSE = 1;

void dfs(int fatigue, vector<vector<int>> dungeons, vector<bool> visited, int progress, int &answer)
{
    if(0 >= fatigue)
    {
        answer = max(answer, progress);
        return;
    }

    for(int idx = 0; idx < dungeons.size(); idx++)
    {
        if(visited.at(idx) == false)
        {
            if(0 <= fatigue - dungeons[idx][MINNEED])
            {
                visited.at(idx) = true;
                dfs(fatigue - dungeons[idx][MINUSE], dungeons, visited, progress + 1, answer);
                visited.at(idx) = false;
            }
        }
    }

    answer = max(answer, progress);
    return;
}

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = -1;

    for(int idx = 0; idx < dungeons.size(); idx++)
    {
        vector<bool> visited(dungeons.size(), false);
        visited.at(idx) = true;
        dfs(k - dungeons[idx][MINUSE], dungeons, visited, 1, answer);
    }

    return answer;
}

int main()
{
    int k = 100;
    vector<vector<int>> dungeons;
    vector<int> fatigue; // 피로도

    fatigue.emplace_back(100);
    fatigue.emplace_back(1);
    dungeons.emplace_back(fatigue);
    fatigue.clear();

    fatigue.emplace_back(99);
    fatigue.emplace_back(1);
    dungeons.emplace_back(fatigue);
    fatigue.clear();
    
    fatigue.emplace_back(99);
    fatigue.emplace_back(1);
    dungeons.emplace_back(fatigue);
    fatigue.clear();

    fatigue.emplace_back(99);
    fatigue.emplace_back(1);
    dungeons.emplace_back(fatigue);
    fatigue.clear();

    fatigue.emplace_back(99);
    fatigue.emplace_back(1);
    dungeons.emplace_back(fatigue);
    fatigue.clear();

    fatigue.emplace_back(99);
    fatigue.emplace_back(1);
    dungeons.emplace_back(fatigue);
    fatigue.clear();

    fatigue.emplace_back(99);
    fatigue.emplace_back(1);
    dungeons.emplace_back(fatigue);
    fatigue.clear();

    int result = solution(k, dungeons);

    cout << result;

    return 0;
}