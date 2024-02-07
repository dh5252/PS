#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100000];
int dp[100000][3];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i =0;i<N;++i) {
        cin >> arr[i];
    }
    dp[0][0] = 0;
    dp[0][1] = arr[0];
    dp[0][0] = 0;
    for (int i = 1 ; i < N ; ++i) {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        dp[i][1] = dp[i - 1][0] + arr[i];
        dp[i][2] = dp[i - 1][1] + arr[i] / 2;
    }

    cout << max(dp[N - 1][0], max(dp[N - 1][1], dp[N - 1][2]));


    return 0;
}
