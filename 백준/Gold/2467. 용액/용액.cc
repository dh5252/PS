#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

#define ABS(x) (((x) > (0)) ? (x) : -(x))

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
    int N;
    int a[100001];

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    int near = 2147483647;
    pair<int, int> p;
    for (int i = 0; i < N - 1; ++i)
    {
        int k = lower_bound(a + i + 1, a + N, -a[i]) - a;
        if (k >= N)
        {
            int value;
            value = ABS(a[i] + a[k - 1]);
            if (value < near)
            {
                near = value;
                p = make_pair(a[i], a[k - 1]);
            }
        }
        else if (k == i + 1)
        {
            int value;
            value = ABS(a[i] + a[k]);
            if (value < near)
            {
                near = value;
                p = make_pair(a[i], a[k]);
            }
        }
        else if (k > i + 1)
        {
            int value1 = ABS(a[i] + a[k]);
            int value2 = ABS(a[i] + a[k - 1]);
            
            if (value1 < value2 && value1 < near)
            {
                near = value1;
                p = make_pair(a[i], a[k]);
            }
            else if (value1 > value2 && value2 < near)
            {
                near = value2;
                p = make_pair(a[i], a[k - 1]);
            }
        }
    }
    cout << p.first << " " << p.second;
}