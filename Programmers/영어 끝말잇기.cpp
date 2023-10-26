/**************************
문제의 핵심 ( Summer/Winter Coding(~2018) )
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

void getAnswer(int idx, int n, vector<int> &answer)
{
    int num = idx % n;
    int order = idx / n;
    if (num == 0)
    {
        answer.emplace_back(n);
        answer.emplace_back(order);
    }
    else
    {
        answer.emplace_back(num);
        answer.emplace_back(order + 1);
    }
}

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;

    set<string> reports;
    char last = NULL;
    for(int idx = 0; idx < words.size(); idx++)
    {
        if(last != NULL)
        {
            if(last != words[idx][0])
            {
                getAnswer(idx + 1, n, answer);
                break;
            }
        }

        if(reports.find(words[idx].c_str()) != reports.end())
        {
            getAnswer(idx + 1, n, answer);
            break;
        }
        else
        {
            reports.insert(words[idx]);
        }
        last = words[idx][words[idx].length()-1];
    }

    if(answer.empty())
    {
        answer.emplace_back(0);
        answer.emplace_back(0);
    }

    return answer;
}

int main()
{
    int n = 3;
    vector<string> words;
    words.emplace_back("tank");
    words.emplace_back("kick");
    words.emplace_back("know");
    words.emplace_back("wheel");
    words.emplace_back("land");
    words.emplace_back("dream");
    words.emplace_back("mother");
    words.emplace_back("robot");
    words.emplace_back("tank");

    vector<int> results = solution(n, words);

    for(int result : results)
    {
        cout << result << endl;
    }

    return 0;
}