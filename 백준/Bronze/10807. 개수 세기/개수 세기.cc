#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <cmath>

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N; cin >> N;
    int arr[101];
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    int v; cin >> v;
    int cnt = 0;
    for (int i = 0; i < N; ++i)
        if (arr[i] == v)
            ++cnt;
    cout << cnt;
}       