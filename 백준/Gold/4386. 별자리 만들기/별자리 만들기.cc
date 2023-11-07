#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct node
{
	int ver;
	double wei;
}	node;

pair<double, double> cd[101];
vector<pair<int, double> > w[101];
bool v[101];

bool operator<(const node &a, const node &b)
{
	return a.wei > b.wei;
}

void set_w(int i, int j)
{
	w[i].push_back({j, sqrt((cd[i].first - cd[j].first) * (cd[i].first - cd[j].first) + (cd[i].second - cd[j].second) * (cd[i].second - cd[j].second))});
	w[j].push_back({i, sqrt((cd[i].first - cd[j].first) * (cd[i].first - cd[j].first) + (cd[i].second - cd[j].second) * (cd[i].second - cd[j].second))});
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> cd[i].first >> cd[i].second;
		for (int j = 0 ; j < i ; ++j)
			set_w(i, j);
	}

	
	priority_queue<node> pq;

	double ans = 0;
	pq.push({0, 0});
	while (!pq.empty())
	{
		node cur = pq.top();
		pq.pop();

		if (v[cur.ver])
			continue;

		ans += cur.wei;
		v[cur.ver] = 1;
		for (int i = 0 ; i < w[cur.ver].size() ; ++i)
		{
			if (v[w[cur.ver][i].first]) continue;
			pq.push({w[cur.ver][i].first, w[cur.ver][i].second});
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << ans;
	
}