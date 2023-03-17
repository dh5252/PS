#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int parent[500000];
int height[500000];

int find(int child)
{
    if (parent[child] == child)
        return child;
    return parent[child] = find(parent[child]);
}

int set_union(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y)
        return 1;
    
    if (height[x] < height[y])
        parent[x] = y;
    else if (height[x] > height[y])
        parent[y] = x;
    else
    {
        parent[y] = x;
        ++height[x];
    }
    return 0;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n, m; 
    cin >> n >> m;

    int prn = 0;
    for (int i = 0 ; i < n ; ++i)
        parent[i] = i;

    for (int i = 1 ; i <= m ; ++i)
    {
        int c1, c2;
        cin >> c1 >> c2;

        if (!prn && set_union(c1, c2))
            prn = i;
    }
    cout << prn;
}