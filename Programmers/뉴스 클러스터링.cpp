/**************************
문제의 핵심 ( 2018 kakao blind recruitment )
1. 교집합 -> set_intersection

2. 합집합 ( 중복 제거 ) -> set_union
-> 합집합 ( 중복 허용 ) -> merge

3. 유의사항
-> 두 집합은 정렬이 되어있어야 함
-> 매개변수 : (집합1.begin(), 집합1.end(), 집합2.begin(), 집합2.end(), std::back_inserter(새로운 벡터))
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

vector<string> getSet(string str)
{
    vector<string> setList;

    for(int idx = 0; idx < str.length() - 1; idx++)
    {
        char cha = (char)(tolower(str[idx]));
        if('a' <= cha && 'z' >= cha)
        {
            char cha1 = (char)(tolower(str[idx + 1]));
            if('a' <= cha1 && 'z' >= cha1)
            {
                string temp;
                temp += cha;
                temp += cha1;
                setList.emplace_back(temp);
            }
        }
    }

    return setList;
}

int solution(string str1, string str2)
{
    vector<string> setList1 = getSet(str1);
    vector<string> setList2 = getSet(str2);

    sort(setList1.begin(), setList1.end());
    sort(setList2.begin(), setList2.end());

    vector<string> intersection;
    set_intersection(setList1.begin(), setList1.end(), setList2.begin(), setList2.end(), back_inserter(intersection));
    long long intersectionCnt = intersection.size() * 65536;

    vector<string> unionList;
    set_union(setList1.begin(), setList1.end(), setList2.begin(), setList2.end(), back_inserter(unionList));
    int unionCnt = unionList.size();

    if(intersectionCnt == 0 && unionCnt == 0)
    {
        return 65536;
    }

    return intersectionCnt / unionCnt;
}

int main()
{
    string str1 = "FRANCE";
    string str2 = "french";

    int result = solution(str1, str2);

    cout << result;

    return 0;
}