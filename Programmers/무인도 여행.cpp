/**************************
문제의 핵심
1. BFS / DFS 문제인 것을 알아차릴 것
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dist[4][2] = {
    {1, 0},  // right
    {0, -1}, // down
    {-1, 0}, // left
    {0, 1}   // up
};

static const int X = 0;
static const int Y = 1;

bool cmp(int &lvalue, int &rvalue)
{
    return lvalue < rvalue;
}

int getStay(vector<string> &maps, vector<vector<bool>> &visitedMaps, vector<int> start, int width, int length)
{
    queue<vector<int>> q;
    q.push(start);

    int maxStay = 0;

    while (!q.empty())
    {
        vector<int> position = q.front();
        q.pop();

        maxStay += (maps[position[X]][position[Y]] - '0');

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = position[X] + dist[dir][X];
            int ny = position[Y] + dist[dir][Y];

            if((nx < 0 || nx >= width) ||
            (ny < 0 || ny >= length) ||
            (maps[nx][ny] == 'X') || 
            (visitedMaps[nx][ny] == true))
            {
                continue;
            }

            visitedMaps[nx][ny] = true;

            vector<int> waitPosition;
            waitPosition.emplace_back(nx);
            waitPosition.emplace_back(ny);

            q.push(waitPosition);
        }
    }

    return maxStay;
}

vector<int> solution(vector<string> maps)
{
    vector<int> answer;
    vector<vector<bool>> visitedMaps(maps.size(), vector<bool>(maps[0].length(), false));

    for (int width = 0; width < maps.size(); width++)
    {
        for (int length = 0; length < maps[0].length(); length++)
        {
            if ((maps[width][length] != 'X') && (visitedMaps[width][length] == false))
            {
                visitedMaps[width][length] = true;

                vector<int> start;
                start.emplace_back(width);
                start.emplace_back(length);

                int maxStay = getStay(maps, visitedMaps, start, maps.size(), maps[0].length());
                answer.emplace_back(maxStay);
            }
            else
            {
                visitedMaps[width][length] = true;
            }
        }
    }

    if(answer.empty())
    {
        answer.emplace_back(-1);
    }

    sort(answer.begin(), answer.end(), cmp);

    return answer;
}

int main()
{
    vector<string> maps;

    // get maps
    maps.emplace_back("X591X");
    maps.emplace_back("X1X5X");
    maps.emplace_back("X231X");
    maps.emplace_back("1XXX1");

    vector<int> result = solution(maps);

    int resultSize = result.size();
    for (int idx = 0; idx < resultSize; idx++)
    {
        cout << result.at(idx) << endl;
    }

    return 0;
}