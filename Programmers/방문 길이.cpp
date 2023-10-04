/**************************
문제의 핵심 ( 2020 kakao blind recruitment )
1. map[start, destination] / map[destination, start]로 저장하기 때문에 총 변의 수는 나누기2를 해야함
**************************/
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

map<char, pair<int,int>> dist;

void init()
{
    dist.insert({'U', make_pair(0, 1)});
    dist.insert({'D', make_pair(0, -1)});
    dist.insert({'L', make_pair(-1, 0)});
    dist.insert({'R', make_pair(1, 0)});
}

int solution(string dirs)
{
    init();
    int answer = 0;

    map<pair<pair<int,int>, pair<int, int>>, bool> visited;

    int x = 0;
    int y = 0;
    for(char &dir : dirs)
    {
        int nx = x + dist[dir].first;
        int ny = y + dist[dir].second;
        if(nx > 5 || nx < -5)
        {
            continue;
        }
        if(ny > 5 || ny < -5)
        {
            continue;
        }
        pair<pair<int,int>, pair<int,int>> points = {{x,y}, {nx, ny}};
        visited.insert({points, true});
        points = {{nx, ny}, {x, y}};
        visited.insert({points, true});
        x = nx;
        y = ny;
    }

    answer = visited.size() / 2;

    return answer;
}

int main()
{
    int result = solution("ULURRDLLU");

    cout << result;

    return 0;
}