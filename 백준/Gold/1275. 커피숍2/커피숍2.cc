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
#define MAX_SIZE 100001

using namespace std;

long long a[MAX_SIZE];
long long tree[MAX_SIZE << 2];

void init(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = a[l];
        return ;
    }
    init(node << 1, l, (l + r) / 2);
    init(node << 1 | 1, (l + r) / 2 + 1, r);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

long long query(int l, int r, int s, int e, int n)
{
    if (s > r || l > e) return 0;
    else if (s >= l && r >= e) return tree[n];
    long long lsum = query(l, r, s, (s + e) / 2, n << 1);
    long long rsum = query(l, r, (s + e) / 2 + 1, e, n << 1 | 1);
    return lsum + rsum;
}

void update(int index, long long diff, int s, int e, int n)
{
    if (index >= s && index <= e)
    {
        tree[n] += diff;
        if (s == e) return;
        update(index, diff, s, (s + e) / 2, n << 1);
        update(index, diff, (s + e) / 2 + 1, e, n << 1 | 1);
    }
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, Q; cin >> N >> Q;
    for (int i = 0 ; i < N ; ++ i)
        cin >> a[i];
    init(1, 0, N - 1);
    for (int i = 0 ; i < Q ; ++i)
    {
        int x,y,A,B; cin >> x >> y >> A >> B;
        if (x > y) swap(x, y);
        cout << query(x - 1, y - 1, 0, N - 1, 1) << "\n";
        long long diff = B - a[A - 1];
        a[A - 1] = B;
        update(A - 1, diff, 0, N - 1, 1);
    }
}