#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <queue>

#define ABS(x) ( ((x)<0)?-(x):(x) ) 
#define INF 2000000000

using namespace std;

typedef struct nd
{
    int con;
    int wei;
}   nd;

bool operator<(const nd& a, const nd& b)
{
    return a.wei > b.wei;
}

vector<nd> node[1000001];
int cnt[1000001];
int dist[1000001];
int before[1000001];

int find_first(int index)
{
    if (cnt[index]) return index;
    return before[index] = find_first(before[index]);
}



int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, M, K; cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i)
        cin >> cnt[i];
    for (int i = 0; i < M; ++i)
    {
        int s, e, v; cin >> s >> e >> v;
        if (s == e) continue;
        node[s].push_back({ e, v });
        node[e].push_back({ s, v });
    }
    for (int i = 1; i <= N; ++i)
        dist[i] = INF;
    memset(before, -1, sizeof(before));
    dist[1] = 0;
    before[1] = 0;
    priority_queue<nd> pq;
    pq.push({ 1, 0 });
    while (!pq.empty())
    {
        nd cur = pq.top();
        pq.pop();
        if (dist[cur.con] < cur.wei) continue;
        for (int i = 0; i < node[cur.con].size(); ++i)
        {
            if (dist[cur.con] + node[cur.con][i].wei < dist[node[cur.con][i].con])
            {
                dist[node[cur.con][i].con] = dist[cur.con] + node[cur.con][i].wei;
                before[node[cur.con][i].con] = cur.con;
                pq.push({ node[cur.con][i].con, dist[node[cur.con][i].con] });
            }
            else if (dist[cur.con] + node[cur.con][i].wei == dist[node[cur.con][i].con])
            {
                if (before[node[cur.con][i].con] < cur.con)
                    before[node[cur.con][i].con] = cur.con;
            }
        }
    }
    cnt[0] = 1;
    for (int i = 0; i < K; ++i)
    {
        int start; cin >> start;
        if (before[start] != -1)
        {
            int find = find_first(start);
            if (!find)
                cout << -1 << "\n";
            else
            {
                --cnt[find];
                cout << find << "\n";
            }
        }
        else cout << -1 << "\n";
    }
}