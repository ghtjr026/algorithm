/**************************
문제의 핵심 ( 2021 kakao blind Recruitment )
1. map을 사용할 것을 인지할 것

2. order는 정렬되어 있지 않음을 유의할 것

3. dfs로 course 별 문자열을 모두 counting할 것
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void dfs(int index, int course, string order, string item, vector<bool> &visited, map<string, int> &combination)
{
    if (item.length() == course)
    {
        ++combination[item];
        return;
    }

    for (int idx = index; idx < order.length(); idx++)
    {
        if (!visited[idx])
        {
            visited[idx] = true;
            item.push_back(order[idx]);
            dfs(idx + 1, course, order, item, visited, combination);
            visited[idx] = false;
            item.pop_back();
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for (int &condition : course)
    {
        map<string, int> combination;
        for (string order : orders)
        {
            if (order.length() < condition)
            {
                continue;
            }
            vector<bool> visited(order.size(), false);
            string temp;
            sort(order.begin(), order.end());
            dfs(0, condition, order, temp, visited, combination);
        }

        map<string, int>::iterator maxCountMap = max_element(combination.begin(), combination.end(),
                                                             [](const auto &lvalue, const auto &rvalue)
                                                             { return lvalue.second < rvalue.second; });

        if (1 < maxCountMap->second)
        {
            for (auto &list : combination)
            {
                if (list.second == maxCountMap->second)
                {
                    answer.emplace_back(list.first);
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<string> orders;
    orders.emplace_back("ABCDE");
    orders.emplace_back("AB");
    orders.emplace_back("CD");
    orders.emplace_back("ADE");
    orders.emplace_back("XYZ");
    orders.emplace_back("XYZ");
    orders.emplace_back("ACD");

    vector<int> course;
    course.emplace_back(2);
    course.emplace_back(3);
    course.emplace_back(5);

    vector<string> results = solution(orders, course);

    for (string result : results)
    {
        cout << result << endl;
    }

    return 0;
}