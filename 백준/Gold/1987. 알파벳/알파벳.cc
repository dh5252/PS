#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
#include <utility>

using namespace std;

int R, C;
int map[21][21];
int max_cnt = -1;

void dfs(int i, int j, int state, int cnt)
{
	max_cnt = max(max_cnt, cnt);
	if (i > 0 && !(state & (1 << map[i - 1][j])))
		dfs(i - 1, j, (state | (1 << map[i - 1][j])), cnt + 1);

	if (i < R - 1 && !(state & (1 << map[i + 1][j])))
		dfs(i + 1, j, (state | (1 << map[i + 1][j])), cnt + 1);

	if (j > 0 && !(state & (1 << map[i][j - 1])))
		dfs(i, j - 1, (state | (1 << map[i][j - 1])), cnt + 1);
	
	if (j < C - 1 && !(state & (1 << map[i][j + 1])))
		dfs(i, j + 1, (state | (1 << map[i][j + 1])), cnt + 1);
	
}

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	cin >> R >> C;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			char input;
			cin >> input;
			map[i][j] = input - 'A';
		}
	}
	dfs(0, 0, 1 << map[0][0], 1);
	cout << max_cnt;
	return 0;
}