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

using namespace std;

int P[201];
bool visit[201];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int T; cin >> T;
    for (int t = 1 ; t <= T ; ++t)
    {
        int N; cin >> N;
        for (int i = 0 ; i < 2 * N ; ++i)
            cin >> P[i];
        
        vector<int> ans;
        memset(visit, 0 , sizeof(visit));
        for (int i = 0 ; i < 2 * N ; ++i)
        {
            if (visit[i]) continue;
            for (int j = i + 1 ; j < 2 * N ; ++j)
                if (!visit[j] && P[j] % 4 == 0 && P[i] == P[j] / 4 * 3)
                {
                    ans.push_back(P[i]);
                    visit[j] = 1;
                    break;
                }
        }
        cout << "Case #" << t << ":";
        for (int i = 0 ; i < ans.size() ; ++i)
            cout << " " << ans[i];
        cout << "\n";
    }

}