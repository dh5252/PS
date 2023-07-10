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

long long A[200001];
long long B[200001];
long long dp[200001][2];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    long long N, K; cin >> N >> K;

    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < N; ++i)
        cin >> B[i];
    
    dp[0][0] = A[0];
    dp[0][1] = B[0];
    for (int i = 1; i < N; ++i)
    {
        dp[i][0] = A[i];
        dp[i][0] += min(dp[i - 1][0], dp[i - 1][1] + K);
        dp[i][1] = B[i];
        dp[i][1] += min(dp[i - 1][0] + K, dp[i - 1][1]);
    }
    cout << min(dp[N - 1][0], dp[N - 1][1]);
}

