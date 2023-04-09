#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>

#define ABS(x) ( ((x)<0)?-(x):(x) )
using namespace std;

int arr[1000000];
int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;

    cin >> N;
    int one = 0, two = 0, three = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        if (arr[i] == 1) one++;
        if (arr[i] == 2) two++;
        if (arr[i] == 3) three++;
    }

    int U, D;
    cin >> U >> D;

    if (one > U || two > D) 
        cout << "NO";
    else
    {
        one = U - one;
        two = D - two;
        cout << "YES\n";
        for (int i = 0; i < N; ++i)
        {
            if (arr[i] == 1)
                cout << "U";
            if (arr[i] == 2)
                cout << "D";
            if (arr[i] == 3)
            {
                if (one-- > 0)
                    cout << "U";
                else
                    cout << "D";
            }
        }
    }


    
}