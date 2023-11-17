/**************************
문제의 핵심
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool cmp(int& lvalue, int& rvalue)
{
    return lvalue < rvalue;
}

string solution(string s)
{
    string answer = "";

    vector<int> list;

    stringstream ss(s);
    string temp;
    while(getline(ss, temp, ' '))
    {
        list.emplace_back(stoi(temp));
    }

    sort(list.begin(), list.end(), cmp);

    answer += to_string(list.at(0));
    answer += " ";
    answer += to_string(list.at(list.size() - 1));

    return answer;
}

int main()
{
    string result = solution("-1 -2 -3 -4");

    cout << result;

    return 0;
}