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

using namespace std;


int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int T; cin >> T;

    for (int i = 0; i < T; ++i)
    {
        int N; cin >> N;
        pair<double, double> dia[201];
        int dp[301] = { 0 };
        int max_len = 1;
        for (int j = 0; j < N; ++j)
        {
            cin >> dia[j].first >> dia[j].second;
            int flag = 0;
            dp[j] = 1;
            for (int k = j - 1; k >= 0; --k)
                if (dia[j].first > dia[k].first && dia[j].second < dia[k].second)
                    dp[j] = max(dp[k] + 1, dp[j]);                
            
            if (j == 0)
            {
                dp[j] = 1;
                continue;
            }
            if (dp[j] > max_len) max_len = dp[j];
        }
        cout << max_len << "\n";
    }
}

