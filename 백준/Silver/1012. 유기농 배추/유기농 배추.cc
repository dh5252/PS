#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>
#include <limits.h>
#include <string>

using namespace std;

bool m[51][51];
bool visit[51][51];
int M, N;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int i, int j)
{
    visit[i][j] = 1;
    for (int k = 0; k < 4; ++k)
    {
        int x = dx[k] + i;
        int y = dy[k] + j;
        if (x >= 0 && y >= 0 && x < M && y < N && m[x][y] && !visit[x][y])
            dfs(x, y);
    }
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int T; cin >> T;

    for (int t = 0; t < T; ++t)
    {
        memset(m, 0, sizeof(m));
        memset(visit, 0, sizeof(visit));
        cin >> M >> N;
        int K; cin >> K;
        while (K--)
        {
            int x, y; cin >> x >> y;
            m[x][y] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                if (m[i][j] && !visit[i][j])
                {
                    dfs(i, j);
                    ++cnt;
                }
        cout << cnt << "\n";
    }
}

