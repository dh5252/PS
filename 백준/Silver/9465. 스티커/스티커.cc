#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <unordered_map>

using namespace std;

int dp[100001][2];
int stick[100001][2];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int n;
        cin >> n;
        for (int j = 1; j <= n; ++j)
            cin >> stick[j][0];
        
        for (int j = 1; j <= n; ++j)
            cin >> stick[j][1];
        
        memset(dp, 0, sizeof(dp));
        dp[1][0] = stick[1][0];
        dp[1][1] = stick[1][1];
        dp[2][0] = dp[1][1] + stick[2][0];
        dp[2][1] = dp[1][0] + stick[2][1];
        for (int j = 3; j <= n; ++j)
        {
            dp[j][0] = max(dp[j - 1][1], dp[j - 2][1]);
            dp[j][0] += stick[j][0];
            dp[j][1] = max(dp[j - 1][0], dp[j - 2][0]);
            dp[j][1] += stick[j][1];
        }
        cout << max(dp[n][0], dp[n][1]) << "\n";
    }
}