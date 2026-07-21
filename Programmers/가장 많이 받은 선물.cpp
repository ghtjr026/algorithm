#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    map<string, int> names;
    int idx = 0;
    for (auto name : friends) {
        names.insert(make_pair(name, idx++));
    }

    const int names_size = static_cast<int>(names.size());
    vector<vector<int>> status(names_size, vector<int>(names_size, 0));
    vector<pair<int, int>> person(names_size);

    const int gifts_size = static_cast<int>(gifts.size());
    for(int index = 0; index < gifts_size; index++) {
        string record = gifts.at(index);
        stringstream ss(record);
        string giver;
        string receiver;

        ss >> giver;
        ss >> receiver;

        status.at(names.at(giver)).at(names.at(receiver))++;

        person.at(names.at(giver)).first++;
        person.at(names.at(receiver)).second++;
    }

    vector<int> result(names_size);
    for (int cur = 0; cur < names_size; cur++) {
        for (int next = cur; next < names_size; next++) {
            if (next == cur) {
                continue;
            }

            int cur_gift_index = status.at(cur).at(next);
            int next_gift_index = status.at(next).at(cur);

            if ((status.at(cur).at(next) == 0 && status.at(next).at(cur) == 0) || cur_gift_index == next_gift_index) {
                cur_gift_index = person.at(cur).second - person.at(cur).first;
                next_gift_index = person.at(next).second - person.at(next).first;

                if (cur_gift_index == next_gift_index) {
                    continue;
                }
                else if (cur_gift_index < next_gift_index) {
                    result.at(cur)++;
                }
                else {
                    result.at(next)++;
                }
            }
            else {
                if (cur_gift_index < next_gift_index) {
                    result.at(next)++;
                }
                else {
                    result.at(cur)++;
                }
            }
        }
    }

    for (int index = 0; index < names_size; index++) {
        answer = max(answer, result.at(index));
    }

    return answer;
}