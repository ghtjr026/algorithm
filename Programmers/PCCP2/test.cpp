#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<int, int> getDirt(char str, pair<int, int> dirt)
{
    int x = dirt.first;
    int y = dirt.second;
    if(str == 'R')
    {
        if(x == 0 && y == 1)
        {
            x = 1;
            y = 0;
        }
        else if(x == 1 && y == 0)
        {
            x = 0;
            y = -1;
        }
        else if(x == 0 && y == -1)
        {
            x = -1;
            y = 0;
        }
        else
        {
            x = 0;
            y = 1;
        }
    }
    else if(str == 'L')
    {
        if(x == 0 && y == 1)
        {
            x = -1;
            y = 0;
        }
        else if(x == 1 && y == 0)
        {
            x = 0;
            y = 1;
        }
        else if(x == 0 && y == -1)
        {
            x = 1;
            y = 0;
        }
        else
        {
            x = 0;
            y = -1;
        }
    }
    return make_pair(x, y);    
}

vector<int> solution(string command)
{
    vector<int> answer;

    pair<int, int> dirt = make_pair(0, 1);
    pair<int, int> position = make_pair(0, 0);

    for(char str : command)
    {
        if(str == 'G')
        {
            position.first += dirt.first;
            position.second += dirt.second;
        }
        else if(str == 'B')
        {
            position.first -= dirt.first;
            position.second -= dirt.second;
        }
        else
        {
            dirt = getDirt(str, dirt);
        }
    }

    answer.emplace_back(position.first);
    answer.emplace_back(position.second);

    return answer;
}

int main()
{
    vector<int> results = solution("GRGLGRG");

    for(int result : results)
    {
        cout << result << endl;
    }

    return 0;
}