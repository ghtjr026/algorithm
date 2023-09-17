/**************************
문제의 핵심 ( kakao blind Recruitment )
1. records 를 먼저 정렬하면 3-12 ( 5번 제외 )한 테스트 케이스가 실패함

2. map을 사용하면 key 값으로 오름차순 정렬됨
-> map의 key를 carNumber로 하면 됨
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>

using namespace std;

// fees
static const int TIME = 0;
static const int COST = 1;
static const int PERTIME = 2;
static const int PERCOST = 3;

typedef struct RECORD
{
    int time;
    string carNum;
    string type;
};

int TimeToMin(string time)
{
    int hour = stoi(time.substr(0, 2)) * 60;
    int min = stoi(time.substr(3, 2));

    return hour + min;
}

vector<RECORD> stringToRecord(vector<string> records)
{
    vector<RECORD> recordList;

    for (string &record : records)
    {
        stringstream ss(record);
        string temp;
        RECORD organize;
        for (int idx = 0; idx < 3; idx++)
        {
            getline(ss, temp, ' ');
            switch (idx)
            {
            case 0:
                organize.time = TimeToMin(temp);
                break;

            case 1:
                organize.carNum = temp;
                break;

            case 2:
                organize.type = temp;
                break;

            default:
                break;
            }
        }
        recordList.emplace_back(organize);
    }

    return recordList;
}

vector<int> calculateFee(map<string, int> timeList, vector<int> fees)
{
    vector<int> answer;

    for(auto &time : timeList)
    {
        int cost = fees[COST];
        int subTime = time.second - fees[TIME];

        if(0 < subTime)
        {
            if(subTime % fees[PERTIME] != 0)
            {
                subTime += fees[PERTIME];
            }
            cost += subTime / fees[PERTIME] * fees[PERCOST];
        }

        answer.emplace_back(cost);
    }

    return answer;
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    map<string, int> parkingCar;
    map<string, int> timeList;

    vector<RECORD> recordList = stringToRecord(records);

    for (int idx = 0; idx < recordList.size(); idx++)
    {
        RECORD curRecord = recordList.at(idx);

        auto parkingIter = parkingCar.find(curRecord.carNum);
        if(curRecord.type == "IN")
        {
            parkingCar.insert({curRecord.carNum, curRecord.time});
            continue;
        }

        int stayTime = curRecord.time - parkingIter->second;
        auto timeListIter = timeList.find(curRecord.carNum);
        if(timeListIter == timeList.end())
        {
            timeList.insert({curRecord.carNum, stayTime});
        }
        else
        {
            timeList[curRecord.carNum] = timeListIter->second + stayTime;
        }
        parkingCar.erase(curRecord.carNum);
    }

    for(auto &remain : parkingCar)
    {
        string lastDay("23:59");
        int stayTime = TimeToMin(lastDay) - remain.second;

        auto timeListIter = timeList.find(remain.first);
        if(timeListIter == timeList.end())
        {
            timeList.insert({remain.first, stayTime});
        }
        else
        {
            timeList[remain.first] = timeListIter->second + stayTime;
        }
    }

    return calculateFee(timeList, fees);
}

int main()
{
    vector<int> fees;
    fees.emplace_back(180);
    fees.emplace_back(5000);
    fees.emplace_back(10);
    fees.emplace_back(600);

    vector<string> records;
    records.emplace_back("05:34 5961 IN");
    records.emplace_back("06:34 5961 OUT");
    records.emplace_back("07:34 5961 IN");
    records.emplace_back("08:34 5961 OUT");
    records.emplace_back("09:34 5961 IN");
    records.emplace_back("10:34 5961 OUT");
    records.emplace_back("11:34 5961 IN");
    records.emplace_back("12:34 5961 OUT");

    vector<int> answer = solution(fees, records);

    for (int &fee : answer)
    {
        cout << fee << endl;
    }

    return 0;
}