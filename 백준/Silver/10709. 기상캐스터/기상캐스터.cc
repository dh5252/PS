#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <set>

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;

char map[101][101];
int ans[101][101];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int W, H;
    cin >> H >> W;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
        {
            cin >> map[i][j];
            
            int k;
            for (k = j; k >= 0; --k)
                if (map[i][k] == 'c')
                    break;
            if (k == -1) ans[i][j] = -1;
            else
                ans[i][j] = j - k;
        }

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
    

    return 0;
}