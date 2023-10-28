#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

typedef struct move
{
	bool wall;
	int val;
	pair<int, int> coordi;
}	mv;

queue<mv> que;
char m[1001][1001];
bool v[1001][1001][2];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;

	int N, M; cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			cin >> m[i][j];
	
	que.push({1, 1, {0, 0}});
	while (!que.empty())
	{
		mv cur = que.front();
		que.pop();

		//cout << "check "  << cur.coordi.first << " " <<cur.coordi.second << "\n";

		if (cur.coordi.first == N - 1 && cur.coordi.second == M - 1)
		{
			ans = cur.val;
			break;
		}

		for (int i = 0 ; i < 4 ; i++)
		{
			int rx = dx[i] + cur.coordi.first;
			int ry = dy[i] + cur.coordi.second;
			if (rx >= 0 && rx < N && ry >= 0 && ry < M)
			{
				if (m[rx][ry] == '0' && cur.wall && !v[rx][ry][0])
				{
					v[rx][ry][0] = 1;
					que.push({1, cur.val + 1, {rx, ry}});
				}
				else if (m[rx][ry] == '0' && !cur.wall && !v[rx][ry][1])
				{
					v[rx][ry][1] = 1;
					que.push({0, cur.val + 1, {rx, ry}});
				}
				else if (m[rx][ry] == '1' && cur.wall && !v[rx][ry][1])
				{
					v[rx][ry][1] = 1;
					que.push({0, cur.val + 1, {rx, ry}});
				}
			}
		}
	}
	cout << ans;
}