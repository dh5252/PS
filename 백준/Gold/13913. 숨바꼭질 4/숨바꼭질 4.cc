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

using namespace std;

int visit[100001][2];
queue<pair<int, int> > que;
int dx[3][2] = { {1,1},{-1,1}, {0,2} };

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, K; cin >> N >> K;

    que.push({ N, 0 });
    visit[N][0] = 1;
    visit[N][1] = 0;
    while (!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();

        if (cur.first == K)
        {
            cout << cur.second << "\n";
            vector<int> ans;
            int search = cur.first;
            ans.push_back(cur.first);
            while (search != N)
            {
                search = visit[search][1];
                ans.push_back(search);
            }
            for (int i = ans.size() - 1; i >= 0; --i)
                cout << ans[i] << " ";
            break;
        }

        for (int i = 0; i < 3; ++i)
        {
            int rx = dx[i][0] + cur.first * dx[i][1];

            if (rx >= 0 && rx <= 100000)
            {
                if (!visit[rx][0])
                {
                    visit[rx][1] = cur.first;
                    visit[rx][0] += visit[cur.first][0];
                    que.push({ rx, cur.second + 1 });
                }
            }
        }
    }
}

