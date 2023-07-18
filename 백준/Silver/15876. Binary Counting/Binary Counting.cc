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

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n,k; cin >> n >> k;

    int num = 0;
    int cnt = 1;
    int standard = 2;
    int turn = -1;
    int prn_cnt = 0;
    while (1)
    {
        if (num == standard)
        {
            cnt++;
            standard <<= 1;
        }
        for (int i = 0 ; i < cnt ; ++i)
        {
            turn++;
            if (turn % n == k - 1) 
            {
                cout << (((1 << (cnt - i - 1)) & num) > 0) << " ";
                if (++prn_cnt == 5) return 0;
            }
        }
        num++;
        if (prn_cnt == 5) break;
    }
    
}