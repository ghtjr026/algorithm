#include <algorithm>
#include <climits>
#include <deque>
#include <vector>

using namespace std;

vector<int> solution(
    int m,
    int n,
    int h,
    int w,
    vector<vector<int>> drops
) {
    const int INF = INT_MAX;

    /*
     * desert[y][x] 대신 desert[y * n + x]로 접근한다.
     *
     * 각 칸에 비가 내리는 순서를 저장하고,
     * 비가 내리지 않는 칸은 INF로 둔다.
     */
    vector<int> desert(m * n, INF);

    for (int i = 0; i < static_cast<int>(drops.size()); ++i) {
        int y = drops[i][0];
        int x = drops[i][1];

        desert[y * n + x] = i + 1;
    }

    /*
     * 한 행에서 너비 w의 구간이 시작될 수 있는 열의 개수
     */
    const int rowMinColumnCount = n - w + 1;

    /*
     * rowMin[y][x]:
     *
     * desert의 y번째 행에서
     * x ~ x + w - 1 구간의 최솟값
     */
    vector<int> rowMin(m * rowMinColumnCount);

    /*
     * 1단계:
     * 각 행에서 너비 w인 슬라이딩 윈도우 최솟값을 구한다.
     */
    for (int y = 0; y < m; ++y) {
        deque<int> dq;

        for (int x = 0; x < n; ++x) {
            /*
             * x - w 이하의 인덱스는 현재 윈도우에서 벗어났다.
             *
             * 예:
             * w = 3, x = 4이면 현재 윈도우는 [2, 4]
             * 따라서 인덱스 1 이하는 제거한다.
             */
            while (!dq.empty() && dq.front() <= x - w) {
                dq.pop_front();
            }

            /*
             * 현재 값보다 크거나 같은 값은
             * 앞으로 최솟값이 될 수 없으므로 제거한다.
             */
            while (
                !dq.empty() &&
                desert[y * n + dq.back()] >= desert[y * n + x]
            ) {
                dq.pop_back();
            }

            dq.push_back(x);

            /*
             * x가 w - 1 이상이면 너비 w인 윈도우가 완성된다.
             */
            if (x >= w - 1) {
                int startX = x - w + 1;

                rowMin[y * rowMinColumnCount + startX] =
                    desert[y * n + dq.front()];
            }
        }
    }

    int bestRainOrder = -1;
    vector<int> answer = {0, 0};

    /*
     * 2단계:
     * rowMin의 각 열에서 높이 h인 슬라이딩 윈도우
     * 최솟값을 구한다.
     */
    for (int x = 0; x < rowMinColumnCount; ++x) {
        deque<int> dq;

        for (int y = 0; y < m; ++y) {
            /*
             * 현재 높이 h의 윈도우를 벗어난 행 제거
             */
            while (!dq.empty() && dq.front() <= y - h) {
                dq.pop_front();
            }

            /*
             * 단조 증가 상태를 유지한다.
             */
            while (
                !dq.empty() &&
                rowMin[dq.back() * rowMinColumnCount + x] >=
                    rowMin[y * rowMinColumnCount + x]
            ) {
                dq.pop_back();
            }

            dq.push_back(y);

            /*
             * 높이 h인 윈도우가 완성됐다.
             */
            if (y >= h - 1) {
                int startY = y - h + 1;

                /*
                 * 현재 h × w 영역의 최솟값
                 */
                int rainOrder =
                    rowMin[dq.front() * rowMinColumnCount + x];

                /*
                 * 더 늦게 비를 맞는 위치라면 갱신한다.
                 */
                if (rainOrder > bestRainOrder) {
                    bestRainOrder = rainOrder;
                    answer = {startY, x};
                }
                /*
                 * 비를 맞는 시점이 같다면
                 * 더 위쪽, 그다음 더 왼쪽 위치를 선택한다.
                 *
                 * 열부터 순회하고 있으므로 동률 비교가 필요하다.
                 */
                else if (rainOrder == bestRainOrder) {
                    if (
                        startY < answer[0] ||
                        (startY == answer[0] && x < answer[1])
                    ) {
                        answer = {startY, x};
                    }
                }
            }
        }
    }

    return answer;
}