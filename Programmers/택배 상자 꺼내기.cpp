#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;

    vector<vector<int>> area;

    int floor = n / w;
    if (n % w != 0) {
        floor++;
    }

    vector<int> boxs;
    for (int idx = 1; idx <= floor*w; idx++) {
        if (idx > n) {
            boxs.emplace_back(-1);
        }
        else {
            boxs.emplace_back(idx);
        }


        if (idx % w == 0) {
            if ((area.size() == 0) || (area.size() % 2 == 0)) {
            }
            else {
                reverse(boxs.begin(), boxs.end());
            }
            area.emplace_back(boxs);
            boxs.clear();
        }
    }

    int cur_floor = (num - 1) / w;

    auto it = find(area.at(cur_floor).begin(), area.at(cur_floor).end(), num);
    int index = distance(area.at(cur_floor).begin(), it);

    for (int idx = cur_floor; idx < floor; idx++)
    {
        if (area.at(idx).at(index) != -1) {
            answer++;
        }
    }
    return answer;
}