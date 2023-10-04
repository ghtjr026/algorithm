/**************************
문제의 핵심 ( 2020 kakao blind recruitment )
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getCompress(string s, int unit)
{
    string result = "";
    string standard = s.substr(0, unit);
    string compare = "";
    int cnt = 1;

    for(int idx = unit; idx < s.length(); idx += unit)
    {
        compare = s.substr(idx, unit);
        if(standard != compare)
        {
            if(cnt != 1)
            {
                result += to_string(cnt);
            }
            result += standard;
            standard = compare;
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }

    if(cnt != 1)
    {
        result += to_string(cnt);
    }
    result += compare;

    return result;
}

int solution(string s)
{
    int answer = s.length();

    for(int i = 1; i < s.length(); i++)
    {
        string temp = getCompress(s, i);
        answer = min(answer, (int)temp.length());
    }

    return answer;
}

int main()
{
    int result = solution("aabbaccc");

    cout << result << endl;

    return 0;
}