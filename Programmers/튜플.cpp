/**************************
문제의 핵심 ( 2019 kakao developer winter internship )
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void getTuple(string s, vector<vector<int>> &tuples)
{
    stringstream ss(s);
    string temp;
    while(getline(ss, temp, '{'))
    {
        stringstream tempSs(temp);
        string tuple;
        while(getline(tempSs, tuple, '}'))
        {
            stringstream tupleStream(tuple);
            string num;
            vector<int> list;
            while(getline(tupleStream, num, ','))
            {
                if(num != "")
                {
                    list.emplace_back(stoi(num));
                }
            }
            if(!list.empty())
            {
                tuples.emplace_back(list);
            }
        }
    }
}

bool cmp(vector<int> &lvalue, vector<int> &rvalue)
{
    return lvalue.size() < rvalue.size();
}

vector<int> solution(string s)
{
    vector<int> answer;

    vector<vector<int>> tuples;

    getTuple(s, tuples);

    sort(tuples.begin(), tuples.end(), cmp);

    for(auto &tuple : tuples)
    {
        for(int num : tuple)
        {
            if(find(answer.begin(), answer.end(), num) == answer.end())
            {
                answer.emplace_back(num);
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> results = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
    

    for(int &result : results)
    {
        cout << result << endl;
    }

    return 0;
}