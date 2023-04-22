#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;

typedef struct node
{
    bool is_terminal;
    map<char, node *> child;
}   node;

node nd[8000000];
int node_cnt = 0;

node *getnode()
{
    nd[node_cnt].is_terminal = false;
    return &nd[node_cnt++];
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int C, N;
    cin >> C >> N;

    node *color = getnode();
    node *member = getnode();
    for (int i = 0 ; i < C ; ++i)
    {
        string str; cin >> str;
        node *search = color;
        for (int j = 0 ; j < str.length() ; ++j)
        {
            if (search->child.find(str[j] - 'a') == search->child.end())
                search->child[str[j] - 'a'] = getnode();
            search = search->child[str[j] - 'a'];
        }
        search->is_terminal = true;
    }

    for (int i = 0 ; i < N ; ++i)
    {
        string str; cin >> str;
        node *search = member;
        for (int j = str.length() - 1 ; j >= 0 ; --j)
        {
            if (search->child.find(str[j] - 'a') == search->child.end())
                search->child[str[j] - 'a'] = getnode();
            search = search->child[str[j] - 'a'];
        }
        search->is_terminal = true;
    }

    int Q; cin >> Q;
    for (int i = 0 ; i < Q ; ++i)
    {
        string str; cin >> str;
        int j;
        node *search = color;
        set<int> check;
        for (j = 0 ; j < str.length() ; ++j)
        {
            if (search->is_terminal)
                check.insert(j - 1);
            
            if (search->child.find(str[j] - 'a') == search->child.end())
                break;
            search = search->child[str[j] - 'a'];
        }
        int flag = 0;
        search = member;
        for (j = str.length() - 1; j >= 0 ; --j)
        {
            if (search->is_terminal)
            {
                if (check.find(j) != check.end())
                {
                    cout << "Yes\n";
                    flag = 1;
                    break;
                }
            }
            if (search->child.find(str[j] - 'a') == search->child.end())                
                break;
            search = search->child[str[j] - 'a'];
        }
        if (!flag)
            cout << "No\n";
        
    }


}