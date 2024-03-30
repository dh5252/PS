#include <bits/stdc++.h>
using namespace std;

int dp[501][501];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N; cin >> N;
    pair<int, int> nd[501];
    for (int i = 0 ; i < N ; ++i)
        cin>>nd[i].first>>nd[i].second;

    for (int r = 1 ; r <= N ; ++r) {
        for (int s = 0 ; s + r < N ; ++s) {
            dp[s][s + r] = INT_MAX;
            for (int i = s + 1 ; i <= s + r ; ++i) 
                dp[s][s+r] = min(dp[s][s+r], dp[s][i-1] + dp[i][s+r] + nd[s].first * nd[i].first * nd[s+r].second);
        }
    }
    cout << dp[0][N-1];
}

