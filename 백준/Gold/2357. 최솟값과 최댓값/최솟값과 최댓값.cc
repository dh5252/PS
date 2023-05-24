#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>
#include <limits.h>

using namespace std;

int arr[100001];
int max_seg[400002];
int min_seg[400002];
int N;

void init(int node, int start, int end)
{
    if (start == end)
    {
        min_seg[node] = max_seg[node] = arr[start];
        return;
    }
    init(node << 1, start, (start + end) >> 1);
    init(node << 1 | 1, ((start + end) >> 1) + 1, end);
    max_seg[node] = max(max_seg[node << 1], max_seg[node << 1 | 1]);
    min_seg[node] = min(min_seg[node << 1], min_seg[node << 1 | 1]);
}

pair<int, int> query(int left, int right, int start, int end, int node)
{
    if (end < left || start > right) return { 2147483647, 0 };
    
    if (left <= start && end <= right) return { min_seg[node], max_seg[node] };

    pair<int, int> tmp, tmp2;

    tmp = query(left, right, start, (start + end) >> 1, node << 1);
    tmp2 = query(left, right, ((start + end) >> 1) + 1, end, node << 1 | 1);

    tmp.first = min(tmp.first, tmp2.first);
    tmp.second = max(tmp.second, tmp2.second);
    return tmp;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) cin >> arr[i];


    init(1, 0, N - 1);

    for (int i = 0; i < M; ++i)
    {
        int a, b; cin >> a >> b;

        pair<int, int> tmp = query(a - 1, b - 1, 0, N - 1, 1);

        cout << tmp.first << " " << tmp.second << "\n";
    }
}

