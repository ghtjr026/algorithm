#include <string>
#include <vector>
#include <climits>

using namespace std;

void calculate(int stage, vector<int>& hint_cnt, vector<vector<int>>& cost, vector<vector<int>>& hint, int result, int& answer) {
    const int cost_size = static_cast<int>(cost.size());
    
    if (hint_cnt.at(stage) >= cost.at(stage).size()) {
        result += cost.at(stage).back();
    }
    else {
        result += cost.at(stage).at(hint_cnt.at(stage));
    }

    if (stage == cost_size - 1) {
        answer = min(answer, result);
        return;
    }

    // 힌트 권 구매안함
    calculate(stage + 1, hint_cnt, cost, hint, result, answer);

    // 힌트 권 구매함
    result += hint.at(stage).front();
    const int hint_size = static_cast<int>(hint.at(stage).size());
    for (int idx = 1; idx < hint_size; idx++) {
        hint_cnt.at(hint.at(stage).at(idx) - 1)++;
    }

    calculate(stage + 1, hint_cnt, cost, hint, result, answer);

    for (int idx = 1; idx < hint_size; idx++) {
        hint_cnt.at(hint.at(stage).at(idx) - 1)--;
    }
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    int answer = INT_MAX;

    const int cost_size = static_cast<int>(cost.size());
    vector<int> hint_cnt(cost_size, 0);

    calculate(0, hint_cnt, cost, hint, 0, answer);

    return answer;
}