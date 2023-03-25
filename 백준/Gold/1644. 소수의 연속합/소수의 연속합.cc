#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

#define MAX 4000000

using namespace std;


int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
   
    int *n_prime = new int[MAX + 1];
    long long *dp = new long long[MAX];
    vector<int> prime;

   cin >> N;
   for (int i = 2 ; i <= MAX ; ++i)
   {
       if (!n_prime[i])
       {
           prime.push_back(i);
           int tmp = i;
           while (tmp <= MAX)
           {
                n_prime[tmp] = 1;
                tmp += i;
           }
       }
   }


   dp[0] = prime[0];
    for (int i = 1 ; i < prime.size() ; ++i)
        dp[i] = prime[i] + dp[i - 1];
    
    
    int res = 0;
    int k = lower_bound(dp, dp + prime.size() , N) - dp;

    for (int i = k ; i < prime.size() ; ++i)
    {
        long long gap = dp[i] - N;
        if (gap == 0)
        {
            ++res;
            continue;
        }
        int find = lower_bound(dp, dp + i, gap) - dp;
        if (find < i && gap == dp[find])
            ++res;
    }
    cout << res;
}