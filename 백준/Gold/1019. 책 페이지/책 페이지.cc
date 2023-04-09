#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

long long arr[12][10];
int ans[10];

void rec(int dep, int num)
{
    
}


int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N; 

    cin >> N;

    int loc = 1;
    for (int i = 1 ; i < 12 ; ++i)
    {
        for (int j = 0 ; j < 10 ; ++j)
            arr[i][j] = loc * i;
        loc *= 10;
    }
    
    int place = 1;
    int digit_cnt = 1;

    int cp_N = N / 10;
    while (cp_N > 0)
    {
        ++digit_cnt;
        place *= 10;
        cp_N /= 10;
    }

    int save_loc = place;
    for (int j = digit_cnt - 2; j >= 0 ; --j)
    {
        ans[0] -= save_loc;
        save_loc /= 10;
    }
 
    while (digit_cnt > 0)
    {
        int d = N / place;
        int m = N % place;
        if (digit_cnt > 1)
        {
            ans[d] += m + 1;
            for(int i = 0 ; i < d ; ++i)
                ans[i] += place;
            
            
            for(int i = 0 ; i < 10 ;++i)
                ans[i] += arr[digit_cnt - 1][i] * d;
        }
        else
        {
            for (int i = 0 ; i <= d ; ++i)
                ++ans[i];
        }
        N = m;
        place /= 10;
        --digit_cnt;
    }

    --ans[0];

    for (int i = 0 ; i < 10 ; ++i)
        cout << ans[i] << " ";

}