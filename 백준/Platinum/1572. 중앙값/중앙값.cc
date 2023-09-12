#include <bits/stdc++.h>

#define MAX_SIZE 250001
using namespace std;

int N, K;
int arr[MAX_SIZE];
int seg[65537 << 2];

void update(int l, int r, int node, int index, int diff)
{
    if (index < l || index > r)
        return ;
    seg[node] += diff;
    if (l != r)
    {
        update(l, (l + r) / 2, node * 2, index, diff);
        update((l + r) / 2 + 1, r, node * 2 + 1, index, diff);
    }
}

int query(int find, int node, int l, int r)
{   
    if (l == r)
        return l;   
    if (seg[node << 1] >= find)
        return query(find, node * 2, l, (l + r) / 2);
    return query(find - seg[node << 1], node * 2 + 1, (l + r) / 2 + 1, r);
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N >> K;
    for (int i = 0 ; i < N ; ++i)
        cin >> arr[i];
    
    for (int i = 0 ; i < K ; ++i)
        update(0, 65536, 1, arr[i], 1);
    
    long long sum = 0;
    sum += (long long)query((K + 1) / 2, 1, 0, 65536);
    for (int i = K ; i < N ; ++i)
    {
        update(0, 65536, 1, arr[i - K], -1);
        update(0, 65536, 1, arr[i], 1);
        sum += (long long)query((K + 1) / 2, 1, 0, 65536);
    }
    cout << sum;
}