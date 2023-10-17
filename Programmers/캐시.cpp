/**************************
문제의 핵심 ( 2018 kakao blind recruitment )
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool ishit(deque<string> &dq, string city, int cacheSize)
{
    if(dq.empty())
    {
        dq.push_front(city);
        return false;
    }

    deque<string>::iterator it = dq.begin();
    for (; it != dq.end();)
    {
        if ((*it) == city)
        {
            dq.erase(it);
            dq.push_front(city);
            return true;
        }
        else
        {
            it++;
        }
    }

    if (it == dq.end())
    {
        if(dq.size() == cacheSize)
        {
            dq.pop_back();
        }
        dq.push_front(city);
    }
    return false;
}

string getLower(string city)
{
    string lower;

    for(char &str : city)
    {
        lower += char(tolower(str));
    }

    return lower;
}

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;

    deque<string> dq;
    
    if(cacheSize == 0)
    {
        answer = cities.size() * 5;
    }
    else
    {
        for (string &city : cities)
        {
            string temp = getLower(city);
            if (ishit(dq, temp, cacheSize))
            {
                answer += 1;
            }
            else
            {
                answer += 5;
            }
        }
    }

    return answer;
}

int main()
{
    int cacheSize = 2;
    vector<string> cities;
    cities.emplace_back("Jeju");
    cities.emplace_back("Pangyu");
    cities.emplace_back("NewYork");
    cities.emplace_back("NewYork");

    int result = solution(cacheSize, cities);

    cout << result;

    return 0;
}