#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long dp[100000][3];

int main()
{
    int N; scanf("%d", &N);

    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    for (int i = 1 ; i < N ;++i)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][1]) % 9901;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
    }
    printf("%lld", (dp[N - 1][0] + dp[N - 1][1] + dp[N-1][2])%9901);
}