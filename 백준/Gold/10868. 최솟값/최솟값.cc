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

int arr[MAX_SIZE];
int tree[MAX_SIZE << 2];

void init(int l, int r, int node)
{
    if (l == r)
    {
        tree[node] = arr[l];
        return ;
    }
    init(l, (l + r) / 2, node * 2);
    init((l + r) / 2 + 1, r, node * 2 + 1);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int query(int l, int r, int s, int e, int node)
{
    if (s > r || e < l)
        return INT_MAX;
    if (s <= l && e >= r)
        return tree[node];
    int l_min = query(l , (l + r) / 2, s, e, node * 2);
    int r_min = query((l + r) / 2 + 1, r, s, e, node * 2 + 1);
    return min(l_min, r_min);
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 1 ; i <= N ; ++i)
        cin >> arr[i];
    init(1, N, 1);
    for (int i = 0 ; i < M ; ++i)
    {
        int a,b; cin >> a >> b;
        cout << query(1, N, a, b, 1) << "\n";
    }    
    return 0;
}