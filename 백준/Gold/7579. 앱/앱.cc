#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>

#define ABS(x) ( ((x)<0)?-(x):(x) )
using namespace std;

typedef struct app
{
    int m;
    int c;
}   app;

bool operator < (const app& a, const app& b)
{
    if (a.c == b.c)
        return a.m > b.m;
    return a.c < b.c;
}

int dp[10001][100];
app ap[10001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    


    for (int i = 0; i < N; ++i)
        cin >> ap[i].m;
    
    for (int i = 0; i < N; ++i)
        cin >> ap[i].c;

    sort(ap, ap + N);

    for (int i = 0; i < 10001; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int max_v = 0;

            if (i > 0) max_v = max(max_v, dp[i - 1][j]);
            if (j > 0) max_v = max(max_v, dp[i][j - 1]);
            if (i >= ap[j].c)
                if (i - ap[j].c >= 0)
                {
                    int new_v = ap[j].m;
                    if (i - ap[j].c >= 0 && j - 1 >= 0) new_v += dp[i - ap[j].c][j - 1];
                    max_v = max(max_v, new_v);
                }
            
            dp[i][j] = max_v;
            
            if (max_v >= M)
            {
                cout << i << "\n";
                return 0;
            }
        }
     
    }
    return 0;
    
    
}