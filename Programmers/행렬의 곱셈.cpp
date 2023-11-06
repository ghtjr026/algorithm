/**************************
문제의 핵심
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));

    for(int x = 0; x < answer.size(); x++)
    {
        for(int y = 0; y < answer[x].size(); y++)
        {
            for(int idx = 0; idx < arr2.size(); idx++)
            {
                answer[x][y] += (arr1[x][idx] * arr2[idx][y]);
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> arr1;
    vector<int> temp;
    temp.emplace_back(2);
    temp.emplace_back(3);
    temp.emplace_back(2);
    arr1.emplace_back(temp);
    temp.clear();

    temp.emplace_back(4);
    temp.emplace_back(2);
    temp.emplace_back(4);
    arr1.emplace_back(temp);
    temp.clear();

    temp.emplace_back(3);
    temp.emplace_back(1);
    temp.emplace_back(4);
    arr1.emplace_back(temp);
    temp.clear();

    vector<vector<int>> arr2;
    temp.emplace_back(5);
    temp.emplace_back(4);
    temp.emplace_back(3);
    arr2.emplace_back(temp);
    temp.clear();

    temp.emplace_back(2);
    temp.emplace_back(4);
    temp.emplace_back(1);
    arr2.emplace_back(temp);
    temp.clear();

    temp.emplace_back(3);
    temp.emplace_back(1);
    temp.emplace_back(1);
    arr2.emplace_back(temp);
    temp.clear();

    vector<vector<int>> matrix = solution(arr1, arr2);

    for(vector<int> arr : matrix)
    {
        for(int num : arr)
        {
            cout << num << ' ';
        }
        cout << endl;
    }

    return 0;
}