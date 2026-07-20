#include <vector>
#include <numeric>

using namespace std;

int solution(vector<vector<int>> signals) {
    long long totalCycle = 1;

    // 모든 신호등 상태가 처음으로 반복되는 전체 주기 계산
    for (const auto& signal : signals) {
        int green = signal[0];
        int yellow = signal[1];
        int red = signal[2];

        int cycle = green + yellow + red;
        totalCycle = lcm(totalCycle, static_cast<long long>(cycle));
    }

    // 전체 상태가 한 번 반복될 때까지만 확인
    for (long long time = 1; time <= totalCycle; ++time) {
        bool allYellow = true;

        for (const auto& signal : signals) {
            int green = signal[0];
            int yellow = signal[1];
            int red = signal[2];

            int cycle = green + yellow + red;
            int current = static_cast<int>((time - 1) % cycle);

            // 현재 신호등이 노란불이 아닌 경우
            if (current < green || current >= green + yellow) {
                allYellow = false;
                break;
            }
        }

        if (allYellow) {
            return static_cast<int>(time);
        }
    }

    return -1;
}