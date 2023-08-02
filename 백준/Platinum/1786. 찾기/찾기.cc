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

int p[1000001];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    string T,P;
    getline(cin, T);
    getline(cin, P);

    int j = 0;
    for (int i = 1 ; i < P.length() ; ++i)
    {
        while (j > 0 && P[j] != P[i])
            j = p[j - 1];
        if (P[j] == P[i])
            p[i] = ++j;
    }

    vector<int> ans;
    j = 0;
    for (int i = 0 ; i < T.length() ; ++i)
    {
        while (j > 0 && T[i] != P[j])
            j = p[j - 1];
        if (T[i] == P[j])
        {
            if (j == P.length() - 1)
            {
                ans.push_back(i - j + 1);
                j = p[j];
            }
            else ++j;
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0 ; i < ans.size() ; ++i)
        cout << ans[i] << "\n";
    return 0;
}