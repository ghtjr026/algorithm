#include <algorithm>

using namespace std;

using int64 = long long;

// x의 이진수에서 1의 개수를 계산한다.
int64 bitCount(int64 x)
{
    int64 count = 0;

    while (x > 0)
    {
        x &= (x - 1);
        count++;
    }

    return count;
}

// 자식 노드가 2개인 분배 노드의 층이 twoLevels개 있을 때, 마지막에 y개의 노드를 만들기 위해 필요한 2분배 노드의 최소 개수
int64 minBinaryNodes(int twoLevels, int64 y)
{
    if (y == 0)
    {
        return 0;
    }

    const int64 x = y - 1;

    // ceil(y / 2) + ceil(y / 4) + ... + ceil(y / 2^twoLevels)
    return x - bitCount(x) + twoLevels;
}

int solution(int dist_limit, int split_limit)
{
    const int64 distLimit = dist_limit;
    const int64 splitLimit = split_limit;

    // 처음에는 루트의 자식 하나가 리프이다.
    int64 answer = 1;

    // 2^twoLevels
    int64 pow2 = 1;

    for (int twoLevels = 0; pow2 <= splitLimit; twoLevels++, pow2 *= 2) {
        // 2분배 층을 완전히 구성했을 때의
        // 최대 2분배 노드 수
        const int64 maxBinaryNodes = pow2 - 1;

        // 3분배 층을 사용하지 않는 경우
        answer = max(answer, 1 + min(distLimit, maxBinaryNodes));

        // 3^threeLevels
        int64 pow3 = 3;

        // 1 + 3 + ... + 3^(threeLevels - 1)
        int64 ternarySeries = 1;

        for (int threeLevels = 1; pow2 * pow3 <= splitLimit; threeLevels++, pow3 *= 3, ternarySeries = ternarySeries * 3 + 1) {
            // 첫 번째 3분배 층에서 사용할 수 있는
            // 최대 노드 수
            const int64 maxFirstTernaryNodes = pow2;

            /*
             * minBinaryNodes(twoLevels, y)
             * + ternarySeries * y
             * <= distLimit
             *
             * 위 조건을 만족하는 가장 큰 y를 찾는다.
             */
            int64 left = 0;
            int64 right = maxFirstTernaryNodes;

            while (left < right)
            {
                const int64 mid = (left + right + 1) / 2;

                const int64 binaryNodes = minBinaryNodes(twoLevels, mid);

                const int64 requiredNodes = binaryNodes + (ternarySeries * mid);

                if (requiredNodes <= distLimit)
                {
                    left = mid;
                }
                else
                {
                    right = mid - 1;
                }
            }

            /*
             * 최적값은 경계의 양쪽 중 하나이다.
             *
             * left:
             * 모든 3분배 층을 채울 수 있는 가장 큰 y
             *
             * left + 1:
             * 모든 3분배 층을 채울 수 없는 첫 번째 y
             */
            const int64 candidates[2] = {
                left,
                left + 1
            };

            for (int index = 0; index < 2; index++) {
                const int64 y = candidates[index];

                if (y < 1 || y > maxFirstTernaryNodes) {
                    continue;
                }

                const int64 minBinary = minBinaryNodes(twoLevels, y);

                /*
                 * 첫 번째 3분배 층에 y개의
                 * 분배 노드를 배치할 수 있어야 한다.
                 */
                if (minBinary + y > distLimit) {
                    continue;
                }

                const int64 remainingAfterBinary = distLimit - minBinary;

                // 사용할 수 있는 3분배 노드 수
                const int64 ternaryNodes = min(ternarySeries * y, remainingAfterBinary);

                // 3분배 노드를 배치한 후의 남은 예산
                const int64 remaining = distLimit - minBinary - ternaryNodes;

                /*
                 * 남은 예산으로 추가할 수 있는
                 * 2분배 노드 수
                 */
                const int64 extraBinaryNodes = min(maxBinaryNodes - minBinary, remaining);

                const int64 binaryNodes =minBinary + extraBinaryNodes;

                /*
                 * 시작 리프 1개
                 * 2분배 노드 하나당 리프 +1
                 * 3분배 노드 하나당 리프 +2
                 */
                const int64 leafCount = 1 + binaryNodes + 2 * ternaryNodes;

                answer = max(answer, leafCount);
            }
        }
    }

    return static_cast<int>(answer);
}