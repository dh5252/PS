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
#define MAX_SIZE 100001
using namespace std;

int tree[4 * MAX_SIZE];

void init(int l, int r, int node)
{
    if (l == r)
    {
        tree[node] = 1;
        return;
    }
    init(l, (l + r) / 2, node * 2);
    init((l + r) / 2 + 1, r, node * 2 + 1);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int l, int r, int find, int node)
{
    if (tree[node] <= find)
        return -1;
    if (l == r)
        return l;
    int res = -1;
    res = query(l, (l + r) / 2, find, node * 2);
    if (res == -1)
        res = query((l + r) / 2 + 1, r, find - tree[node * 2], node * 2 + 1);
    return res;
}

void update(int l, int r, int index, long long diff, int node)
{
    if (index < l || index > r)
        return;
    tree[node] += diff;
    if (l != r)
    {
        update(l, (l + r) / 2, index, diff, node * 2);
        update((l + r) / 2 + 1, r, index, diff, node * 2 + 1);
    }
}


int ans[100001];
int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N; cin >> N;

    init(1, N, 1);
    for (int i = 1 ; i <= N ; ++i)
    {
        int tmp; cin >> tmp;
        int loc = query(1, N, tmp, 1);
        ans[loc] = i;
        update(1, N, loc, -1, 1);
    } 
    for (int i = 1 ; i <= N ; ++i)
        cout << ans[i] << "\n";
    return 0;
}