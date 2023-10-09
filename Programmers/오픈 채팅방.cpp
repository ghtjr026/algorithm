/**************************
문제의 핵심 ( 2019 kakao blind recruitment )
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string isEnter(string enterance)
{
    string result = "";
    if(enterance == "Enter")
    {
        result = " 들어왔습니다.";
    }
    else if(enterance == "Leave")
    {
        result = " 나갔습니다.";
    }
    else
    {
        result = "Change";
    }
    return result;
}

string getAdminPage(string record, map<string, string> &idName)
{
    stringstream ss(record);
    string temp;

    string id;
    string enterance;
    int cnt = 0;
    while(getline(ss, temp, ' '))
    {
        switch (cnt++)
        {
        case 0:
            enterance = isEnter(temp);
            break;
        case 1:
            id = temp;
            break;
        case 2:
            idName[id] = temp;
            break;

        default:
            break;
        }
    }

    return id + enterance;
}

void idToName(vector<string> &answer, map<string, string> &idName)
{
    for(string &str : answer)
    {
        int idx = 0;
        for(;idx < str.size(); idx++)
        {
            if(str[idx] == ' ')
            {
                break;
            }
        }

        string id = str.substr(0, idx);
        str.replace(str.begin(), str.begin() + idx, (idName[id] + "님이"));
    }
}

vector<string> solution(vector<string> record)
{
    vector<string> answer;

    map<string, string> idName;

    for(string &str : record)
    {
        string result = getAdminPage(str, idName);
        if(result.find("Change") == string::npos)
        {
            answer.emplace_back(result);
        }
    }

    idToName(answer, idName);

    return answer;
}

int main()
{
    vector<string> record;
    record.emplace_back("Enter uid1234 Muzi");
    record.emplace_back("Enter uid4567 Prodo");
    record.emplace_back("Leave uid1234");
    record.emplace_back("Enter uid1234 Prodo");
    record.emplace_back("Change uid4567 Ryan");

    vector<string> result = solution(record);

    for(string &str : result)
    {
        cout << str << endl;
    }

    return 0;
}