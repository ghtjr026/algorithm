/**************************
문제의 핵심
1. 유의사항 없음
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    for(int idx = 0; idx < phone_book.size() - 1; idx++)
    {
        if(phone_book[idx] == phone_book[idx + 1].substr(0, phone_book[idx].size()))
        {
            answer = false;
            break;
        }
    }

    // vector<vector<string>> sortedNum(10);

    // for(string &str : phone_book)
    // {
    //     sortedNum[str[0] - '0'].emplace_back(str);
    // }

    // for(vector<string> strlist : sortedNum)
    // {
    //     if(!answer)
    //     {
    //         break;
    //     }

    //     if(!strlist.empty())
    //     {
    //         if(strlist.size() == 1)
    //         {
    //             continue;
    //         }
    //         sort(strlist.begin(), strlist.end());
    //         for(int idx = 0; idx < strlist.size(); idx++)
    //         {
    //             if(!answer)
    //             {
    //                 break;
    //             }
                
    //             string standard = strlist.at(idx);
    //             for(int cmp = idx + 1; cmp < strlist.size(); cmp++)
    //             {
    //                 if(strlist.at(cmp).find(standard) == 0)
    //                 {
    //                     answer = false;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    // }

    return answer;
}

int main()
{
    vector<string> phone_book;

    for(int idx = 0; idx < 1000000; idx++)
    {
        phone_book.emplace_back(to_string(idx));
    }

    long startTime = (long)clock();
    bool result = solution(phone_book);
    long endTime = (long)clock();

    cout << endTime - startTime << endl;

    cout << result;

    return 0;
}