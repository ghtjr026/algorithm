/**************************
문제의 핵심 ( 2018 kakao blind recruitment )
1. sort와 stable_sort의 차이점을 유의할 것
-> sort : Quick 정렬을 사용하고, 같은 항목일 경우 정렬하기 전의 순서를 보장하지 않음
-> stable_sort : 병합정렬을 사용하고, 같은 항목일 경우 이전 순서를 보장하고 있음

2. compare 함수 사용시, const&를 권장하고 있으며, 전달받은 인자가 변경되어서는 안된다
-> &타입은 사용할 수 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

void getSubstring(string str, string &head, int &num)
{
    string temp;
    int idx = 0;
    for(; idx < str.length(); idx++)
    {
        if((0 <= str[idx] - '0') && 
        (9 >= str[idx] - '0'))
        {
            break;
        }
        temp += char(tolower(str[idx]));
    }
    head = temp;
    temp = "";

    for(; idx < str.length(); idx++)
    {
        if((0 > str[idx] - '0') &&
        (9 < str[idx] - '0'))
        {
            break;
        }

        temp += str[idx];
        if(temp.length() == 5)
        {
            break;
        }
    }

    if(temp != "")
    {
        num = stoi(temp);
    }
}

bool cmp(const string &lvalue, const string &rvalue)
{
    string lvalueHead;
    int lvalueNum;
    getSubstring(lvalue, lvalueHead, lvalueNum);

    string rvalueHead;
    int rvalueNum;
    getSubstring(rvalue, rvalueHead, rvalueNum);

    if(lvalueHead != rvalueHead)
    {
        return lvalueHead < rvalueHead;
    }
    else
    {
        if(lvalueNum == rvalueNum)
        {
            return false;
        }
        else
        {
            return lvalueNum < rvalueNum;
        }
    }
}

vector<string> solution(vector<string> files)
{
    stable_sort(files.begin(), files.end(), cmp);

    return files;
}

int main()
{
    vector<string> files;
    files.emplace_back("abc");
    files.emplace_back("acb");
    files.emplace_back("abd");

    vector<string> results = solution(files);

    for(string &result : results)
    {
        cout << result << endl;
    }

    return 0;
}