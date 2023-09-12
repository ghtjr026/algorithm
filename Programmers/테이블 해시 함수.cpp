/**************************
문제의 핵심
1. XOR연산 -> ^
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int COL = 0;

bool cmp(vector<int> &lvalue, vector<int> &rvalue)
{
    if(lvalue[COL] == rvalue[COL])
    {
        return lvalue[0] > rvalue[0];
    }
    return lvalue[COL] < rvalue[COL];
}

vector<long> getSum(vector<vector<int>> data)
{
    vector<long> sum;

    for(int idx = 0; idx < data.size(); idx++)
    {
        long value = 0;
        for(int i = 0; i < data[idx].size(); i++)
        {
            value += (data[idx][i] % (idx + 1));
        }
        sum.emplace_back(value);
    }

    return sum;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
    int answer = 0;
    col--;
    row_begin--;

    COL = col;
    sort(data.begin(), data.end(), cmp);

    vector<long> dataSum = getSum(data);
    
    while(row_begin != row_end)
    {
        answer = answer ^ dataSum[row_begin];
        row_begin++;
    }

    return answer;
}

int main()
{
    vector<vector<int>> datas;
    vector<int> data;
    //get data
    data.emplace_back(2);
    data.emplace_back(2);
    data.emplace_back(6);
    datas.emplace_back(data);
    data.clear();

    data.emplace_back(1);
    data.emplace_back(5);
    data.emplace_back(10);
    datas.emplace_back(data);
    data.clear();

    data.emplace_back(4);
    data.emplace_back(2);
    data.emplace_back(9);
    datas.emplace_back(data);
    data.clear();

    data.emplace_back(3);
    data.emplace_back(8);
    data.emplace_back(3);
    datas.emplace_back(data);
    data.clear();

    int col = 2;
    int row_begin = 2;
    int row_end = 3;

    int result = solution(datas, col, row_begin, row_end);

    cout << result;

    return 0;
}