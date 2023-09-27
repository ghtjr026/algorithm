/**************************
문제의 핵심 ( 월간 코드 챌린지 시즌1 )
1. dfs를 사용할 것을 인지할 것

2. dfs에서 arr을 넘길 때 참조로 넘기지 않으면 매번 복사가 발생해서 시간초과가 뜸
-> 참조로 넘기면 복사가 발생하지 않아 통과함
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(int x, int y, int length, int &cntOne, int &cntZero, vector<vector<int>> &arr)
{
    int one = 0;
    int zero = 0;

    bool flag = true;
    int num = arr[x][y];
    for(int i = x; i < x + length; i++)
    {
        for(int j = y; j < y + length; j++)
        {
            if(num != arr[i][j])
            {
                flag = false;
                break;
            }
        }
    }

    if(flag)
    {
        if(num == 0)
        {
            cntZero++;
        }
        else
        {
            cntOne++;
        }
        return;
    }

    //left up
    dfs(x, y, length / 2, cntOne, cntZero, arr);
    //right up
    dfs(x + length / 2, y, length / 2, cntOne, cntZero, arr);
    //left down
    dfs(x, y + length / 2, length / 2, cntOne, cntZero, arr);
    //right down
    dfs(x + length / 2, y + length / 2, length / 2, cntOne, cntZero, arr);

    return;
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;

    int cntOne = 0;
    int cntZero = 0;

    dfs(0, 0, arr.size(), cntOne, cntZero, arr);

    answer.emplace_back(cntZero);
    answer.emplace_back(cntOne);

    return answer;
}

int main()
{
    vector<vector<int>> arr;
    vector<int> list;
    list.emplace_back(1);
    list.emplace_back(1);
    list.emplace_back(0);
    list.emplace_back(0);
    arr.emplace_back(list);
    list.clear();

    list.emplace_back(1);
    list.emplace_back(0);
    list.emplace_back(0);
    list.emplace_back(0);
    arr.emplace_back(list);
    list.clear();

    list.emplace_back(1);
    list.emplace_back(0);
    list.emplace_back(0);
    list.emplace_back(1);
    arr.emplace_back(list);
    list.clear();

    list.emplace_back(1);
    list.emplace_back(1);
    list.emplace_back(1);
    list.emplace_back(1);
    arr.emplace_back(list);
    list.clear();

    vector<int> results = solution(arr);

    for(int result: results)
    {
        cout << result << endl;
    }

    return 0;
}