#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <limits.h>
#include <list>
#include <stack>

#define ABS(x) ( ((x)<0)?-(x):(x) ) 

using namespace std;

int arr[100001];
int dp[100001][2];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N; cin >> N;
    for (int i = 0 ; i < N ; ++i)
    {
        int t1,t2; cin >> t1 >> t2 >> arr[i];
    }
    dp[0][0] = arr[0];
    dp[0][1] = 0;
    for (int i = 1 ; i < N ; ++i)
    {
        dp[i][0] = dp[i - 1][1] + arr[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << max(dp[N - 1][0], dp[N - 1][1]);
}