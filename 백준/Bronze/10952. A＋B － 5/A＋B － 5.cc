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
    
    while (1)
    {
        int A, B; cin >> A >> B;
        if (A == 0 && B == 0) break;
        cout << A + B << "\n";
    }

}