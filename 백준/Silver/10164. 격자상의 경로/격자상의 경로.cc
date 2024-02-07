#include <bits/stdc++.h>
using namespace std;


long long dp[16][16];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,K;
    cin>>N>>M>>K;

    --K;
    pair<int, int> k(K / M, K % M);

    dp[0][0] = 1;
    
    for (int i = 0 ; i <= k.first ; ++i) {
        for (int j = 0 ; j <= k.second ; ++j) {
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
        }
    }
    dp[k.first][k.second] = 0;
    for (int i = k.first ; i < N ; ++i) {
        for (int j = k.second ; j < M ; ++j) {
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
        }
    }
    cout << dp[N-1][M-1];

    return 0;
}
