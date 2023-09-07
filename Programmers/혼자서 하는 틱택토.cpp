/**************************
문제의 핵심
1. 경우의 수를 정리할 것
**************************/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static const char FIRST = 'O';
static const char SECOND = 'X';

static const int SUCCESS = 1;
static const int FAIL = 0;

void isWidth(vector<string> board, int &isPossibleFirst, int &isPossibleSecond)
{
    for(int idx = 0; idx < 3; idx++)
    {
        if(board[idx].at(0) == board[idx].at(1) && board[idx].at(0) == board[idx].at(2))
        {
            if (board[idx].at(0) == FIRST)
            {
                isPossibleFirst++;
            }
            else if (board[idx].at(0) == SECOND)
            {
                isPossibleSecond++;
            }
        }
    }
}

void isLength(vector<string> board, int &isPossibleFirst, int &isPossibleSecond)
{
    for(int idx = 0; idx < 3; idx++)
    {
        if(board[0][idx] == board[1][idx] && board[0][idx] == board[2][idx])
        {
            if (board[0].at(idx) == FIRST)
            {
                isPossibleFirst++;
            }
            else if (board[0].at(idx) == SECOND)
            {
                isPossibleSecond++;
            }
        }
    }
}

void isDiagonal(vector<string> board, int &isPossibleFirst, int &isPossibleSecond)
{
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        if (board[0].at(0) == FIRST)
        {
            isPossibleFirst++;
        }
        else if (board[0].at(0) == SECOND)
        {
            isPossibleSecond++;
        }
    }

    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        if (board[0].at(2) == FIRST)
        {
            isPossibleFirst++;
        }
        else if (board[0].at(2) == SECOND)
        {
            isPossibleSecond++;
        }
    }
}

int solution(vector<string> board)
{
    int answer = 0;
    int isPossibleFirst = 0;
    int isPossibleSecond = 0;

    isWidth(board, isPossibleFirst, isPossibleSecond);
    isLength(board, isPossibleFirst, isPossibleSecond);
    isDiagonal(board, isPossibleFirst, isPossibleSecond);

    //check count
    int cntFirst = 0;
    int cntSecond = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == FIRST)
            {
                cntFirst++;
            }
            else if(board[i][j] == SECOND)
            {
                cntSecond++;
            }
        }
    }

    if(isPossibleFirst == 0 && isPossibleSecond == 0)
    {
        if((cntFirst == cntSecond) || (cntFirst - 1 == cntSecond))
        {
            answer = 1;
        }
    }
    else if(isPossibleFirst == 1 && isPossibleSecond == 0)
    {
        if(cntFirst - 1 == cntSecond)
        {
            answer = 1;
        }
    }
    else if(isPossibleFirst == 0 && isPossibleSecond == 1)
    {
        if(cntFirst == cntSecond)
        {
            answer = 1;
        }
    }
    else if(isPossibleFirst == 2 && isPossibleSecond == 0)
    {
        if(cntFirst - 1 == cntSecond)
        {
            answer = 1;
        }
    }

    return answer;
}

int main()
{
    vector<string> board;

    board.emplace_back("XXX");
    board.emplace_back("OOO");
    board.emplace_back("OXO");

    int isFin = solution(board);
    
    return 0;
}