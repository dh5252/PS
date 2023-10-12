#include <bits/stdc++.h>
using namespace std;

typedef struct con
{
	int ver,wei;
}	con;

typedef struct reverse
{
	int ver, wei;
}	rev;

bool operator<(const con &a, const con &b)
{
	return a.wei < b.wei;
}

vector<con> ver[1001];
vector<rev> rever[1001];

int dist[1001];
int rev_dist[1001];


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, X;
	cin >> N >> M >> X;
	for (int i = 0 ; i < M ; ++i)
	{
		int s,e,t; cin >> s >> e >> t;
		ver[s].push_back({e, t});
		rever[e].push_back({s, t});
	}

	for (int i = 1 ; i <= N ; ++i)
		dist[i] = INT_MAX;
	dist[X] = 0;

	priority_queue<con> pq;

	pq.push({X, 0});
	while (!pq.empty())
	{
		con cur = pq.top();
		pq.pop();

		for (int i = 0 ; i < ver[cur.ver].size() ; ++i)
		{
			int cur_dist = cur.wei + ver[cur.ver][i].wei;
			if (dist[ver[cur.ver][i].ver] > cur_dist)
			{
				dist[ver[cur.ver][i].ver] = cur_dist;
				pq.push({ver[cur.ver][i].ver, cur_dist});
			}
		}
	}

	for (int i = 1 ; i <= N ; ++i)
		rev_dist[i] = INT_MAX;
	rev_dist[X] = 0;
	
	pq = {};

	pq.push({X, 0});
	while (!pq.empty())
	{
		con cur = pq.top();
		pq.pop();

		for (int i = 0 ; i < rever[cur.ver].size() ; ++i)
		{
			int cur_dist = cur.wei + rever[cur.ver][i].wei;
			if (rev_dist[rever[cur.ver][i].ver] > cur_dist)
			{
				rev_dist[rever[cur.ver][i].ver] = cur_dist;
				pq.push({rever[cur.ver][i].ver, cur_dist});
			}
		}
	}

	int max_value = 0;
	for (int i = 1 ; i <= N ; ++i)
		max_value = max(max_value, dist[i] + rev_dist[i]);
	
	cout << max_value;
}