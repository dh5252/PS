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

using namespace std;

int a[200000];
int b[200000];
int sum[200000];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, H;
    int ans = 0;
    cin >> N >> H;

    for (int i = 0 ; i < N / 2 ; ++i)
        cin >> a[i] >> b[i];
    
    sort(a, a + N / 2);
    sort(b, b + N / 2);

    int min_v = INT_MAX;
    int cnt = 0;
    for (int i = 1 ; i <= H ; ++i)
    {
        int *k1 = lower_bound(a, a + N / 2, i);
        int *k2 = lower_bound(b, b + N / 2, H - i + 1);
        int value = a + N / 2 - k1;
        value += b + N / 2 - k2;
        if (min_v > value)
        {
            min_v = value;
            cnt = 1;
        }
        else if (min_v == value)
            ++cnt;
    }
    cout << min_v << " " << cnt;

}