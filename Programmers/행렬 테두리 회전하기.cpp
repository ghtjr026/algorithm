/**************************
문제의 핵심
1. 행렬의 테두리를 회전할 때, 값을 바로바로 바꾸면 문제가 생길 수 있음을 유의
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

vector<vector<int>> makeMatrix(int rows, int columns)
{
    vector<vector<int>> matrix(rows, vector<int>(columns, 0));

    int start = 1;
    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            matrix[row][column] = start++;
        }
    }

    return matrix;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;

    vector<vector<int>> matrix = makeMatrix(rows, columns);

    for(vector<int> & query : queries)
    {
        int x1 = query[0] - 1;
        int y1 = query[1] - 1;
        int x2 = query[2] - 1;
        int y2 = query[3] - 1;

        queue<int> rotation;
        int Min = rows * columns;
        for(int x = x1; x <= x2; x++)
        {
            for(int y = y1; y <= y2; y++)
            {
                // make array
                if(x == x1 || x == x2)
                {
                    Min = min(Min, matrix[x][y]);
                }
                else
                {
                    if(y == y1 || y == y2)
                    {
                        Min = min(Min, matrix[x][y]);
                    }
                }

                // rotate matrix
                // up line
                if(x == x1 && y != y1)
                {
                    rotation.push(matrix[x][y - 1]);
                }
                // left line
                if(x != x2 && y == y1)
                {
                    rotation.push(matrix[x + 1][y]);
                }
                // down line
                if(x == x2 && y != y2)
                {
                    rotation.push(matrix[x][y + 1]);
                }
                // right line
                if(x != x1 && y == y2)
                {
                    rotation.push(matrix[x - 1][y]);
                }
            }
        }

        answer.emplace_back(Min);
        if(answer.size() == queries.size())
        {
            break;
        }

        for(int x = x1; x <= x2; x++)
        {
            for(int y = y1; y <= y2; y++)
            {
                if(x == x1 || x == x2)
                {
                    matrix[x][y] = rotation.front();
                    rotation.pop();
                }
                else
                {
                    if(y == y1 || y == y2)
                    {
                        matrix[x][y] = rotation.front();
                        rotation.pop();
                    }
                }
            }
        }
    }

    return answer;
}

int main()
{
    int rows = 6;
    int columns = 6;

    vector<vector<int>> queries;
    vector<int> query;
    query.emplace_back(2);
    query.emplace_back(2);
    query.emplace_back(5);
    query.emplace_back(4);
    queries.emplace_back(query);
    query.clear();

    query.emplace_back(3);
    query.emplace_back(3);
    query.emplace_back(6);
    query.emplace_back(6);
    queries.emplace_back(query);
    query.clear();

    query.emplace_back(5);
    query.emplace_back(1);
    query.emplace_back(6);
    query.emplace_back(3);
    queries.emplace_back(query);
    query.clear();

    vector<int> results = solution(rows, columns, queries);

    for(int &result : results)
    {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}