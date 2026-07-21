#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    const int schedules_size = static_cast<int>(schedules.size());
    for (int idx = 0; idx < schedules_size; idx++) {

        int work_time = schedules.at(idx) + 10;
        if (work_time % 100 > 59) {
            work_time += 100;
            work_time -= 60;
        }

        vector<int> cur_timelog = timelogs.at(idx);

        const int cur_timelog_size = static_cast<int>(cur_timelog.size());
        bool is_success = true;
        for (int day = 0, cur_startday = startday; day < cur_timelog_size; day++, cur_startday++) {
            if (cur_startday % 7 == 6 || cur_startday % 7 == 0) {
                continue;
            }

            int day_time = cur_timelog.at(day);
            if (day_time > work_time) {
                is_success = false;
                break;
            }
        }

        if (is_success) {
            answer++;
        }
    }

    return answer;
}