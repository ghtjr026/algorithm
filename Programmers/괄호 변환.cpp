/**************************
문제의 핵심 ( 2020 kakao blind recruitment )
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isRightStr(string str)
{
    if(str.empty())
    {
        return true;
    }
    else if(str[0] == '(')
    {
        return true;
    }
    return false;
}

void subString(string origin, string &u, string &v)
{
    int openCnt = 0;
    int closeCnt = 0;
    int idx = 0;
    for(; idx < origin.length(); idx++)
    {
        u.push_back(origin[idx]);
        if(origin[idx] == '(')
        {
            openCnt++;
        }
        else
        {
            closeCnt++;
        }
        
        if(openCnt == closeCnt)
        {
            break;
        }
    }

    for(idx++;idx < origin.length(); idx++)
    {
        v.push_back(origin[idx]);
    }
}

void dfs(string p, string &answer)
{
    string u;
    string v;
    subString(p, u, v);

    if(isRightStr(u))
    {
        answer += u;
        if(!v.empty())
        {
            dfs(v, answer);
        }
        return;
    }
    else
    {
        answer += "(";
        dfs(v, answer);
        answer += ")";
    }

    u.erase(u.begin());
    u.erase(u.end() - 1);

    if(!u.empty())
    {
        string temp;
        for(char &str : u)
        {
            if(str == '(')
            {
                temp += ')';
            }
            else
            {
                temp += '(';
            }
        }
        answer += temp;
    }
    return;
}

string solution(string p)
{
    string answer = "";

    dfs(p, answer);

    return answer;
}

int main()
{  
    string result = solution("");

    cout << result << endl;

    return 0;
}