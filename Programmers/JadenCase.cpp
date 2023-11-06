/**************************
문제의 핵심
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

void getJadenCase(string &str)
{
    for(int idx = 0; idx < str.length(); idx++)
    {
        if(idx == 0)
        {
            if('a' <= str[idx] && 'z' >= str[idx])
            {
                str[idx] = toupper(str[idx]);
            }
        }
        else
        {
            if('A' <= str[idx] && 'Z' >= str[idx])
            {
                str[idx] = tolower(str[idx]);
            }
        }
    }
}

string solution(string s)
{
    string answer = "";

    stringstream ss(s);
    string temp;
    while(getline(ss, temp, ' '))
    {
        if(!temp.empty())
        {
            getJadenCase(temp);
            answer += temp;
        }
        
        answer += " ";
    }

    if(s[s.length() - 1] == ' ')
    {
        return answer;
    }
    return answer.substr(0, answer.size() - 1);
}

int main()
{
    string str = solution("a b c de  fg ");

    for(char ch : str)
    {
        if(ch == ' ')
        {
            cout << '&';
        }
        else
        {
            cout << ch;
        }
    }

    return 0;
}