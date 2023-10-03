/**************************
문제의 핵심 ( 월간 코드 챌린지 시즌1 )
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int dist[3][2] = {
    {1, 0},
    {0, 1},
    {-1, -1}
};

static const int X = 0;
static const int Y = 1;
static const int dir = 3;

vector<int> solution(int n)
{
    vector<int> answer;

    vector<vector<int>> map(n, vector<int>(n, 0));

    int dirFlag = 0;
    int idx = 1;
    int x = -1;
    int y = 0;

    for(int i = n; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            x += dist[dirFlag % dir][X];
            y += dist[dirFlag % dir][Y];
            map[x][y] = idx++;
            if(j == i -1)
            {
                dirFlag++;
                continue;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            answer.emplace_back(map[i][j]);
        }
    }

    return answer;
}

int main()
{
    vector<int> results = solution(5);

    for(int &result : results)
    {
        cout << result << endl;
    }

    return 0;
}