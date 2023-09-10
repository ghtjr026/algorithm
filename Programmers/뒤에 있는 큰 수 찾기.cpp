/**************************
문제의 핵심
1. 단순 2중 for문으로 푼다면 시간초과가 남

2. answer이 -1인 경우, 그 뒤부터는 큰 숫자가 없다는 것을 의미

3. 역으로 돌리면서 수를 비교
3-1. 현재 수가 다음 수보다 작으면 다음 수를 answer에 넣음
3-2. 현재 수가 다음 수보다 크면 answer과 비교, 만약 answer이 -1이면 -1로 갱신
3-3. 현재 수가 다음 수보다 크면 answer과 비교, 만약 answer이 더 크면 answer로 갱신
**************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer(numbers.size(), -1);

    int maxNumIdx = numbers.size() - 1;
    for(int idx = numbers.size() - 2; idx < numbers.size(); idx--)
    {
        for(int comIdx = idx + 1; comIdx <= maxNumIdx; comIdx++)
        {
            if(numbers[idx] < numbers[comIdx])
            {
                answer[idx] = numbers[comIdx];
                break;
            }
            else
            {
                if(answer[comIdx] == -1)
                {
                    maxNumIdx = comIdx;
                    break;
                }
                else if(numbers[idx] < answer[comIdx])
                {
                    answer[idx] = answer[comIdx];
                    break;
                }
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> numbers;
    
    //get numbers

    vector<int> backBigNum = solution(numbers);

    for(int idx = 0; idx < backBigNum.size(); idx++)
    {
        cout << backBigNum[idx] << " ";
    }
    cout << endl;

    return 0;
}