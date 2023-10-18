/**************************
문제의 핵심 ( 2018 kakao blind recruitment )
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int dist[4][2]
{
    {-1, -1}, // leftup
    {-1, 1}, // rightup
    {1, -1}, // leftdown
    {1, 1} // rightdown
};

const int X = 0;
const int Y = 1;
const char EMPTY = '-';

bool isSameStr(int x, int y, vector<string> &board, vector<vector<bool>> &visited)
{
    bool isSameStr = false;
    for(int idx = 0; idx < 4; idx++)
    {
        int nx = x + dist[idx][X];
        int ny = y + dist[idx][Y];

        if((0 <= nx) &&
        (board.size() > nx) &&
        (0 <= ny) &&
        (board[x].length() > ny))
        {
            if(board[x][y] != EMPTY)
            {
                if((board[x][y] == board[x][ny]) &&
                (board[x][y] == board[nx][y]) &&
                (board[x][y] == board[nx][ny]))
                {
                    visited[x][y] = true;
                    visited[x][ny] = true;
                    visited[nx][y] = true;
                    visited[nx][ny] = true;
                    isSameStr = true;
                }
            }
        }
    }
    return isSameStr;
}

int getDeleteCount(const vector<vector<bool>> &visited)
{
    int count = 0;
    for(vector<bool> x : visited)
    {
        for(bool isVisited : x)
        {
            if(isVisited)
            {
                count++;
            }
        }
    }
    return count;
}

void updateBoard(vector<string> &board, const vector<vector<bool>> &visited)
{
    for(int x = 0; x < visited.size(); x++)
    {
        for(int y = 0; y < visited[x].size(); y++)
        {
            if(visited[x][y])
            {
                board[x][y] = EMPTY;
            }
        }
    }

    for(int x = board.size() - 1; x > 0; x--)
    {
        for(int y = 0; y < board[x].length(); y++)
        {
            if(board[x][y] == EMPTY)
            {
                for(int nx = x - 1; nx > -1; nx--)
                {
                    if(board[nx][y] != EMPTY)
                    {
                        board[x][y] = board[nx][y];
                        board[nx][y] = EMPTY;
                        break;
                    }
                }
            }
        }
    }
}

int solution(int m, int n, vector<string> board)
{
    int answer = 0;

    while(true)
    {
        bool isSame = false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].length(), false));
        for(int x = 0; x < m; x++)
        {
            for(int y = 0; y < n; y++)
            {
                if(visited[x][y])
                {
                    continue;
                }

                if(isSameStr(x, y, board, visited))
                {
                    isSame = true;
                }
            }
        }

        if(!isSame)
        {
            break;
        }

        answer += getDeleteCount(visited);
        updateBoard(board, visited);
    }

    return answer;
}

int main()
{
    int m = 6;
    int n = 6;
    vector<string> board;
    board.emplace_back("TTTANT");
    board.emplace_back("RRFACC");
    board.emplace_back("RRRFCC");
    board.emplace_back("TRRRAA");
    board.emplace_back("TTMMMF");
    board.emplace_back("TMMTTJ");

    int result = solution(m, n, board);

    cout << result;

    return 0;
}