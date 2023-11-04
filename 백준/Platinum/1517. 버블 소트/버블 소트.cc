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

typedef struct node
{
    int index;
    int val;
}   node;

bool operator<(const node &a, const node &b)
{
    if (a.val == b.val)
        return a.index < b.index;
    return a.val < b.val;
}


int N;
long long seg[500001 << 1];

void update(int loc, int value)
{
    for (seg[loc += N] = value ; loc > 0 ; loc >>= 1)
        seg[loc >> 1] = seg[loc] + seg[loc^1];
}

long long query(int l, int r)
{
    long long res = 0;
    for (l += N, r += N ; l < r ; l >>= 1, r >>= 1)
    {
        if (l & 1) res += seg[l++];
        if (r & 1) res += seg[--r];
    }
    return res;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    cin >> N;
    node nd[500001];
    int arr[500001];

    for (int i = 0 ; i < N ; ++i)
    {
        cin >> arr[i];
        nd[i].val= arr[i];
        nd[i].index = i;
    }
    sort(nd, nd + N);
    long long ans = 0;
    for (int i = 0 ; i < N ; ++i)
    {
        long long v = seg[N + nd[i].index];
        update(nd[i].index, v + 1);
        ans += query(nd[i].index + 1, N);
    }
    cout << ans;
    return 0;
}