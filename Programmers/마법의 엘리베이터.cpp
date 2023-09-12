/**************************
문제의 핵심
1. 반례를 잘 찾을 것
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int storey)
{
    int answer = 0;

    while(storey != 0)
    {
        int n = storey % 10;
        if(5 < n)
        {
            answer += (10 - n);
            storey += 10;
        }
        else if((n == 5) && ((storey / 10) % 10 >= 5)) // >=, ex 555
        {
            answer += (10 - n);
            storey += 10;
        }
        else
        {
            answer += n;
        }
        storey /= 10;
    }

    return answer;
}

int main()
{
    int storey;

    //get storey
    storey = 49;

    int minimum = solution(storey);

    cout << minimum;

    return 0;
}