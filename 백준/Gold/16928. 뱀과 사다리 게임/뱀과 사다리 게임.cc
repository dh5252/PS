#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <set>

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;

typedef struct node
{
    int num;
    int level;
};

queue<node> que;
int map[107];
int jump[101];
int visit[101];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        jump[x] = y;
    }
    for (int i = 0; i < M; ++i)
    {
        int x, y;
        cin >> x >> y;
        jump[x] = y;
    }

    que.push({ 1, 0 });
    while (!que.empty())
    {
        node cur = que.front();
        que.pop();

        if (jump[cur.num])
            cur.num = jump[cur.num];

        if (cur.num == 100)
        {
            cout << cur.level;
            return 0;
        }

        for (int i = 1; i <= 6; ++i)
            if (cur.num + i <= 100 && !visit[cur.num + i])
            {
                que.push({ cur.num + i, cur.level + 1 });
                visit[cur.num + i] = 1;
            }
    }
    return 0;
}