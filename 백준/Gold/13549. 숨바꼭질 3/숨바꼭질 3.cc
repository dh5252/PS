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

queue<pair<int, int> > que;
int dp[100001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
    int N, K; cin >> N >> K;

    for (int i = 0 ; i <= 100000 ; ++i)
        dp[i] = INT_MAX;


    que.push({K, 0});


    while (!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();

        int p = cur.first;
        //cout << "check : " << p <<  " " << cur.second << "\n";
        while (1)
        {
            if (dp[p] > cur.second)
            {
                que.push({p, cur.second});
                dp[p] = cur.second;
            }
            if (p - 1 >= 0 && dp[p - 1] > cur.second + 1)
            {
                que.push({p - 1, cur.second + 1});
                dp[p - 1] = cur.second + 1;
            }
            if (p + 1 <= 100000 && dp[p + 1] > cur.second + 1)
            {
                que.push({p + 1, cur.second + 1});
                dp[p + 1] = cur.second + 1;
            }
            if (p == 0) break;
            if (p % 2 == 0)
                p /= 2;
            else
            {
                if (dp[p] > cur.second)
                {
                    que.push({p, cur.second});
                    dp[p] = cur.second;
                }
                if (p - 1 >= 0 && dp[p - 1] > cur.second + 1)
                {
                    que.push({p - 1, cur.second + 1});
                    dp[p - 1] = cur.second + 1;
                }
                if (p + 1 <= 100000 && dp[p + 1] > cur.second + 1)
                {
                    que.push({p + 1, cur.second + 1});
                    dp[p + 1] = cur.second + 1;
                }
                break;
            }
        }
    }
    cout << dp[N];
    return 0;
}