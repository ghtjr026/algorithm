/**************************
문제의 핵심 ( Summer/Winter Coding(~2018) )
1. bfs로 해결함

2. 유의사항
-> 거리가 갱신되었을 때, 이미 지나간 마을도 다시 계산이 필요하다는 것을 인지할 것
**************************/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> bfs(vector<vector<pair<int, int>>> &graph, vector<bool> &visited)
{
    vector<int> minWeight(visited.size(), 9999999);
    minWeight[1] = 0;

    queue<int> town;
    town.push(1);

    while(!town.empty())
    {
        int start = town.front();
        town.pop();

        if(visited[start])
        {
            continue;
        }

        visited[start] = true;

        for(int idx = 0; idx < graph[start].size(); idx++)
        {
            int dest = graph[start][idx].first;
            int weight = graph[start][idx].second;

            if(minWeight[dest] > minWeight[start] + weight)
            {
                visited[start] = false;
                visited[dest] = false;
                minWeight[dest] = minWeight[start] + weight;
                town.push(dest);
            }
        }
    }

    return minWeight;
}

bool cmp(pair<int, int> rvalue, pair<int, int> lvalue)
{
    return rvalue.first < lvalue.first;
}

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;

    vector<vector<pair<int, int>>> graph(N + 1); // destination, weight
    vector<bool> visited(N + 1, false);

    for(vector<int> infos : road)
    {
        graph[infos[0]].emplace_back(make_pair(infos[1], infos[2]));
        graph[infos[1]].emplace_back(make_pair(infos[0], infos[2]));
    }

    for(int idx = 0; idx < graph.size(); idx++)
    {
        sort(graph[idx].begin(), graph[idx].end(), cmp);
    }

    vector<int> weights = bfs(graph, visited);

    for(int weight : weights)
    {
        if(weight <= K)
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    int n = 5;
    int k = 3;
    vector<vector<int>> road;
    vector<int> info;
    info.emplace_back(1);
    info.emplace_back(2);
    info.emplace_back(1);
    road.emplace_back(info);
    info.clear();

    info.emplace_back(2);
    info.emplace_back(3);
    info.emplace_back(3);
    road.emplace_back(info);
    info.clear();

    info.emplace_back(5);
    info.emplace_back(2);
    info.emplace_back(2);
    road.emplace_back(info);
    info.clear();

    info.emplace_back(1);
    info.emplace_back(4);
    info.emplace_back(2);
    road.emplace_back(info);
    info.clear();

    info.emplace_back(5);
    info.emplace_back(3);
    info.emplace_back(1);
    road.emplace_back(info);
    info.clear();

    info.emplace_back(5);
    info.emplace_back(4);
    info.emplace_back(2);
    road.emplace_back(info);
    info.clear();

    int result = solution(n, road, k);

    cout << result;

    return 0;
}