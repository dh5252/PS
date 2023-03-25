#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int A[1000000];
int dp[1000001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

   
    cin >> N;
    for(int i = 0 ; i < N ; ++i)
        cin >> A[i];

    int max_len = 0;  
    for (int i = 0 ; i < N ; ++i)
    {
        int k = lower_bound(dp, dp + max_len + 1, A[i]) - dp;
        if (k > max_len)
            ++max_len;
        dp[k] = A[i];
    }
    cout << max_len;
}