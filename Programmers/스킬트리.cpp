/**************************
문제의 핵심 ( Summer/Winter Coding(~2018) )
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;

    for(auto &skillTree : skill_trees)
    {
        bool isposible = true;
        auto before = skillTree.find(skill[0]);

        for(int idx = 1; idx < skill.length(); idx++)
        {
            auto after = skillTree.find(skill[idx]);
            if(before > after)
            {
                isposible = false;
                break;
            }
            before = after;
        }

        if(isposible)
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    string skill = "CBD";
    vector<string> skillTrees;
    skillTrees.emplace_back("BACDE");
    skillTrees.emplace_back("CBADF");
    skillTrees.emplace_back("AECB");
    skillTrees.emplace_back("BDA");

    int result = solution(skill, skillTrees);

    cout << result;

    return 0;
}