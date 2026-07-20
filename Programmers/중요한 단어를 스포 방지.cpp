#include <bits/stdc++.h>
using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int messageLength = message.size();
    int spoilerCount = spoiler_ranges.size();

    // 각 문자가 몇 번째 스포 구간에 포함되는지 저장
    // -1이면 스포 구간이 아닌 문자
    vector<int> spoilerIndex(messageLength, -1);

    for (int i = 0; i < spoilerCount; ++i) {
        int start = spoiler_ranges[i][0];
        int end = spoiler_ranges[i][1];

        for (int position = start; position <= end; ++position) {
            spoilerIndex[position] = max(spoilerIndex[position], i);
        }
    }

    // 스포 구간에 포함되지 않은 일반 단어
    unordered_set<string> normalWords;

    // revealedWords[i]:
    // i번째 스포 구간을 클릭할 때 완전히 공개되는 단어
    vector<vector<string>> revealedWords(spoilerCount);

    stringstream ss(message);
    string word;

    int cursor = 0;

    while (ss >> word) {
        // 공백을 건너뛰어 현재 단어의 시작 위치를 찾는다.
        while (cursor < messageLength && message[cursor] == ' ') {
            ++cursor;
        }

        int wordStart = cursor;
        int wordEnd = wordStart + word.size() - 1;

        // 이 단어가 완전히 공개되는 시점
        int revealIndex = -1;

        for (int position = wordStart; position <= wordEnd; ++position) {
            revealIndex = max(revealIndex, spoilerIndex[position]);
        }

        if (revealIndex == -1) {
            // 어떤 스포 구간에도 포함되지 않은 단어
            normalWords.insert(word);
        } else {
            // 마지막으로 관련된 스포 구간을 클릭할 때 공개된다.
            revealedWords[revealIndex].push_back(word);
        }

        cursor = wordEnd + 1;
    }

    // 지금까지 공개된 스포 단어
    unordered_set<string> previousSpoilerWords;

    int answer = 0;

    for (int i = 0; i < spoilerCount; ++i) {
        for (const string& currentWord : revealedWords[i]) {
            bool existsInNormalArea =
                normalWords.find(currentWord) != normalWords.end();

            bool alreadyRevealed =
                previousSpoilerWords.find(currentWord) !=
                previousSpoilerWords.end();

            if (!existsInNormalArea && !alreadyRevealed) {
                ++answer;
            }

            // 중요한 단어인지와 관계없이,
            // 이미 공개된 스포 단어로 기록해야 한다.
            previousSpoilerWords.insert(currentWord);
        }
    }

    return answer;
}