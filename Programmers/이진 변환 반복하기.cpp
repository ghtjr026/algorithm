/**************************
문제의 핵심 ( 월간 코드 챌린지 시즌1 )
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getBinary(int num)
{
    string s;

    while(num > 0)
    {
        s += to_string(num % 2);
        num /= 2;
    }

    reverse(s.begin(), s.end());
    return s;
}

vector<int> solution(string s)
{
    vector<int> answer;
    int cnt = 0;
    int episode = 0;

    while(s != "1")
    {
        episode++;
        
        int cntZero = count(s.begin(), s.end(), '0');
        cnt += cntZero;

        s = getBinary(s.length() - cntZero);
    }

    answer.emplace_back(episode);
    answer.emplace_back(cnt);

    return answer;
}

int main()
{
    vector<int> results = solution("1111111");

    for(int &result : results)
    {
        cout << result << endl;
    }

    return 0;
}