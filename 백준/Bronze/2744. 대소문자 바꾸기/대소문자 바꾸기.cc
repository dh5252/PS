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

    string str; cin >> str;

    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            cout << (char)(str[i] - 'a' + 'A');
        else
            cout << (char)(str[i] - 'A' + 'a');
    }
   
}