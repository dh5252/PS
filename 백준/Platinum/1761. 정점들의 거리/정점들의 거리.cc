#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;

typedef struct node
{
    vector<pair<int, int> > child;
}node;

int dp[40001][20];
int wei[40001];
int visit[40001];
int depth[40001];


node nd[40001];

int LCA(int a, int b)
{
    if (depth[a] > depth[b])
    {
        while (depth[a] != depth[b])
        {
            for (int i = 0; i < 18; ++i)
            {
                if (depth[dp[a][i]] < depth[b])
                {
                    a = dp[a][i - 1];
                    break;
                }
                else if (depth[dp[a][i]] == depth[b])
                {
                    a = dp[a][i];
                    break;
                }
            }
        }
    }
    else if (depth[b] > depth[a])
    {
        while (depth[b] != depth[a])
        {
            for (int i = 0; i < 18; ++i)
            {
                if (depth[dp[b][i]] < depth[a])
                {
                    b = dp[b][i - 1];
                    break;
                }
                else if (depth[dp[b][i]] == depth[a])
                {
                    b = dp[b][i];
                    break;
                }
            }
        }
    }
    if (a == b)
        return a;

    while (dp[a][0] != dp[b][0])
    {
        for (int i = 0; i < 18; ++i)
        {
            if (dp[a][i] == dp[b][i])
            {
                a = dp[a][i - 1];
                b = dp[b][i - 1];
                break;
            }
        }
    }
    return dp[a][0];
}

void dfs(int cur, int dep, int w)
{
    visit[cur] = 1;
    depth[cur] = dep;
    wei[cur] = w;
    for (int i = 0; i < nd[cur].child.size(); ++i)
        if (!visit[nd[cur].child[i].first])
        {
            dp[nd[cur].child[i].first][0] = cur;
            dfs(nd[cur].child[i].first, dep + 1, w + nd[cur].child[i].second);
        }
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;

    cin >> N;

    for (int i = 0; i < N - 1; ++i)
    {
        int f, s, w;
        cin >> f >> s >> w;
        nd[f].child.push_back({ s, w });
        nd[s].child.push_back({ f, w });
    }
    dp[1][0] = 0;
    dp[0][0] = 0;
    dfs(1, 0, 0);

    for (int i = 1; i < 18; ++i) 
        for (int j = 1; j <= N; ++j)
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
                               
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int n1, n2;
        cin >> n1 >> n2;
        int com = LCA(n1, n2);
        cout << wei[n1] - wei[com] + wei[n2] - wei[com] << "\n";
    }
}