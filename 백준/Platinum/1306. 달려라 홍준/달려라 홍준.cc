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
#define MAX_SIZE 1000001

long long arr[MAX_SIZE];
long long tree[MAX_SIZE << 2];

using namespace std;

void init(int n, int s, int e)
{
    if (s == e)
    {
        tree[n] = arr[s];
        return;
    }
    init(n << 1, s, (s + e) / 2);
    init(n << 1 | 1, (s + e) / 2 + 1, e);
    tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
}

long long query(int n, int l, int r, int s, int e)
{
    if (s > r || l > e) return 0;
    else if (s >= l && e <= r) return tree[n];
    return max(query(n << 1, l, r, s, (s + e) / 2), query(n << 1 | 1, l, r, (s + e) / 2 + 1, e));
}

void update(int n, int index, long long new_v, int s, int e)
{
    if (index >= s && index <= e)
    {
        tree[n] = max(tree[n], new_v);
        if (s == e) return ;
        update(n << 1, index, new_v, s, (s + e) / 2);
        update(n << 1 | 1, index, new_v, (s + e) / 2 + 1, e);
    }
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    for (int i = 0 ; i < N ; ++i)
        cin >> arr[i];
    init(1, 0, N - 1);
    for (int i = M ; i <= N - M + 1 ; ++i)
        cout << query(1, i - M, M + i - 2, 0, N - 1) << " ";
    
}