/**************************
문제의 핵심 ( kakao Internship )
1. P(student)의 위치를 찾아 거리두기 확인할 것

다른 풀이
1. 5x5 배열을 만듬 ( 모든 값을 0으로 초기화 )

2. X의 좌표에 임의의 수로 세팅 ( e.g. 100 )

3. P의 좌표 및 상화좌우 좌표에 -1일 씩 할 것

4. 모든 배열에서 -2 이하인 좌표가 있으면 거리두기 실패한 것
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isMenDistance(int x, int y, int x1, int y1)
{
    int distance = abs(x - x1) + abs(y - y1);
    if(distance > 2)
    {
        return true;
    }
    return false;
}

bool isUntect(vector<string> place, vector<pair<int, int>> student)
{
    bool isUntect = true;
    vector<pair<int, int>> ruleBreakers; //student idx
    // check rule breaker
    for(int idx = 0; idx < student.size(); idx++)
    {
        int x = student[idx].first;
        int y = student[idx].second;
        for(int compare = idx + 1; compare < student.size(); compare++)
        {
            int x1 = student[compare].first;
            int y1 = student[compare].second;
            if (!isMenDistance(x, y, x1, y1))
            {
                ruleBreakers.emplace_back(make_pair(idx, compare));
            }
        }
    }

    int a = 1;

    for(auto &breaker : ruleBreakers)
    {
        int x = student[breaker.first].first;
        int y = student[breaker.first].second;
        int x1 = student[breaker.second].first;
        int y1 = student[breaker.second].second;
        // same x
        if(x == x1)
        {
            if(place[x][y + 1] != 'X')
            {
                isUntect = false;
                break;
            }
        }
        // same y
        else if(y == y1)
        {
            if(place[x + 1][y] != 'X')
            {
                isUntect = false;
                break;
            }
        }
        // other
        else if ((place[x][y1] != 'X') ||
            (place[x1][y] != 'X'))
        {
            isUntect = false;
            break;
        }
    }
    return isUntect;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for(auto &place : places)
    {
        vector<pair<int, int>> student;
        for(int x = 0; x < place.size(); x++)
        {
            for(int y = 0; y < place.size(); y++)
            {
                if(place[x][y] == 'P')
                {
                    student.emplace_back(make_pair(x, y));
                }
            }
        }

        if(student.empty())
        {
            answer.emplace_back(1);
            continue;
        }

        if(isUntect(place, student))
        {
            answer.emplace_back(1);
        }
        else
        {
            answer.emplace_back(0);
        }
    }

    return answer;
}

int main()
{
    vector<vector<string>> places;

    vector<string>place;
    place.emplace_back("POOOP");
    place.emplace_back("OXXOX");
    place.emplace_back("OPXPX");
    place.emplace_back("OOXOX");
    place.emplace_back("POXXP");
    places.emplace_back(place);
    place.clear();

    place.emplace_back("POOPX");
    place.emplace_back("OXPXP");
    place.emplace_back("PXXXO");
    place.emplace_back("OXXXO");
    place.emplace_back("OOOPP");
    places.emplace_back(place);
    place.clear();

    place.emplace_back("PXOPX");
    place.emplace_back("OXOXP");
    place.emplace_back("OXPOX");
    place.emplace_back("OXXOP");
    place.emplace_back("PXPOX");
    places.emplace_back(place);
    place.clear();

    place.emplace_back("OOOXX");
    place.emplace_back("XOOOX");
    place.emplace_back("OOOXX");
    place.emplace_back("OXOOX");
    place.emplace_back("OOOOO");
    places.emplace_back(place);
    place.clear();

    place.emplace_back("PXPXP");
    place.emplace_back("XPXPX");
    place.emplace_back("PXPXP");
    place.emplace_back("XPXPX");
    place.emplace_back("PXPXP");
    places.emplace_back(place);
    place.clear();

    vector<int> results = solution(places);

    for(int &result : results)
    {
        cout << result << endl;
    }

    return 0;
}