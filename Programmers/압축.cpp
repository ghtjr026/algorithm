/**************************
문제의 핵심 ( 2018 kakao blind recruitment )
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void init(map<string, int> &dict, int &index)
{
    dict.insert({"A", index++});
    dict.insert({"B", index++});
    dict.insert({"C", index++});
    dict.insert({"D", index++});
    dict.insert({"E", index++});
    dict.insert({"F", index++});
    dict.insert({"G", index++});
    dict.insert({"H", index++});
    dict.insert({"I", index++});
    dict.insert({"J", index++});
    dict.insert({"K", index++});
    dict.insert({"L", index++});
    dict.insert({"M", index++});
    dict.insert({"N", index++});
    dict.insert({"O", index++});
    dict.insert({"P", index++});
    dict.insert({"Q", index++});
    dict.insert({"R", index++});
    dict.insert({"S", index++});
    dict.insert({"T", index++});
    dict.insert({"U", index++});
    dict.insert({"V", index++});
    dict.insert({"W", index++});
    dict.insert({"X", index++});
    dict.insert({"Y", index++});
    dict.insert({"Z", index++});
}

vector<int> solution(string msg)
{
    vector<int> answer;

    map<string, int> dict;
    int index = 1;
    init(dict, index);

    int curMsgIdx = 0;
    int maxStrSize = 1;
    while(curMsgIdx != msg.length())
    {
        string curStr;
        bool isFind = false;
        for(; curMsgIdx < msg.length(); curMsgIdx++)
        {
            curStr += msg[curMsgIdx];
            if(dict.find(curStr) == dict.end())
            {
                dict.insert({curStr, index++});
                answer.emplace_back(dict[curStr.substr(0, curStr.length() - 1)]);
                isFind = true;
                break;
            }
        }

        if(!isFind)
        {
            answer.emplace_back(dict[curStr]);
        }
    }

    return answer;
}

int main()
{
    vector<int> results = solution("TOBEORNOTTOBEORTOBEORNOT");

    for(int &result : results)
    {
        cout << result << endl;
    }

    return 0;
}