#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<vector<int>> queries)
{
    vector<string> answer;

    vector<string> str;
    str.emplace_back("RR");
    str.emplace_back("Rr");
    str.emplace_back("Rr");
    str.emplace_back("rr");

    for(vector<int> query : queries)
    {
        int n = query[0];
        int p = query[1];

        if(n == 1)
        {
            answer.emplace_back("Rr");
            continue;
        }
        else if(n == 2)
        {
            answer.emplace_back(str[p - 1]);
            continue;
        }

        map<int, int> list;
        int value = p;
        int generation = n;
        while(generation != 2)
        {
            list.insert({generation, value});
            bool isAdd = false;
            if(value % 4 != 0)
            {
                isAdd = true;
            }
            value /= 4;
            if(isAdd)
            {
                value++;
            }
            generation--;
        }

        if(value == 1)
        {
            answer.emplace_back("RR");
            continue;
        }
        else if(value == 4)
        {
            answer.emplace_back("rr");
            continue;
        }
        else
        {
            bool isFin = false;
            for(auto it = list.begin(); it != list.end(); it++)
            {
                int mod = it->second % 4;
                if(mod == 1 || mod == 0)
                {
                    if(mod == 0)
                    {
                        mod = 4;
                    }
                    answer.emplace_back(str[mod - 1]);
                    isFin = true;
                    break;
                }
            }

            if(!isFin)
            {
                answer.emplace_back("Rr");
                continue;
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>>queries;
    vector<int> query;
    query.emplace_back(4);
    query.emplace_back(18);
    queries.emplace_back(query);

    vector<string> results = solution(queries);

    for(string result : results)
    {
        cout << result;
    }

    return 0;
}