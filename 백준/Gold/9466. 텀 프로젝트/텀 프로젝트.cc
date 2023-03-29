#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct node
{
    vector<int> child;
}   node;


node nd[100001];
int visit[100001];
int sum;

void dfs(int index, int first, int cnt)
{
    if (index == first)
    {
        sum += cnt;
        return;
    }
    if (visit[index])
        return;
    visit[index] = 1;
    if (!nd[index].child.size())
        return ;
    for (int i = 0; i < nd[index].child.size(); ++i)
        dfs(nd[index].child[i], first, cnt + 1);
}


int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);


    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        int n;
        sum = 0;
        cin >> n;
        memset(nd, 0, sizeof(nd));
        memset(visit, 0, sizeof(visit));
        for (int j = 1; j <= n; ++j)
        {
            int tmp;
            cin >> tmp;
            nd[tmp].child.push_back(j);
        }

        for (int j = 1; j <= n; ++j)
        {
            if (!visit[j])
            {
                visit[j] = 1;
                for (int k = 0; k < nd[j].child.size(); ++k)
                    dfs(nd[j].child[k], j, 1);
            }
        }
        cout << n - sum << "\n";
    }

}