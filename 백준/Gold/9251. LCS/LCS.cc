#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int dp[1001][1001];


int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
    string a, b;

    cin >> a >> b;

    for (int i = 0; i < a.length(); ++i)
    {
        for (int j = 0; j < b.length(); ++j)
        {
            if (i == 0 && j == 0)
            {
                if (a[i] == b[j])
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
            else if (i == 0)
                dp[i][j] = max(dp[i][j - 1], (int)(a[i] == b[j]));
            else if (j == 0)
                dp[i][j] = max(dp[i - 1][j], (int)(a[i] == b[j]));
            else
            {
                if (a[i] == b[j])
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, max(dp[i - 1][j], dp[i][j - 1]));
            
                
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    cout << dp[a.size() - 1][b.size() - 1];
}