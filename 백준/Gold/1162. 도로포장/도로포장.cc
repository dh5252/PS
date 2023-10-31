#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
	int idx;
	long long value;
	int cur_k;
} node;

bool operator<(const node &a, const node &b)
{
	return a.value > b.value;
}

long long dist[10001][21];
vector<node> nd[10001];
priority_queue<node> pq;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M, K; cin >> N >> M >> K;

	for (int i = 0 ; i < M ; ++i)
	{
		int s, e, w; cin >> s >> e >> w;
		nd[s].push_back({e, w, 0});
		nd[e].push_back({s, w, 0});
	}

	for (int i = 1 ; i <= N ; i++)
		for (int j = 0 ; j <= K ; j++)
		{
			if (i == 1) dist[i][j] = 0;
			else dist[i][j] = LLONG_MAX;
		}
	pq.push({1, 0, 0});

	while (!pq.empty())
	{
		node cur = pq.top();
		pq.pop();

		if (cur.value > dist[cur.idx][cur.cur_k])
			continue;

		for (int i = 0 ; i < nd[cur.idx].size() ; i++)
		{
			long long cur_wei = cur.value + nd[cur.idx][i].value;
			int next_nd = nd[cur.idx][i].idx;

			if (dist[next_nd][cur.cur_k] > cur_wei)
			{
				dist[next_nd][cur.cur_k] = cur_wei;
				pq.push({next_nd, cur_wei, cur.cur_k});
			}
			if (cur.cur_k + 1 <= K)
			{
				if (dist[next_nd][cur.cur_k + 1] > cur.value)
				{
					dist[next_nd][cur.cur_k + 1] = cur.value;
					pq.push({next_nd, cur.value, cur.cur_k + 1});
				}
			}
		}
	}
	long long min_value = LLONG_MAX;
	for (int i = 0 ; i <= K ; i++)
		min_value = min(min_value, dist[N][i]);
	cout << min_value;
}