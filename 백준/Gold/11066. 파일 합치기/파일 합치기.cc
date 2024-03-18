
#include <bits/stdc++.h>

using namespace std;

int dp[501][501];
int cum[501];

int main()
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T; cin >> T;
    for (int t = 0 ; t < T ; ++t) {
        int K; cin >> K;
        memset(dp, 0, sizeof(dp));
        memset(cum, 0, sizeof(cum));
        int tmp;
        for (int i = 0 ; i < K ; ++i) {
            cin >> tmp;
            cum[i] = tmp;
            if (i > 0) cum[i] += cum[i - 1];
        }
        for (int gap = 1 ; gap < K ; ++gap) {
            for (int i = 0 ; i + gap < K ; ++i) {
                dp[i][i + gap] = INT_MAX;
                for (int j = i ; j < i + gap ; ++j) 
                    dp[i][i + gap] = min(dp[i][i + gap], dp[i][j] + dp[j + 1][i + gap]);
                dp[i][i + gap] += cum[i + gap];
                if (i > 0)
                    dp[i][i + gap] -= cum[i - 1];
            }
        }
        cout << dp[0][K - 1] << "\n";
    }
    

    return 0;
}
