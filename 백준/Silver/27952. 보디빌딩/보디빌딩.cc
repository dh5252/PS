#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>

#define ABS(x) ( ((x)<0)?-(x):(x) )
using namespace std;

long long A[500000];
long long B[500000];
long long sum[500000];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, X;
    cin >> N >> X;

    for (int i = 0; i < N; ++i)
        cin >> A[i];

    for (int i = 0; i < N; ++i)
    {
        cin >> B[i];
        if (i == 0)
            sum[i] = B[i];
        else
            sum[i] = sum[i - 1] + B[i];
    }

    for (int i = 0; i < N; ++i)
    {
        if (sum[i] < A[i])
        {
            cout << -1;
            return 0;
        }
    }
    
    long long cnt = 0;
    while (sum[N - 1] >= A[N - 1])
    {
        sum[N - 1] -= X;
        ++cnt;
    }
    cout << cnt - 1;
    
}