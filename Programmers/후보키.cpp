/**************************
문제의 핵심 ( 2019 kakao blind recruitment )
1. 후보키의 핵심 요소 정리
-> 유일성 : 릴레이션에 있는 모든 튜플에 대해 유일하게 식별되어야 한다
-> 최소성 : 유일성을 가진 키를 구성하는 속성 중 하나라도 제외하는 경우 유일성이 깨지는 것을 의미한다.
           즉, 릴레이션의 모든 튜플을 유일하게 식별하는 데 꼭 필요한 속성들로만 구성되어야 한다

해결 방안
1. 모든 조합을 구함

2. 조합에 대한 키를 구함 ( set을 사용하여 중복을 제거 )

3. 조합의 수와 relation의 수가 동일한 keyList를 구함 ( 후보키를 구함 )
-> 이때 이미 후보키에 등록된 키가 keyList에 있는 경우는 '최소성'을 위배하므로 제외시켜야함을 유의
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void makeAllKey(vector<string> keyNum, vector<vector<string>> relation, vector<set<string>> &allKey)
{
    for (string &str : keyNum)
    {
        set<string> keys;
        for (int idx = 0; idx < relation.size(); idx++)
        {
            string key;
            for (int strIdx = 0; strIdx < str.size(); strIdx++)
            {
                int position = str[strIdx] - '0';
                key += relation[idx][position];
            }
            keys.insert(key);
        }
        allKey.emplace_back(keys);
    }
}

void getCandidateKey(vector<set<string>> allKey, vector<string> keyNum, int checkSize, vector<string> &candidateKey)
{
    int idx = -1;
    for (auto &key : allKey)
    {
        idx++;
        if (key.size() == checkSize)
        {
            bool isposible = true;
            for (auto &str : candidateKey)
            {
                int cntDuplication = 0;
                for (auto &chart : str)
                {
                    for (int keyNumIdx = 0; keyNumIdx < keyNum[idx].size(); keyNumIdx++)
                    {
                        if(chart == keyNum[idx][keyNumIdx])
                        {
                            cntDuplication++;
                            break;
                        }
                    }
                }

                if(str.size() == cntDuplication)
                {
                    isposible = false;
                    break;
                }
            }

            if(isposible)
            {
                candidateKey.emplace_back(keyNum[idx]);
            }
        }
    }
}

int solution(vector<vector<string>> relation)
{
    vector<string> keyNum;

    for (int i = 0; i < relation[0].size(); i++)
    {
        vector<bool> visited(relation[0].size() - (i + 1), false);
        visited.insert(visited.end(), i + 1, true);
        do
        {
            string temp = "";
            for (int k = 0; k < relation[0].size(); k++)
            {
                if (visited[k])
                {
                    temp += to_string(k);
                }
            }
            keyNum.emplace_back(temp);
        } while (next_permutation(visited.begin(), visited.end()));
    }

    // make all key
    vector<set<string>> allKey;
    makeAllKey(keyNum, relation, allKey);

    // check size
    vector<string> candidateKey;
    getCandidateKey(allKey, keyNum, relation.size(), candidateKey);

    if (candidateKey.size() == 0)
    {
        return 1;
    }
    return candidateKey.size();
}

int main()
{
    vector<vector<string>> relation;
    vector<string> tuple;
    tuple.emplace_back("a");
    tuple.emplace_back("1");
    tuple.emplace_back("aaa");
    tuple.emplace_back("c");
    tuple.emplace_back("ng");
    relation.emplace_back(tuple);
    tuple.clear();

    tuple.emplace_back("a");
    tuple.emplace_back("1");
    tuple.emplace_back("bbb");
    tuple.emplace_back("e");
    tuple.emplace_back("g");
    relation.emplace_back(tuple);
    tuple.clear();

    tuple.emplace_back("c");
    tuple.emplace_back("1");
    tuple.emplace_back("aaa");
    tuple.emplace_back("d");
    tuple.emplace_back("ng");
    relation.emplace_back(tuple);
    tuple.clear();

    tuple.emplace_back("d");
    tuple.emplace_back("2");
    tuple.emplace_back("bbb");
    tuple.emplace_back("d");
    tuple.emplace_back("ng");
    relation.emplace_back(tuple);
    tuple.clear();

    int result = solution(relation);

    cout << result;

    return 0;
}