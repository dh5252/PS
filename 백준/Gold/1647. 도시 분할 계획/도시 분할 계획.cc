#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

struct cmp
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second > b.second;
	}
};

vector<pair<int, int> > node[100001];
int visit[100001];
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;



int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N, M;
	

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;
		node[A].push_back({ B, C });
		node[B].push_back({ A, C });
	}

	int max_wei = 0;
	int sum = 0;
	int cnt = 0;
	
	pq.push({ 1, 0 });
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();
		pq.pop();

		if (visit[cur.first])
			continue;
		max_wei = max(max_wei, cur.second);
		sum += cur.second;
		visit[cur.first] = 1;
		++cnt;
		if (cnt == N)
			break;
		for (int i = 0; i < node[cur.first].size(); ++i)
			pq.push(node[cur.first][i]);
		
	}
	cout << sum - max_wei;
	return 0;
}