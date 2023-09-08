/**************************
문제의 핵심
1. BFS라는 것을 파악할 것
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int dist[][2] = {
    {1, 0}, //right
    {0, -1}, //down
    {-1, 0}, //left
    {0, 1} //up
};

const int posX = 0;
const int posY = 1;

int getStepBFS(vector<string> maps, vector<int> start, vector<int> goal, int width, int length)
{
    vector<vector<bool>> visited(width, vector<bool>(length, false));
    queue<pair<vector<int>, int>> q;

    int step = 0;
    visited[start[posX]][start[posY]] = true;
    q.push({start, 0});

    while(!q.empty())
    {
        pair<vector<int>, int> current = q.front();
        vector<int> position = current.first;
        int time = current.second;
        q.pop();

        if(position[posX] == goal[posX] && position[posY] == goal[posY])
        {
            step = time;
            break;
        }

        for(const auto &dir : dist)
        {
            int nx = position[posX] + dir[posX];
            int ny = position[posY] + dir[posY];

            if((nx < 0 || nx >= width) ||
            (ny < 0 || ny >= length) ||
            (maps[nx][ny] == 'X') || 
            (visited[nx][ny] == true))
            {
                continue;
            }

            visited[nx][ny] = true;
            vector<int> nextPosition;
            nextPosition.emplace_back(nx);
            nextPosition.emplace_back(ny);
            q.push({nextPosition, time+1});
        }
    }

    return step;
}

int solution(vector<string> maps) {

    vector<int> start;
    vector<int> exit;
    vector<int> lever;

    for(int x = 0; x < maps.size();x++)
    {
        for(int y = 0; y < maps[x].length(); y++)
        {
            switch (maps[x][y])
            {
            case 'S':
                start.emplace_back(x);
                start.emplace_back(y);
                break;
            case 'E':
                exit.emplace_back(x);
                exit.emplace_back(y);
                break;
            case 'L':
                lever.emplace_back(x);
                lever.emplace_back(y);
                break;
            default:
                break;
            }
        }
    }

    int reachLever = getStepBFS(maps, start, lever, maps.size(), maps[0].length());

    if(reachLever == 0)
    {
        return -1;
    }

    int reachExit = getStepBFS(maps, lever, exit, maps.size(), maps[0].length());

    if(reachExit == 0)
    {
        return -1;
    }

    return reachLever + reachExit;
}

int main()
{
    vector<string> maps;

    //get maps
    maps.emplace_back("LOOXS");
    maps.emplace_back("OOOOX");
    maps.emplace_back("OOOOO");
    maps.emplace_back("OXXXX");
    maps.emplace_back("OOOOE");

    int finalStep = solution(maps);

    cout << finalStep << endl;

    return 0;
}