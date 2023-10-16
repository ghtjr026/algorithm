/**************************
문제의 핵심
1. 안입는 경우를 대비하여 25 line에 1을 더하여 곱을 해주는 것임

2. 모두다 안입는 경우가 있기때문에  마지막에 1을 빼는 것임
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;

    map<string, int> cntDress;

    for(vector<string> &dress : clothes)
    {
        cntDress[dress.at(1)]++;
    }

    for(auto &dress : cntDress)
    {
        answer *= dress.second + 1;
    }

    return answer - 1;
}

int main()
{
    vector<vector<string>> clothes;
    vector<string> dress;
    dress.emplace_back("yellow_hat");
    dress.emplace_back("headgear");
    clothes.emplace_back(dress);
    dress.clear();

    dress.emplace_back("blue_sunglasses");
    dress.emplace_back("eyewear");
    clothes.emplace_back(dress);
    dress.clear();

    dress.emplace_back("green_turban");
    dress.emplace_back("headgear");
    clothes.emplace_back(dress);
    dress.clear();

    int result = solution(clothes);

    cout << result;

    return 0;
}