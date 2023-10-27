/**************************
문제의 핵심
1. 최대공약수를 구하는 함수 getGCD
-> 매개변수 num이 num1 보다 항상 커야함

2. 최대 공배수 = num * num1 / getGCD
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getGCD(int num, int num1)
{
    int remain;
    while(num1 != 0)
    {
        remain = num % num1;
        num = num1;
        num1 = remain;
    }

    return num;
}

int solution(vector<int> arr)
{
    int answer = arr[0];

    for(int idx = 1; idx < arr.size(); idx++)
    {
        answer = (answer * arr[idx]) / (getGCD(answer, arr[idx]));
    }

    return answer;
}

int main()
{
    vector<int> arr;
    arr.emplace_back(2);
    arr.emplace_back(6);
    arr.emplace_back(8);
    arr.emplace_back(14);

    int result = solution(arr);

    cout << result;

    return 0;
}