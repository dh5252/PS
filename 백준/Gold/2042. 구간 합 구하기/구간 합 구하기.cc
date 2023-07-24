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
long long tree[4000004];
long long a[1000001];

void init(int n, int s, int e)
{
    if (s == e)
        tree[n] = a[s];
    else
    {
        init(n*2, s, (s + e) / 2);
        init(n*2 + 1, (s + e) / 2 + 1, e);
        tree[n] = tree[n*2] + tree[n*2+1];
    }
}

long long query(int l, int r, int s, int e, int n)
{
    if (l > e || s > r) return 0;
    else if (l <= s && r >= e) return tree[n];
    long long lsum = query(l, r, s, (s + e)/2, n*2);
    long long rsum = query(l, r, (s + e)/2 + 1, e, n*2+1);
    return lsum + rsum;
}

void update(int index, long long diff, int s, int e, int n)
{
    if (index >= s && index <= e)
    {
        tree[n] += diff;
        if (s == e) return ;
        update(index, diff, s, (s+e)/2, n*2);
        update(index, diff, (s+e)/2 + 1, e, n*2+1);
    }
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, M, K; cin >> N >> M >> K;
    for (int i = 0 ; i < N ; ++i)
        cin >> a[i];
    init(1,0,N - 1);
    
    for (int i = 0 ; i < M + K ; ++i)
    {
        long long A,B,C; cin >> A >> B >> C;
        if (A == 1) 
        {
            long long diff = C - a[B - 1];
            a[B - 1] = C;
            update(B - 1, diff, 0 , N - 1, 1);
        }
        if (A == 2) cout << query(B - 1, C - 1, 0, N - 1, 1) << "\n";
    }
}