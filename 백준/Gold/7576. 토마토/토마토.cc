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

typedef struct node
{
    int x, y, level;
}   node;

int m[1001][1001];
queue<node> que;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int M, N; cin >> M >> N;

    for (int i = 0 ; i < N ; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> m[i][j];
            if (m[i][j] == 1) que.push({ i, j, 0 });
        }
    node cur = { 0,0,0 };
    while (!que.empty())
    {
        cur = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = dx[i] + cur.x;
            int ny = dy[i] + cur.y;
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && m[nx][ny] == 0)
            {
                m[nx][ny] = 1;
                que.push({ nx,ny,cur.level + 1 });
            }
        }
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (m[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
    cout << cur.level;
}

