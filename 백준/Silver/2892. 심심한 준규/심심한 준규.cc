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

    int N; cin >> N;
    for (int i = 0 ; i < N ; ++i)
    {
        string num; cin >> num;
        if (num[0] == '4'|| num[0] == '5') cout << "-";
        else cout << ".";
    }
    
}