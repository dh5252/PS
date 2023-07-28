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
    
    int sum = 0;
    for (int i = 0; i < 5; ++i)
    {
        int n; cin >> n;
        sum += n * n;
    }
    cout << sum % 10;
}