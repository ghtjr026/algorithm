/**************************
문제의 핵심
1. 투 포인터 알고리즘을 사용할 것
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &sequence, int k)
{
    vector<int> answer;
    int minLeft = 0;
    int minRight = 0;
    int minLength = 1000001;
    int sum = 0;

    for(int l = 0, r = 0;;)
    {
        if(sum > k)
        {
            sum -= sequence[l++];
        }
        else if(r >= sequence.size())
        {
            break;
        }
        else if(sum <= k)
        {
            sum += sequence[r++];
        }

        if(sum == k)
        {
            if(r - l < minLength)
            {
                minLeft = l;
                minRight = r - 1;             
                minLength = r - l;
            }
        }
    }

    answer.push_back(minLeft);
    answer.push_back(minRight);

    return answer;
}

int main()
{
    vector<int> sequence;
    int k = 0;
    int num = 0;

    while(true)
    {
        cin >> num;
        if(num == -1)
        {
            break;
        }
        sequence.push_back(num);
    }

    cin >> k;

    vector<int> answer = solution(sequence, k);
    for(int i = 0;i< answer.size(); i++)
    {
        cout << answer[i];
    }
    cout << endl;

    return 0;
}