#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;

ordered_set s;

int r[1000001];
int arr[500001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int tmp;
        cin >> tmp;
        r[tmp] = i;
    }
    for (int i = 0; i < N; ++i)
    {
        int tmp;
        cin >> tmp;
        arr[i] = r[tmp];
    }

    long long sum = 0;
    for (int i = 0; i < N; ++i)
    {
        sum += s.size() - s.order_of_key(arr[i]);
        s.insert(arr[i]);
    }
    cout << sum;
    return 0;
}