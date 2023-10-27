/**************************
문제의 핵심
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const int dirt[4][2] =
{
    {1, 1}, // right up
    {1, -1}, // right down
    {-1, 1}, // left up
    {-1, -1} // left down
};

void setVisitedValue(vector<vector<int>> &visited, int i, int j, bool value)
{
    int n = visited.size();
    // width
    for(int idx = 0; idx < n; idx++)
    {
        if(idx == j)
        {
            continue;
        }
        
        if(value)
        {
            visited[i][idx]++;
        }
        else
        {
            visited[i][idx]--;
        }
    }

    // length
    for(int idx = 0; idx < n; idx++)
    {
        if(idx == i)
        {
            continue;
        }

        if(value)
        {
            visited[idx][j]++;
        }
        else
        {
            visited[idx][j]--;
        }
    }

    // right down
    for(int idx = 0; idx < 4; idx++)
    {
        int ni = i;
        int nj = j;
        while(true)
        {
            ni += dirt[idx][0];
            nj += dirt[idx][1];

            if(ni >= 0 && ni < n && nj >= 0 && nj < n)
            {
                if(value)
                {
                    visited[ni][nj]++;
                }
                else
                {
                    visited[ni][nj]--;
                }
            }
            else
            {
                break;
            }
        }
    }
}

void print(vector<vector<int>> visited)
{
    int n = visited.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << visited[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(vector<vector<int>> &visited, int &answer, int cnt, int n)
{
    if(cnt == n)
    {
        answer++;
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (visited[cnt][j] == 0)
        {
            visited[cnt][j]++;
            setVisitedValue(visited, cnt, j, true);
            //print(visited);
            dfs(visited, answer, cnt + 1, n);
            visited[cnt][j]--;
            setVisitedValue(visited, cnt, j, false);
            //print(visited);
        }
    }
}

int solution(int n)
{
    int answer = 0;

    vector<vector<int>> visited(n, vector<int>(n, 0));

    dfs(visited, answer, 0, n);

    return answer;
}

int main()
{
    int result = solution(4);

    cout << result;

    return 0;
}