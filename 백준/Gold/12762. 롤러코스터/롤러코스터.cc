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

int LDS[1001];
int LIS[1001];
int arr[1001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N; cin >> N;
    for (int i = 0 ; i < N ; ++i)
    {
        cin >> arr[i];
        LDS[i] = LIS[i] = 1;
    }
    for (int i = 1 ; i < N ; ++i)
    {
        int max_value = 0;
        for (int j = i - 1 ; j >= 0 ; --j)
            if (arr[i] < arr[j] && max_value <= LDS[j])
            {
                LDS[i] = LDS[j] + 1;
                max_value = LDS[j];
            }
    }
    LIS[N - 1] = 1;
    for (int i = N - 2 ; i >= 0 ; --i)
    {
        int max_value = 0;
        for (int j = i + 1 ; j < N ; ++j)
            if (arr[i] < arr[j] && max_value <= LIS[j])
            {
                LIS[i] = LIS[j] + 1; 
                max_value = LIS[j];
            }
    }
    int max_v = 1;
    for (int i = 0 ; i < N ; ++i)
        if (LDS[i] > 1)
            if (max_v < LIS[i] + LDS[i] - 1)
                max_v = LIS[i] + LDS[i] - 1;
    cout << max_v;
}