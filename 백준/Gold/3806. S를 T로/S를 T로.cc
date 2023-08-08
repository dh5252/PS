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

    int T; cin >> T;
    for (int t = 1 ; t <= T ; ++t)
    {
        string S,T; cin >> S >> T;
        int oz = 0;
        int zo = 0;
        int qc = 0;
        int fo = 0;
        int so = 0;
        int ne = 0;
        for (int i = 0 ; i < S.length() ; ++i)
        {
            if (S[i] == '1') ++fo;
            if (T[i] == '1') ++so;
            if (S[i] == '1' && T[i] == '0')
                ++oz;
            if (S[i] == '0' && T[i] == '1')
                ++zo;
            if (S[i] == '?')
                ++qc;
            if (S[i] != T[i]) ++ne;
        }
        int ans = 0;
        if (fo > so) ans = -1;
        else if (oz == zo) ans = oz + qc;
        else ans = ABS(oz - zo) + qc + min(oz, zo);
            
        
        cout << "Case " << t << ": " << ans << "\n";
    }
    return 0;
}