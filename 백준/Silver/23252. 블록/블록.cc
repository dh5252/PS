#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>
#include <limits.h>
#include <string>
#include <unordered_map>

using namespace std;


int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int T; cin >> T;
    while (T--)
    {
        int A, B, C; cin >> A >> B >> C;
        if (A > 0 && C > 0)
        {
            A--;
            C--;
            if ((A - C) < 0 || (A - C) % 2 != 0) cout << "No\n";
            else cout << "Yes\n";
        }
        else if (A == 0 && C > 0) cout << "No\n";
        else if (A > 0 && C == 0)
        {
            if (A % 2 == 0) cout << "Yes\n";
            else cout << "No\n";
        }
        else if (B % 2 == 0) cout << "Yes\n";
        else cout << "No\n";
    }
}

