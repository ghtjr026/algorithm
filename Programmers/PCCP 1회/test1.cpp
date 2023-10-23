#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void bfs(int studentCnt, int cnt, int sumAbility, vector<vector<int>> &ability, vector<bool> &student, vector<bool> &kind, int &answer)
{
    if(cnt == ability[0].size())
    {
        answer = max(answer, sumAbility);
        return;
    }

    for(int idx = studentCnt; idx < ability.size(); idx++)
    {
        if(student[idx])
        {
            continue;
        }

        student[idx] = true;

        for(int kindIdx = 0; kindIdx < ability[idx].size(); kindIdx++)
        {
            if(kind[kindIdx])
            {
                continue;
            }

            kind[kindIdx] = true;

            bfs(idx + 1, cnt + 1, sumAbility + ability[idx][kindIdx], ability, student, kind, answer);

            kind[kindIdx] = false;
        }

        student[idx] = false;
    }
    return;
}

int solution(vector<vector<int>> ability)
{
    int answer = 0;

    vector<bool> student(ability.size(), false);
    vector<bool> kind(ability[0].size(), false);

    bfs(0, 0, 0, ability, student, kind, answer);

    return answer;
}

int main()
{
    vector<vector<int>> abilities;
    vector<int> ability;
    ability.emplace_back(40);
    ability.emplace_back(10);
    ability.emplace_back(10);
    abilities.emplace_back(ability);
    ability.clear();

    ability.emplace_back(20);
    ability.emplace_back(5);
    ability.emplace_back(0);
    abilities.emplace_back(ability);
    ability.clear();

    ability.emplace_back(30);
    ability.emplace_back(30);
    ability.emplace_back(30);
    abilities.emplace_back(ability);
    ability.clear();

    ability.emplace_back(70);
    ability.emplace_back(0);
    ability.emplace_back(70);
    abilities.emplace_back(ability);
    ability.clear();

    ability.emplace_back(100);
    ability.emplace_back(100);
    ability.emplace_back(100);
    abilities.emplace_back(ability);
    ability.clear();

    int result = solution(abilities);

    cout << result;

    return 0;
}