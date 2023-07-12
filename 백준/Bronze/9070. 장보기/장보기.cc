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
    for (int t = 0; t < T; ++t)
    {
        int N; cin >> N;
        int max_number;
        double max_ratio = 0;
        for (int i = 0; i < N; ++i)
        {
            double w, c; cin >> w >> c;
            if (w / c > max_ratio)
            {
                max_ratio = w / c;
                max_number = c;
            }
            else if (w / c == max_ratio)
                if (c < max_number)
                    max_number = c;
        }
        cout << max_number << "\n";
    }
        
}

