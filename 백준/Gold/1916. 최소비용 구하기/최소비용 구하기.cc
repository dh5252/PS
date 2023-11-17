#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct node
{
	int ver;
	ll wei;
}	node;

bool operator<(const node &a, const node &b)
{
	return a.wei > b.wei;
}



vector<node> nd[1001];
int N, M;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0 ; i < M ; ++i)
	{
		int s,e,v; cin >> s>>e>>v;
		nd[s].push_back({e, v});
	}
	int s, e; cin >>s>>e;
	ll dist[1001];
	for (int i = 1 ; i <= N ; ++i)
		dist[i] = LLONG_MAX;
	dist[s] = 0;
	priority_queue<node> pq;
	pq.push({s, 0});
	while (!pq.empty())
	{
		node cur = pq.top();
		pq.pop();

		if (cur.wei > dist[cur.ver]) continue;

		for (int i = 0 ; i < nd[cur.ver].size() ;++i)
		{
			int next_ver = nd[cur.ver][i].ver;
			if (dist[next_ver] > cur.wei + nd[cur.ver][i].wei)
			{
				dist[next_ver] = cur.wei + nd[cur.ver][i].wei;
				pq.push({next_ver, dist[next_ver]});
			}
		}
	}
	cout << dist[e];
}