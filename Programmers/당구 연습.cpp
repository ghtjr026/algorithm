/**************************
문제의 핵심
1. 당구공을 대칭시켯을때 두 당구공 사이의 거리를 구하는 것

2. 당구공이 동일 선상(x 혹은 y)에 있을 경우 한쪽은 대칭할 수 없음
-> 쿠션보다 공이 먼저 맞기때문
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

static const int X = 0;
static const int Y = 1;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
{
    vector<int> answer;

    //대칭했을 때 시작 점
    int dirCoordi[4][2] = {
        {-startX, startY}, //left
        {m + (m - startX), startY}, //right
        {startX, n + (n - startY)}, //up
        {startX, -startY} //down
    };
    
    while(!balls.empty())
    {
        int minDistance = 999999;
        for(int dir = 0; dir < 4; dir++)
        {
            if(startX == balls[0][X])
            {
                if(startY < balls[0][Y])
                {
                    if(dir == 2) continue; //ignore up
                }
                else
                {
                    if(dir == 3) continue; //ignore down
                }
            }
            else if (startY == balls[0][Y])
            {
                if(startX < balls[0][X])
                {
                    if(dir == 1) continue; //ignore right
                }
                else
                {
                    if(dir == 0) continue; //ignore left
                }
            }
            
            int dist = pow(balls[0][X] - dirCoordi[dir][X], 2) + pow(balls[0][Y] - dirCoordi[dir][Y], 2);
            minDistance = min(minDistance, dist);
        }
        answer.emplace_back(minDistance);
        balls.erase(balls.begin());
    }

    return answer;
}

int main()
{
    vector<vector<int>> balls;
    vector<int> ball;

    ball.emplace_back(1);
    ball.emplace_back(1);
    balls.emplace_back(ball);

    solution(2,2,1,1, balls);

    return 0;
}