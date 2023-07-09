#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>
#include <limits.h>
#include <string>

using namespace std;

bool visit[100001];
queue<pair<int, int> > que;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, K; cin >> N >> K;

    que.push({ N, 0 });
    while (!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();

        if (cur.first == K)
        {
            cout << cur.second;
            break;
        }

        if (cur.first - 1 >= 0 && !visit[cur.first - 1])
        {
            visit[cur .first- 1] = 1;
            que.push({ cur.first - 1, cur.second + 1 });
        }
        if (cur.first + 1 <= 100000 && !visit[cur.first + 1])
        {
            visit[cur.first + 1] = 1;
            que.push({ cur.first + 1, cur.second + 1 });
        }
        if (cur.first * 2 <= 100000 && !visit[cur.first << 1])
        {
            visit[cur.first << 1] = 1;
            que.push({ cur.first << 1, cur.second + 1 });
        }
    }
}

