#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool isAloneAlpha(vector<int> list)
{
    bool isAloneAlpha = false;
    for(int idx = 0; idx < list.size() - 1; idx++)
    {
        if(list[idx + 1] - list[idx] != 1)
        {
            isAloneAlpha = true;
            break;
        }
    }
    return isAloneAlpha;
}

string solution(string input_string)
{
    string answer = "";

    map<char, vector<int>> list;

    for(int idx = 0; idx < input_string.length(); idx++)
    {
        list[input_string[idx]].emplace_back(idx);
    }

    for(map<char, vector<int>>::iterator it = list.begin(); it != list.end(); it++)
    {
        if(isAloneAlpha(it->second))
        {
            answer += it->first;
        }
    }

    if(answer.empty())
    {
        return "N";
    }
    return answer;
}

int main()
{
    string result = solution("");

    cout << result;

    return 0;
}