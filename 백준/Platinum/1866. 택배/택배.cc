#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
	std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
    int N;

    cin >> N;

    int arr[3001];
    for (int i = 1 ; i <= N ; ++i)
        cin >> arr[i];
    int h_cost, t_cost;
    cin >> t_cost >> h_cost;
    sort(arr + 1, arr + N + 1);
    int sum[3001];
    memset(sum, 0 , sizeof(sum));
    for (int i = 1 ; i <= N ; ++i)
        sum[i] = sum[i - 1] + arr[i];
    int dp[3001];
    memset(dp, 0 , sizeof(dp));

    for (int i = 1 ; i <= N ; ++i)
    {
        dp[i] = dp[i - 1] + arr[i] * t_cost;
        for (int j = i ; j >= 1 ; --j)
        {
            int m = (i + j) >> 1;
            int l = (arr[m] * (m - j + 1) - (sum[m] - sum[j - 1])) * t_cost;
            int r = (sum[i] - sum[m - 1] - (arr[m] * (i - m + 1))) * t_cost;
            dp[i] = min(dp[i], dp[j - 1] + l + r + h_cost);
        }
    }
    cout << dp[N];
}