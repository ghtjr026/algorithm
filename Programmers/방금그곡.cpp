/**************************
문제의 핵심 ( 2018 kakao blind recruitment )
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

int strToInt(string time)
{
    int result;
    stringstream ss(time);
    string temp;

    getline(ss, temp, ':');
    result = stoi(temp) * 60;
    
    getline(ss, temp, ':');
    result += stoi(temp);

    return result;
}

void getSheet(string &sheet, int playTime)
{
    while(playTime > sheet.length() - count(sheet.begin(), sheet.end(), '#'))
    {
        sheet += sheet;
    }

    while(playTime != sheet.length() - count(sheet.begin(), sheet.end(), '#'))
    {
        if(sheet.back() == '#')
        {
            sheet.pop_back();
        }
        sheet.pop_back();
    }
}

void getInfo(string music, string &title, string &sheet, int &playTime)
{
    stringstream ss(music);
    string temp;
    int cnt = 0;
    while(getline(ss, temp, ','))
    {
        switch (cnt++)
        {
        case 0:
            playTime = strToInt(temp);
            break;
        case 1:
            playTime = abs(playTime - strToInt(temp));
            break;
        case 2:
            title = temp;
            break;
        case 3:
            getSheet(temp, playTime);
            sheet = temp;
            break;
        default:
            break;
        }
    }
}

bool isSameMelody(string sheet, string m)
{
    bool isSameMelody = false;
    int sheetSize = sheet.length();
    int mSize = m.length();
    int maxIdx = sheetSize - mSize;
    if (maxIdx < 0)
    {
        return isSameMelody;
    }
    else
    {
        for (int idx = 0; idx < sheetSize; idx++)
        {
            if(idx + mSize > sheetSize)
            {
                break;
            }

            if (sheet[idx] == m[0])
            {
                string temp;
                if (m.back() != '#')
                {
                    if (sheetSize <= idx + mSize)
                    {
                        temp = sheet.substr(idx, mSize);
                    }
                    else
                    {
                        temp = sheet.substr(idx, mSize + 1);
                        if (temp.back() != '#')
                        {
                            temp.pop_back();
                        }
                    }
                }
                else
                {
                    temp = sheet.substr(idx, mSize);
                }

                if(temp == m)
                {
                    isSameMelody = true;
                    break;
                }
            }
        }
    }
    
    return isSameMelody;
}

string solution(string m, vector<string> musicinfos)
{
    pair<int, string> answer = make_pair(0, "(None)");

    for(string &str : musicinfos)
    {
        int playtime = 0;
        string title;
        string sheet;
        getInfo(str, title, sheet, playtime);

        if(isSameMelody(sheet, m))
        {
            if(answer.first < playtime)
            {
                answer = make_pair(playtime, title);
            }
        }
    }

    return answer.second;
}

int main()
{
    string sheet = "CC#BCC#BCC#BCC#B";
    vector<string> musicinfo;
    musicinfo.emplace_back("03:00,03:30,FOO,CC#B");
    musicinfo.emplace_back("04:00,04:08,BAR,CC#BCC#BCC#B");

    string result = solution(sheet, musicinfo);

    cout << result;

    return 0;
}