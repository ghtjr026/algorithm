/**************************
문제의 핵심
1. 완전탐색으로 풀 수 있음

다른 풀이 ( 수학적 풀이 )
1. A, AA, AAA, AAAA, AAAAA 순으로 계산됨

2. 각 자리에 필요한 연산 횟수 = count 

3. 알파벳 list의 인덱스 = alpha
-> A가 0인 이유는 A가 기본이기 때문

4. 각 자리에 필요한 연산 횟수 * 알파벳 list의 인덱스

e.g)
A -> 1
AA -> 6
AAA -> 31
AAAA -> 156
AAAAA -> 781

E -> 781 + 1 -> A의 모든 경우의 수 + 1
I -> 781 + 781 + 1 -> A의 모든 경우의 수 + E의 모든 경우의 수 + 1

EA -> 781 + 2 -> A의 모든 경우의 수 + 2
EE -> 781 + 156 + 2 -> A의 모든 경우의 수 + A가 4번째 자리일 때의 모든 경우의 수 + 2
EI -> 781 + 156 + 156 + 2 -> A의 모든 경우의 수 + A가 4번째 자리일 때의 모든 경우의 수 + E가 4번째 자리일 때의 모든 경우의 수 + 2
**************************/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string word)
{
    int answer = 0;

    map<char, int> alpha;
    alpha.insert(make_pair('A', 0));
    alpha.insert(make_pair('E', 1));
    alpha.insert(make_pair('I', 2));
    alpha.insert(make_pair('O', 3));
    alpha.insert(make_pair('U', 4));

    int count[5] = {781, 156, 31, 6, 1};

    for(int i = 0; i < word.length(); i++)
    {
        answer += alpha[word[i]] * count[i];
    }
    answer += word.length();

    return answer;
}

int main()
{
    cout << solution("EI");

    return 0;
}