/**************************
문제의 핵심 ( 2020 kakao intership )
1. stack을 활용할 것을 인지할 것

2. num과 operator stack을 사용할 것

3. stack 이기 때문에 먼저 pop하는 것이 뒤에 있는 숫자임을 인지할 것
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
vector<map<char, int>> priorities;

void init()
{
    map<char,int> priority;
    priority.insert({'*', 0});
    priority.insert({'+', 1});
    priority.insert({'-', 2});
    priorities.emplace_back(priority);
    priority.clear();

    priority.insert({'*', 0});
    priority.insert({'+', 2});
    priority.insert({'-', 1});
    priorities.emplace_back(priority);
    priority.clear();

    priority.insert({'*', 1});
    priority.insert({'+', 0});
    priority.insert({'-', 2});
    priorities.emplace_back(priority);
    priority.clear();

    priority.insert({'*', 1});
    priority.insert({'+', 2});
    priority.insert({'-', 0});
    priorities.emplace_back(priority);
    priority.clear();

    priority.insert({'*', 2});
    priority.insert({'+', 1});
    priority.insert({'-', 0});
    priorities.emplace_back(priority);
    priority.clear();

    priority.insert({'*', 2});
    priority.insert({'+', 0});
    priority.insert({'-', 1});
    priorities.emplace_back(priority);
    priority.clear();
}

void splitString(string expression, vector<long long> &nums, vector<char> &operators)
{
    string temp;
    for(char &str : expression)
    {
        if((str == '*') || 
        (str == '-') ||
        (str == '+'))
        {
            nums.emplace_back(stoi(temp));
            temp.clear();
            operators.emplace_back(str);
        }
        else
        {
            temp += str;
        }
    }
    nums.emplace_back(stoi(temp));
}

long long calc(long long num1, long long num2, char oper)
{
    long long result;
    switch (oper)
    {
    case '*':
        result = num1 * num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '+':
        result = num1 + num2;
        break;
    }

    return result;
}

long long solution(string expression)
{
    init();
    long long answer = 0;

    vector<long long> nums;
    vector<char> operators;

    splitString(expression, nums, operators);

    for(auto &priority : priorities)
    {
        vector<long long> tempNum = nums;
        vector<char> tempOper = operators;
        
        for(int idx = 0; idx < priority.size(); idx++)
        {
            vector<long long> stNum;
            vector<char> stOper;

            stNum.emplace_back(tempNum[0]);
            int numIdx = 1;
            for(char &oper : tempOper)
            {
                stNum.emplace_back(tempNum[numIdx++]);
                stOper.emplace_back(oper);

                if(idx == priority.at(oper))
                {
                    long long num1 = stNum.back();
                    stNum.pop_back();
                    long long num2 = stNum.back();
                    stNum.pop_back();
                    stOper.pop_back();
                    stNum.emplace_back(calc(num2, num1, oper));
                }
            }

            tempNum = stNum;
            tempOper = stOper;
        }
        answer = max(answer, abs(tempNum.back()));
    }

    return answer;
}

int main()
{
    long long result = solution("100-200*300-500+20");
    // nums : 100 200 300 500 20
    // oper : - * - +

    cout << result << endl;

    return 0;
}