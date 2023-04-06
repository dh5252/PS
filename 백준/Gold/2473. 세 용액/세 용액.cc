#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>

#define ABS(x) ( ((x)<0)?-(x):(x) )
using namespace std;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    long long arr[5001];

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    sort(arr, arr + N);

    long long min_v = LLONG_MAX;
    int min_arr[3];
    for (int i = 0; i < N - 2; ++i)
    {
        if (arr[i] >= 0)
        {
            if (ABS(min_v) > ABS(arr[i] + arr[i + 1] + arr[i + 2]))
            {
                min_arr[0] = arr[i];
                min_arr[1] = arr[i + 1];
                min_arr[2] = arr[i + 2];
            }
            break;
        }
        
        for (int j = i + 1; j < N - 1; ++j)
        {
            int k = lower_bound(arr + j + 1, arr + N, -(arr[i] + arr[j])) - arr;
            int search;
            if (k == N)
                search = k - 1;
            else if (k == j + 1)
                search = k;
            else
            {
                if (ABS(arr[i] + arr[j] + arr[k]) > ABS(arr[i] + arr[j] + arr[k - 1]))
                    search = k - 1;
                else
                    search = k;
            }
            if (ABS(min_v) > ABS(arr[i] + arr[j] + arr[search]))
            {
                min_v = arr[i] + arr[j] + arr[search];
                min_arr[0] = arr[i];
                min_arr[1] = arr[j];
                min_arr[2] = arr[search];
            }
        }
    }
    
    cout << min_arr[0] << " " << min_arr[1] << " " << min_arr[2] << "\n";

 
        
    
    
}