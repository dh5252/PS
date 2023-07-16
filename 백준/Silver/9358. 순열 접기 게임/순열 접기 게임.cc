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

#define ABS(x) ( ((x)<0)?-(x):(x) ) 

using namespace std;


int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int T; cin >> T;
    for (int t = 1; t <= T ; ++t)
    {
        int N; cin >> N;
        long long arr[101];
        for (int i = 0 ; i < N ; ++i)
            cin >> arr[i];
        while (N > 2)
        {
            for (int i = 0 ; i <= (N - 1) / 2 ; ++i)
                arr[i] += arr[N - 1 - i];
            N = (N - 1) / 2 + 1;
        }
        cout << "Case #" << t << ": ";
        cout << (arr[0] > arr[1] ? "Alice" : "Bob");
        cout << "\n";
        
    }

}