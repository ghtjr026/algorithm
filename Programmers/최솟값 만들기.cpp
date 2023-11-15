/**************************
문제의 핵심
1. 유의사항 없음
**************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int& lvalue, int& rvalue)
{
    return lvalue > rvalue;
}

bool cmp1(int& lvalue, int& rvalue)
{
    return lvalue < rvalue;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp1);

    for(int i = 0; i < A.size(); i++)
    {
        answer += A[i] * B[i];
    }

    return answer;
}

int main()
{
    return 0;
}