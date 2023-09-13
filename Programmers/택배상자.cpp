/**************************
문제의 핵심
1. stack 활용해야 한다고 생각이 나야함
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void checkContainer(stack<int> &container, vector<int> &order, int &answer)
{
    while (!container.empty())
    {
        int boxNum = container.top();
        container.pop();

        if (boxNum == order[answer])
        {
            answer++;
        }
        else
        {
            container.push(boxNum);
            break;
        }
    }
}

int solution(vector<int> order)
{
    int answer = 0;

    stack<int> container;
    for(int box = 1; box <= order.size();)
    {
        if(box == order[answer])
        {
            box++;
            answer++;
        }

        checkContainer(container, order, answer);
        container.push(box++);
    }

    checkContainer(container, order, answer);

    return answer;
}

int main()
{
    vector<int> order;
    order.emplace_back(3);
    order.emplace_back(2);
    order.emplace_back(1);
    order.emplace_back(4);
    order.emplace_back(5);

    int result = solution(order);

    cout << result;

    return 0;
}