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

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;

int s[1000001];

bool is_prime(int n)
{
    if (n <= 1) return 0;
    for (int i = 2 ; i <= sqrt(n) ; ++i)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N; cin >> N;

    int cnt = 0;
    for (int i = 1 ; i <= 1000000 ; ++i)
    {
        if (is_prime(i)) cnt++;
        s[i] = cnt;
    }
    for (int i = 0 ; i < N ; ++i)
    {
        int L,R; cin >> L >> R;
        if (L <= 0) L = 1;
        if (R <= 0) R = 1;
        if (s[(R << 1) - 1] - s[(L << 1)] < 0) cout << 0 << "\n";
        else cout << s[(R << 1) - 1] - s[(L << 1)] << "\n";
    }
    return 0;
}