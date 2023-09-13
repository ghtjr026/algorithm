/**************************
문제의 핵심
1. 최대 공약수를 구해야함
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int &lvalue, int &rvalue)
{
    return lvalue > rvalue;
}

int getMinMult(vector<int> array)
{
    int result = 0;

    for (int i = array[0]; i > 1; i--)
    {
        bool isPossible = true;
        for (int &num : array)
        {
            if (num % i != 0)
            {
                isPossible = false;
                break;
            }
        }

        if (isPossible)
        {
            result = i;
            break;
        }
    }

    return result;
}

bool isDivide(int min, vector<int> array)
{
    if (min != 0)
    {
        for (int &num : array)
        {
            if (num % min == 0)
            {
                return true;
            }
        }
    }
    return false;
}

int solution(vector<int> arrayA, vector<int> arrayB)
{
    int answer = 0;

    sort(arrayA.begin(), arrayA.end(), cmp);
    sort(arrayB.begin(), arrayB.end(), cmp);

    int minA = getMinMult(arrayA);
    int minB = getMinMult(arrayB);

    if (!isDivide(minA, arrayB) && !isDivide(minB, arrayA))
    {
        answer = max(minA, minB);
    }
    else if(!isDivide(minA, arrayB))
    {
        answer = minA;
    }
    else if(!isDivide(minB, arrayA))
    {
        answer = minB;
    }

    return answer;
}

int main()
{
    vector<int> A;
    A.emplace_back(14);
    A.emplace_back(35);
    A.emplace_back(119);

    vector<int> B;
    B.emplace_back(18);
    B.emplace_back(30);
    B.emplace_back(102);

    int result = solution(A, B);

    cout << result;

    return 0;
}