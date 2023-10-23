/**************************
풀이 실패..
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct node
{
    int x;
    int y;
    bool status;
    node(int x1, int y1, bool status1)
    {
        x = x1;
        y = y1;
        status = status1;
    }
};

int solution(int n, int m, vector<vector<int>> hole)
{
    int answer = 0;

    vector<vector<int>> visited(n, vector<int>(m, 99999));
    visited[0][0] = 0;

    vector<pair<int, int>> holes;
    for(vector<int> info : hole)
    {
        holes.emplace_back(make_pair((info[0] - 1), (info[1] - 1)));
    }

    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < m; y++)
        {
            if(x == 0 && y == 0)
            {
                continue;
            }

            if(find(holes.begin(), holes.end(), make_pair(x, y)) == holes.end())
            {
                // compare left and down value and then get min value

            }
        }
    }

    return answer;
}

int main()
{
    int n = 4;
    int m = 4;
    vector<vector<int>> hole;
    vector<int> info;
    info.emplace_back(2);
    info.emplace_back(3);
    hole.emplace_back(info);
    info.clear();

    info.emplace_back(3);
    info.emplace_back(3);
    hole.emplace_back(info);
    info.clear();

    int result = solution(n, m, hole);

    cout << result;

    return 0;
}