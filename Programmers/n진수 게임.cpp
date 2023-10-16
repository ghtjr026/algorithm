/**************************
문제의 핵심 ( 2018 kakao blind recruitment )
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string changeNBaseNumber(int n, int num)
{
    string temp;

    while(num != 0)
    {
        int remain = num % n;
        switch (remain)
        {
        case 10:
            temp += "A";
            break;
        case 11:
            temp += "B";
            break;
        case 12:
            temp += "C";
            break;
        case 13:
            temp += "D";
            break;
        case 14:
            temp += "E";
            break;
        case 15:
            temp += "F";
            break;
        default:
            temp += to_string(remain);
            break;
        }
        num /= n;
    }

    reverse(temp.begin(), temp.end());
    return temp;
}

string solution(int n, int t, int m, int p)
{
    string answer = "";

    int order = 0;
    for(int num = 0; ;num++)
    {
        if(answer.size() == t)
        {
            break;
        }

        string nBaseNum = changeNBaseNumber(n, num);
        if(nBaseNum == "")
        {
            nBaseNum = "0";
        }

        for(int idx = 0; idx < nBaseNum.size(); idx++)
        {
            if(order % m == p - 1)
            {
                answer += nBaseNum[idx];
                if(answer.size() == t)
                {
                    break;
                }
            }
            order++;
        }
    }

    return answer;
}

int main()
{
    int n = 2;
    int t = 4;
    int m = 2;
    int p = 1;

    string result = solution(n, t, m, p);

    cout << result.c_str() << endl;

    return 0;
}