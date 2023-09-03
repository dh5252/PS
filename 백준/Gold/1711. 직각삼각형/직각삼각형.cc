#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> dot[1501];
int N;
int arr[3];

inline long long line_length(long long x1, long long x2, long long y1, long long y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

bool is_rectangle()
{
    long long len1 = line_length(dot[arr[0]].first, dot[arr[1]].first, dot[arr[0]].second, dot[arr[1]].second);
    long long len2 = line_length(dot[arr[2]].first, dot[arr[1]].first, dot[arr[2]].second, dot[arr[1]].second);
    long long len3 = line_length(dot[arr[0]].first, dot[arr[2]].first, dot[arr[0]].second, dot[arr[2]].second);

    return ((len3 == len1 + len2 ) || (len2 == len1 + len3) || (len1 == len2 + len3));
}

int dfs(int index, int cnt)
{
    long long sum = 0;
    if (cnt == 3)
        return is_rectangle();
    if (index == N)
        return 0;
    sum += dfs(index + 1, cnt);
    arr[cnt] = index;
    sum += dfs(index + 1, cnt + 1);
    return (sum);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N;
    for (int i = 0 ; i < N ; ++i)
        cin >> dot[i].first >> dot[i].second;
    int arr[3];
    cout << dfs(0, 0);
}