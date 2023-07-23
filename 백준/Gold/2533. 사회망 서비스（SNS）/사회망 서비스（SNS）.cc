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
#define LEAF 1
#define CHOICE 2

using namespace std;

list<int> nd[1000001];
int state[1000001];
int cnt;

void post_order(int index, int parent)
{
    auto i = nd[index].begin();
    while (i != nd[index].end())
    {
        if (*i != parent) post_order(*i, index);
        if (state[*i] == CHOICE) i = nd[index].erase(i);
        else ++i;
    }
    if (index == 1)
    {
        if (nd[index].size() != 0) ++cnt;
        return ;
    } 
    else if (nd[index].size() == 1) state[index] = LEAF;
    else
    {
        state[index] = CHOICE;
        ++cnt;
    }  
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N; cin >> N;
    for (int i = 0 ; i < N - 1 ; ++i)
    {
        int u,v; cin >> u >> v;
        if (u > v) swap(u, v);
        nd[u].push_back(v);
        nd[v].push_back(u);
    }
    post_order(1, 0);
    cout << cnt;
}