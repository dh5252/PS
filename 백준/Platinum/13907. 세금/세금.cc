#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

#define INF 9876543210

typedef struct edge
{
    int ver;
    int wei;
    int c;
}   edge;

bool operator<(const edge& a, const edge& b)
{
    return a.wei > b.wei;
}


vector<edge> nd[1001];
int cnt[1001][1001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    int S, D; cin >> S >> D;

    for (int i = 0; i < M; ++i)
    {
        int a, b, w; cin >> a >> b >> w;
        nd[a].push_back({ b, w });
        nd[b].push_back({ a, w });
    }

    priority_queue<edge> pq;

    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= N; ++j)
            cnt[i][j] = INF;
        
    cnt[S][0] = 0;
    pq.push({ S, 0, 0 });
    while (!pq.empty())
    {
        edge cur = pq.top();
        pq.pop();

        if (cur.c >= N) continue;
        if (cnt[cur.ver][cur.c] < cur.wei) continue;

        for (int i = 0; i < nd[cur.ver].size(); ++i)
        {
            if (cnt[nd[cur.ver][i].ver][cur.c + 1] > cur.wei + nd[cur.ver][i].wei)
            {
                cnt[nd[cur.ver][i].ver][cur.c + 1] = cur.wei + nd[cur.ver][i].wei;
                pq.push({ nd[cur.ver][i].ver, cnt[nd[cur.ver][i].ver][cur.c + 1], cur.c + 1 });
            }
        }
    }

    for (int i = 0; i <= K; ++i)
    {
        int tax;
        if (i == 0) tax = 0;
        else cin >> tax;

        int min_value = INF;

        for (int j = 0; j < N; ++j)
            if (cnt[D][j] != INF)
            {
                cnt[D][j] += j * tax;
                min_value = min(cnt[D][j], min_value);
            }

        cout << min_value << "\n";
    }
}