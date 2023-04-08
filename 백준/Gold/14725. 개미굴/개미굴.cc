#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

typedef struct node
{
    map<string, int> convert;
    vector<int> child;
    string str;
}node;

node nd[15001];
node root;
int node_cnt;


void dfs(int cur, int level)
{
    for (int i = 0 ; i < level ; ++i)
        cout << "--";
    cout << nd[cur].str << "\n";
    for (auto k = nd[cur].convert.begin(); k != nd[cur].convert.end() ; ++k)
        dfs(nd[cur].child[k->second], level + 1);
}



int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 0 ; i < N ; ++i)
    {
        int k; cin >> k;
        node *search = &root;
        for(int j = 0 ; j < k ; ++j)
        {
            string eat;
            cin >> eat;
            

            auto find = search->convert.find(eat);
            if (find == search->convert.end())
            {
                nd[node_cnt].str = eat;
                search->child.push_back(node_cnt++);
                search->convert.insert(make_pair(eat, search->child.size() - 1));   
                search = &nd[node_cnt - 1];
            }
            else
                search = &nd[search->child[find->second]];
        }
    }
    for (auto k = root.convert.begin(); k != root.convert.end() ; ++k)
        dfs(root.child[k->second], 0);
}