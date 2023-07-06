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
#include <string>

using namespace std;

int dp[1001][1001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    string s1, s2; cin >> s1 >> s2;


    for (int i = 0; i < s1.length(); ++i)
    {
        for (int j = 0; j < s2.length(); ++j)
        {
            if (s1[i] == s2[j])
            {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                if (i == 0 && j == 0) dp[i][j] = 0;
                else if (i == 0) dp[i][j] = dp[i][j - 1];
                else if (j == 0) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[s1.length() - 1][s2.length() - 1] << "\n";

    if (dp[s1.length() - 1][s2.length() - 1] != 0)
    {
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        string ans;
        while (!(i < 0 || j < 0))
        {
            if (s1[i] == s2[j])
            {
                ans.push_back(s1[i]);
                --i;
                --j;
            }
            else
            {
                if (i == 0) --j;
                else if (j == 0) --i;
                else if (dp[i - 1][j] > dp[i][j - 1]) --i;
                else --j;
            }
        }
        for (int i = ans.length() - 1; i >= 0; --i)
            cout << ans[i];
    }


   
}

