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
#include <unordered_set>

#define ABS(x) ( ((x)<0)?-(x):(x) )
using namespace std;

long long dp[10001];
int arr[101];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n, k; cin >> n >> k;

    for (int i  = 0 ; i < n ; ++i)
        cin >> arr[i];
    
    for (int j = 0 ; j < n ; ++j)
    {
        for (int i = 1 ; i <= k ; ++i)
        {
            if (i - arr[j] == 0)
                dp[i] += 1;
            else if (i - arr[j] > 0)
                dp[i] += dp[i - arr[j]];
        }
    }
    cout << dp[k];


    return 0;
}