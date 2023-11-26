#include <bits/stdc++.h>
using namespace std;

int N,M;
int m[501][501];
int dp[501][501];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int dfs(int i, int j)
{
    if (i == M - 1 && j == N - 1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = 0;
    for (int k = 0 ; k < 4 ; ++k)
    {
        int rx = i + dx[k];
        int ry = j + dy[k];
        if (rx>=0&&ry>=0&&rx<M&&ry<N&&m[rx][ry] < m[i][j])
            dp[i][j] += dfs(rx, ry);
    }
    return dp[i][j];
}


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >>M>>N;
    for(int i = 0 ; i < M ;++i)
        for(int j =0;j<N;++j)
            cin>>m[i][j];

    memset(dp, -1, sizeof(dp));
    cout << dfs(0,0);
    return 0;
}
