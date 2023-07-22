#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <limits.h>
#include <list>
#include <stack>

#define ABS(x) ( ((x)<0)?-(x):(x) )
#define INF 987654321

using namespace std;

typedef struct edge
{
    int ver,wei;
}   edge;

bool operator<(const edge &a, const edge &b)
{
    return a.wei < b.wei;
}

vector<edge> nd[201];
int min_dist[201][201];
int max_dist[201][201];
vector<pair<pair<int, int>, int> > max_dist_list;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, M; cin >> N >> M;

    for (int i = 1 ; i <= N ; ++i)
        for (int j = 1 ; j <= N ; ++j)
            min_dist[i][j] = INF;


    for (int i = 0 ; i < M ; ++i)
    {
        int c1, c2, l; cin >> c1 >> c2 >> l;
        if (min_dist[c1][c2] > l)
        {
            min_dist[c1][c2] = l;
            min_dist[c2][c1] = l;
        }
        if (max_dist[c1][c2] < l)
        {
            max_dist[c1][c2] = l;
            max_dist[c2][c1] = l;
        }
    }
    for (int i = 1 ; i <= N ; ++i)
        for (int j = 1 ; j <= N ; ++j)
        {
            if (min_dist[i][j] != INF)
            {
                nd[i].push_back({j, min_dist[i][j]});
                nd[j].push_back({i, min_dist[i][j]});
                min_dist[j][i] = INF;
            }
            if (max_dist[i][j] != 0)
            {
                max_dist_list.push_back({{i, j}, max_dist[i][j]});
                max_dist[j][i] = 0;
            }
        }
    double last_t = 987654;
    for (int i = 1 ; i <= N ; ++i)
    {
        int dist[201];
        priority_queue<edge> pq;
        for (int j = 1 ; j <= N ; ++j)
            dist[j] = INF;
        dist[i] = 0;
        pq.push({i, 0});
        while (!pq.empty())
        {
            edge cur = pq.top();
            pq.pop();
            for (int j = 0 ; j < nd[cur.ver].size() ; ++j)
            {
                int next_dist = cur.wei + nd[cur.ver][j].wei;
                if (next_dist < dist[nd[cur.ver][j].ver])
                {
                    dist[nd[cur.ver][j].ver] = next_dist;
                    pq.push({nd[cur.ver][j].ver, next_dist});
                }
            }
        }
        double max_t = 0;
        for (int j = 0 ; j < max_dist_list.size() ; ++j)
        {
            pair<int, int> p = max_dist_list[j].first;
            double len = max_dist_list[j].second;
            double t = (len - ABS(dist[p.first] - dist[p.second])) / 2.0 + (double)max(dist[p.first], dist[p.second]);
            if (max_t < t) max_t = t;
        }
        if (max_t < last_t) {
            last_t = max_t;
        }
    }
    cout.precision(1);
    cout << fixed;
    cout << last_t;
}