#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <queue>

#define ABS(x) ( ((x)<0)?-(x):(x) ) 

using namespace std;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int a, b; cin >> a >> b;
        int res = 1;
        while (b--)
        {
            res *= a;
            if (res % 10 == 0) res = 10;
            else res %= 10;
        }
        cout << res << "\n";
    }
}