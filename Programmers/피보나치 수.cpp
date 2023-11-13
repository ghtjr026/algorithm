/**************************
문제의 핵심
1. 유의사항 없음
**************************/
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    vector<int> list;

    list.emplace_back(0);
    list.emplace_back(1);

    for(int i = 2; i <= n; i++)
    {
        long num = list[i - 2] + list[i - 1];
        list.emplace_back(num % 1234567);
    }

    return list[n];
}

int main()
{
    return 0;
}