#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

string str;
int dp[501][501];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> str;
    for (int len = 1; len <= str.length() ; ++len) {
        for (int s = 0 ; s <= str.length() - len; ++s) {
            if ((str[s] == 'a' && str[s + len] == 't') || (str[s] == 'g' && str[s + len] == 'c')) {
                dp[s][s + len] = max(dp[s + 1][s + len - 1] + 2, dp[s][s + len]);
            }
            for (int k = 0 ; k < len ; ++k) {
                dp[s][s + len] = max(dp[s][s + k] + dp[s + k + 1][s + len], dp[s][s + len]);
            }
        }
    }
    cout << dp[0][str.length() - 1];
}
