#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <cmath>

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;

int A[1001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N; cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    int i = 0;
    int cnt = 0;
    while (A[i] != 0)
    {
        int max_idx = 0;
        int save = 0;

        for (int k = i; k <= i + A[i]; ++k)
        {
            if (A[k] + k >= N - 1)
            {
                cout << cnt + 2;
                return 0;
            }
            
            if (A[k] + k >= max_idx)
            {
                save = k;
                max_idx = A[k] + k;
            }
        }
        cnt++;
        i = save;
    }
    if (N == 1) cout << 0;
    else cout << -1;
}