/**************************
문제의 핵심 ( 2021 kakao blind Recruitment )
1. map을 사용해야 하는 것을 인지할 것

2. map<key, value> 에서 key 값은 언어 + 직군 + 경력 + 음식 / value 값은 점수

3. query에서는 언어 / 직군 / 경력 / 음식 이 "-" 값이 올 수 있음을 유의
-> "-"는 해당 주제에서 모든 케이스를 포함하는 것을 의미
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<int>> getSplit(vector<string> infos)
{
    map<string, vector<int>> result;

    for(string &info : infos)
    {
        stringstream ss(info);
        string temp;
        string key;
        int value;
        int cnt = 0;
        while(getline(ss, temp, ' '))
        {
            switch (cnt)
            {
            case 4:
                value = stoi(temp);
                break;
            
            default:
                key += temp;
                break;
            }
            cnt++;
        }
        result[key].emplace_back(value);
    }

    return result;
}

void getQuery(string query, string &lang, string &type, string &exp, string &food, int &value)
{
    stringstream ss(query);
    string temp;
    int cnt = 0;
    while (getline(ss, temp, ' '))
    {
        if (temp == "and")
        {
            continue;
        }

        switch (cnt)
        {
        case 0:
            lang = temp;
            break;
        case 1:
            type = temp;
            break;
        case 2:
            exp = temp;
            break;
        case 3:
            food = temp;
            break;
        case 4:
            value = stoi(temp);
            break;

        default:
            break;
        }
        cnt++;
    }
}

int getCount(vector<int> points, int condition)
{
    int count = 0;
    for(int &point : points)
    {
        if(point >= condition)
        {
            count++;
        }
    }
    return count;
}

vector<int> solution(vector<string> info, vector<string> queries)
{
    map<string, vector<int>> infoList = getSplit(info);

    for(auto &infos : infoList)
    {
        sort(infos.second.begin(), infos.second.end());
    }

    vector<int> answers;
    
    for(string & query : queries)
    {
        string lang;
        string type;
        string exp;
        string food;
        int value;
        getQuery(query, lang, type, exp, food, value);

        int answer = 0;
        for(auto &infos : infoList)
        {
            if((infos.first.find(lang) != string::npos) || lang == "-")
            {
                if(infos.first.find(type) != string::npos || type == "-")
                {
                    if(infos.first.find(exp) != string::npos || exp == "-")
                    {
                        if(infos.first.find(food) != string::npos || food == "-")
                        {
                            answer += getCount(infos.second, value);
                        }
                    }
                }
            }
        }

        answers.emplace_back(answer);
    }

    return answers;
}

int main()
{
    vector<string> info;
    info.emplace_back("java backend junior pizza 150");
    info.emplace_back("python frontend senior chicken 210");
    info.emplace_back("python frontend senior chicken 150");
    info.emplace_back("cpp backend senior pizza 260");
    info.emplace_back("java backend junior chicken 80");
    info.emplace_back("python backend senior chicken 50");

    vector<string> query;
    query.emplace_back("java and backend and junior and pizza 100");
    query.emplace_back("python and frontend and senior and chicken 200");
    query.emplace_back("cpp and - and senior and pizza 250");
    query.emplace_back("- and backend and senior and - 150");
    query.emplace_back("- and - and - and chicken 100");
    query.emplace_back("- and - and - and - 150");

    vector<int> results = solution(info, query);

    for(int &result : results)
    {
        cout << result << endl;
    }


    return 0;
}