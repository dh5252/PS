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
#include <unordered_set>

#define ABS(x) ( ((x)<0)?-(x):(x) )
using namespace std;


int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int arr[1001];
    int num = 1;
    int cnt = 1;
    int A, B; cin >> A >> B;

    for (int i = 1 ; i <= B ; ++i)
    {
        arr[i] = num;
        if (--cnt == 0)
        {
            num++;
            cnt = num;
        }
    }

    int s = 0;
    for (int i = A ; i <= B ; ++i)
        s += arr[i];
    cout << s;
    
    
    return 0;
}