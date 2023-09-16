/**************************
문제의 핵심
1. 소수로 변환 시 int 범위를 넘어선 값이 있을 수 있음
-> 따라서, stoi 가 아닌 stoull ( unsigned long long ) 으로 변환할 것

2. 소수 확인 시 제곱근까지 확인할 것
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

vector<long long> split(string str)
{
    vector<long long> checkList;
    stringstream ss(str);
    string temp;

    while(getline(ss, temp, '0'))
    {
        if(temp != "")
        {
            checkList.emplace_back(stoull(temp));
        }
    }

    return checkList;
}

int isPrime(vector<long long> checkList)
{
    int answer = 0;

    for (long long num : checkList)
    {
        if (num != 1)
        {
            bool isPrime = true;
            for (long long deNum = 2; deNum <= sqrt(num); deNum++)
            {
                if (num % deNum == 0)
                {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime)
            {
                answer++;
            }
        }
    }

    return answer;
}

int solution(int n, int k)
{
    string changeNum = "";

    while(n > 0)
    {
        changeNum += to_string(n % k);
        n /= k;
    }

    reverse(changeNum.begin(), changeNum.end());

    vector<long long> checkList = split(changeNum);

    int answer = isPrime(checkList);

    return answer;
}

int main()
{
    int n = 1000000;
    int k = 10;

    int answer = solution(n, k);

    cout << answer;

    return 0;
}