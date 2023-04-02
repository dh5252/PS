#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>

using namespace std;

double wei[16][16];
double dp[16][1 << 16];
int N;
int min_value;
int complete;


double dfs(int visit, int cur)
{
    if (visit == complete)
    {
        if (!wei[cur][0])
            return 2147483647;
        return wei[cur][0];
    }

    if (dp[cur][visit] != 0)
        return dp[cur][visit];

    dp[cur][visit] = 2147483647;
    for (int i = 0; i < N; ++i)
    {
        if (wei[cur][i] && !(visit & (1 << i)))
            dp[cur][visit] = min(dp[cur][visit], wei[cur][i] + dfs(visit | (1 << i), i));
    }
    return dp[cur][visit];
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    cin >> N;

    int x[16], y[16];

    for (int i = 0; i < N; ++i)
        cin >> x[i] >> y[i];
    

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            wei[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            wei[i][j] = sqrt(wei[i][j]);
        }
    complete = (1 << N) - 1;
    cout << fixed;
    cout.precision(8);
    cout << dfs(1, 0);
}