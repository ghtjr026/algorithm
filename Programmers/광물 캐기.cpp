/**************************
문제의 핵심
1. 광물을 캘수 있는 최대 수를 먼저 구하기

2. 광물을 캘 수 있는 최대 수에 맞게 광물을 5개씩 나누기

3. 나눠진 광물을 diamond / iron / stone 이 많은 순으로 정렬

4. 피로도 계산
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static const int DIAMOND = 0;
static const int IRON = 1;
static const int STONE = 2;

int getMaxMinerals(int dia, int iron, int stone, int minerals)
{
    return min(dia * 5 + iron * 5 + stone * 5, minerals);
}

vector<vector<string>> getMineralsList(vector<string> minerals, int maxMinerals)
{
    vector<vector<string>> mineralsList;

    vector<string> chunkMinerals;
    for(int idx = 0; idx < maxMinerals; idx++)
    {
        chunkMinerals.emplace_back(minerals[idx]);
        if(chunkMinerals.size() == 5)
        {
            mineralsList.emplace_back(chunkMinerals);
            chunkMinerals.clear();
        }
    }

    if(!chunkMinerals.empty())
    {
        mineralsList.emplace_back(chunkMinerals);
    }

    return mineralsList;
}

bool cmp(vector<string> &lvalue, vector<string> &rvalue)
{
    int lDia = count(lvalue.begin(), lvalue.end(), "diamond");
    int rDia = count(rvalue.begin(), rvalue.end(), "diamond");

    if (lDia == rDia)
    {
        int lIron = count(lvalue.begin(), lvalue.end(), "iron");
        int rIron = count(rvalue.begin(), rvalue.end(), "iron");
        return lIron > rIron;
    }
    return lDia > rDia;
}

int solution(vector<int> picks, vector<string> minerals)
{
    int answer = 0; // minimum fatigue(피로도)

    int maxMinerals = 9999;
    maxMinerals = getMaxMinerals(picks[DIAMOND], picks[IRON], picks[STONE], minerals.size());

    vector<vector<string>> mineralsList = getMineralsList(minerals, maxMinerals);

    sort(mineralsList.begin(), mineralsList.end(), cmp);

    for(int i = 0; i < mineralsList.size(); i++)
    {
        for(int j = 0; j < mineralsList[i].size(); j++)
        {
            cout << mineralsList[i][j] << " ";
        }
        cout << endl;
    }

    while(true)
    {
        if(mineralsList.size() == 0)
        {
            break;
        }

        if(picks[DIAMOND] != 0)
        {
            answer += mineralsList[0].size();
            picks[DIAMOND]--;
        }
        else if(picks[IRON] != 0)
        {
            int cntDia = count(mineralsList[0].begin(), mineralsList[0].end(), "diamond");
            answer += 5 * cntDia;
            answer += (mineralsList[0].size() - cntDia);
            picks[IRON]--;
        }
        else if(picks[STONE] != 0)
        {
            int cntDia = count(mineralsList[0].begin(), mineralsList[0].end(), "diamond");
            int cntIron = count(mineralsList[0].begin(), mineralsList[0].end(), "iron");
            answer += (25 * cntDia);
            answer += (5 * cntIron);
            answer += (mineralsList[0].size() - cntDia - cntIron);
            picks[STONE]--;
        }

        mineralsList.erase(mineralsList.begin());
    }

    return answer;
}

int main ()
{
    vector<int> pick;
    pick.emplace_back(1);
    pick.emplace_back(1);
    pick.emplace_back(1);

    vector<string> mineral;
    mineral.emplace_back("diamond");
    mineral.emplace_back("diamond");
    mineral.emplace_back("diamond");
    mineral.emplace_back("diamond");
    mineral.emplace_back("diamond");
    mineral.emplace_back("iron");
    mineral.emplace_back("iron");
    mineral.emplace_back("iron");
    mineral.emplace_back("iron");
    mineral.emplace_back("iron");
    mineral.emplace_back("diamond");
    mineral.emplace_back("diamond");
    mineral.emplace_back("diamond");
    mineral.emplace_back("diamond");
    mineral.emplace_back("diamond");

    int answer = solution(pick, mineral);

    cout << answer << endl;

    return 0;
}