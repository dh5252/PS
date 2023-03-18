#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    int S;
    int dp[100001];

    cin >> N >> S;

    dp[0] = 0;
    cin >> dp[1];
    for (int i = 2 ; i <= N; ++i)
    {
        int tmp;
        cin >> tmp;
        dp[i] = dp[i - 1] + tmp;
    }
    int min_len = 2147483647;
    for (int i = 0 ; i <= N ; ++i)
    {
        int find = S + dp[i];

        int find_index = lower_bound(dp + i, dp + N + 1, find) - (dp);
        if (find_index != N + 1)
            min_len = min(min_len, find_index - i);
    }
    if (min_len == 2147483647)
        cout << 0;
    else
        cout << min_len;
}