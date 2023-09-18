/**************************
문제의 핵심
1. 행과 열을 비교해서 큰 값이 배열에 들어가는 것을 인지할 것
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;

    for(long long i = left; i <= right; i++)
    {
        int row = i / n + 1;
        int cell = i % n + 1;

        answer.emplace_back(max(row, cell));
    }

    return answer;
}

int main()
{
    int n = 3;
    long long left = 2;
    long long right = 5;

    vector<int> result = solution(n, left, right);

    for(int &i : result)
    {
        cout << i << endl;
    }

    return 0;
}