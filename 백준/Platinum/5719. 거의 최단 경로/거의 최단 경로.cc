#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <set>

#define ABS(x) ( ((x)<0)?-(x):(x) )
#define INF 2100000000

using namespace std;

typedef struct edge
{
    int ver;
    int wei;
}   edge;

typedef struct node
{
    vector<edge> con;
}    node;

node nd[501];

bool operator<(const edge& a, const edge& b)
{
    return a.wei > b.wei;
}

vector<int> before[501];
vector<int> non_valid[501];
bool visit[501][501];

void del_path(int cur)
{
    for (int i = 0; i < before[cur].size(); ++i)
    {
        if (visit[before[cur][i]][cur]) continue;
        visit[before[cur][i]][cur] = 1;
        non_valid[before[cur][i]].push_back(cur);
        del_path(before[cur][i]);
    }
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
    while (1)
    {
        int N, M;
        cin >> N >> M;

        if (N == 0 && M == 0)
            break;

        int S, D; cin >> S >> D;

        memset(nd, 0, sizeof(nd));

        for (int i = 0; i < M; ++i)
        {
            int U, V, P; cin >> U >> V >> P;
            nd[U].con.push_back({ V,P });
        }

        int dist[501];


        for (int i = 0; i < N; ++i)
            dist[i] = INF;
        
        dist[S] = 0;
        

        memset(before, 0, sizeof(before));
        memset(non_valid, 0, sizeof(non_valid));

        priority_queue<edge> pq;

        pq.push({S, 0});
        while (!pq.empty())
        {
            edge cur = pq.top();
            pq.pop();

            for (int i = 0; i < nd[cur.ver].con.size(); ++i)
            {
                if (cur.wei + nd[cur.ver].con[i].wei < dist[nd[cur.ver].con[i].ver])
                {
                    dist[nd[cur.ver].con[i].ver] = cur.wei + nd[cur.ver].con[i].wei;
                    before[nd[cur.ver].con[i].ver].clear();
                    before[nd[cur.ver].con[i].ver].push_back(cur.ver);
                    pq.push({ nd[cur.ver].con[i].ver , dist[nd[cur.ver].con[i].ver]});
                }
                else if (cur.wei + nd[cur.ver].con[i].wei == dist[nd[cur.ver].con[i].ver])
                    before[nd[cur.ver].con[i].ver].push_back(cur.ver);
            }
        }

        for (int i = 0; i < N; ++i)
            dist[i] = INF;

        dist[S] = 0;
        memset(visit, 0, sizeof(visit));

        del_path(D);

        pq.push({ S, 0 });
        while (!pq.empty())
        {
            edge cur = pq.top();
            pq.pop();

            for (int i = 0; i < nd[cur.ver].con.size(); ++i)
            {
                int flag = 0;
                for (int j = 0; j < non_valid[cur.ver].size(); ++j)
                {
                    if (non_valid[cur.ver][j] == nd[cur.ver].con[i].ver)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag) continue;
                if (cur.wei + nd[cur.ver].con[i].wei < dist[nd[cur.ver].con[i].ver])
                {
                    dist[nd[cur.ver].con[i].ver] = cur.wei + nd[cur.ver].con[i].wei;
                    pq.push({ nd[cur.ver].con[i].ver , dist[nd[cur.ver].con[i].ver] });
                }
            }
        }
        
        if (dist[D] == INF)
            cout << -1 << "\n";
        else cout << dist[D] << "\n";
    }
    
    return 0;
}