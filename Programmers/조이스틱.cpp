/**************************
문제의 핵심
1. 문제의 분류가 Greedy이지만 Greedy로 풀면 안됨

2. 51 line이 없으면 아래 예가 최소가 안나옴을 유의해야 함
-> BBABA / min : 6
-> without 51 line : 7
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name)
{
    int answer = 0;

    vector<int> idxList;
    int index = 0;
    for(char &str : name)
    {
        answer += min(str - 'A', 'Z' - str + 1);
        if(str != 'A')
        {
            idxList.emplace_back(index);
        }
        index++;
    }

    int move = name.size() - 1;
    if(idxList.size() == 0)
    {
        move = 0;
    }
    else if(idxList.size() == 1)
    {
        int length1 = idxList[0];
        int length2 = name.size() - idxList[0];
        move = min(move, min(length1, length2));
    }
    else
    {
        for (int idx = 1; idx < idxList.size(); idx++)
        {
            int length1 = idxList[idx - 1];
            int length2 = name.size() - idxList[idx];

            move = min(move, length1 + length2 + min(length1, length2));
        }

        move = min(move, idxList[idxList.size() - 1]);
    }

    return answer + move;
}

int main()
{
    int result = solution("BBABA");

    cout << result;

    return 0;
}