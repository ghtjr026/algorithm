/**************************
문제의 핵심
1. 그래프를 만들 것

2. 이어진 두 node를 기준으로 트리 수를 구할 것

3. 두 트리 수의 차를 계산
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

static const int START = 0;
static const int END = 1;

int getCount(vector<vector<int>> map, int start, vector<bool> visited)
{
    queue<int> q;
    q.push(start);
    int count = 0;

    while(!q.empty())
    {
        int nodeNum = q.front();
        q.pop();
        visited[nodeNum] = true;
        count++;

        for(int &node : map[nodeNum])
        {
            if(!visited[node])
            {
                q.push(node);
            }
        }
    }
    return count;
}

bool isExist(vector<int> list, int end)
{
    bool isExist = false;
    
    for(auto num : list)
    {
        if(num == end)
        {
            isExist = true;
            break;
        }
    }

    return isExist;
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = n;

    vector<vector<int>> map(n+1);

    for(vector<int> &wire : wires)
    {
        if(!isExist(map[wire[START]], wire[END]))
        {
            map[wire[START]].emplace_back(wire[END]);
        }
        
        if(!isExist(map[wire[END]], wire[START]))
        {
            map[wire[END]].emplace_back(wire[START]);
        }
    }

    for(vector<int> &wire: wires)
    {
        vector<bool> visited(n+1, false);
        visited[wire[START]] = true;
        visited[wire[END]] = true;
        int startCnt = getCount(map, wire[START], visited);
        int endCnt = getCount(map, wire[END], visited);
        answer = min(answer, abs(startCnt - endCnt));
    }

    return answer;
}

int main()
{
    int n = 4;

    vector<int> wire;
    vector<vector<int>> wires;

    wire.emplace_back(1);
    wire.emplace_back(2);
    wires.emplace_back(wire);
    wire.clear();

    wire.emplace_back(2);
    wire.emplace_back(3);
    wires.emplace_back(wire);
    wire.clear();

    wire.emplace_back(3);
    wire.emplace_back(4);
    wires.emplace_back(wire);
    wire.clear();
    

    int result = solution(n, wires);

    cout << result << endl;

    return 0;
}