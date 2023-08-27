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

long long arr[MAX_SIZE];
long long tree[MAX_SIZE << 2];
int N;

void init(int l, int r, int node)
{
    if (l == r)
    {
        tree[node] = l;
        return ;
    }
    init(l, (l + r) / 2, node * 2);
    init((l + r) / 2 + 1, r, node * 2 + 1);
    int min_index = -1;
    if (tree[node * 2] != -1)
        min_index = tree[node * 2];
    if (tree[node * 2 + 1] != -1 && (tree[node * 2] == -1 || arr[tree[node * 2]] > arr[tree[node * 2 + 1]]))
        min_index = tree[node * 2 + 1];
    tree[node] = min_index;
}

int query(int l, int r, int s, int e, int node)
{
    if (s > r || e < l)
        return -1;
    if (s <= l && e >= r)
        return tree[node];
    int l_min = query(l , (l + r) / 2, s, e, node * 2);
    int r_min = query((l + r) / 2 + 1, r, s, e, node * 2 + 1);
    int res = -1;
    if (l_min != -1)
        res = l_min;
    if (r_min != -1 && (res == -1 || arr[l_min] > arr[r_min]))
        res = r_min;
    return res;
}

long long dac(int l, int r)
{
    int loc = query(1, N, l, r, 1);

    if (loc == -1) return 0;
    long long res = (r - l + 1) * arr[loc];

    if (l == r) return res;

    long long l_res = dac(l, loc - 1);
    long long r_res = dac(loc + 1, r);

    return max(res, max(l_res, r_res));
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    while (1)
    {
        cin >> N;
        if (N == 0)
            return 0;
        for (int i = 1 ; i <= N ; ++i)
            cin >> arr[i];
        init(1, N, 1);
        cout << dac(1, N) << "\n";

    }

    
    return 0;
}