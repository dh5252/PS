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
#include <list>

using namespace std;

vector<pair<int, int> > view;
list<pair<int, int> > cur;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int N = n;
    while (n--)
    {
        int l, r; cin >> l >> r;
        view.push_back({ l,r });
    }
    
    for (int i = view.size() - 1; i >= 0; --i)
    {
        auto it = cur.begin();
        pair<int, int> f = view[i];
        int flag = 0;
        
        while (it != cur.end())
        {
            if (f.first >= it->first && f.second <= it->second) flag = 1;
            if (view[i].first >= it->first && view[i].second <= it->second)
            {
                view[i].first = it->first;
                view[i].second = it->second;
                it = cur.erase(it);
            }
            else if (view[i].first <= it->first && view[i].second >= it->second)
                it = cur.erase(it);
            else if (view[i].first - 1<= it->second && view[i].second > it->second)
            {
                view[i].first = it->first;
                it = cur.erase(it);
            }
            else if (view[i].second + 1 >= it->first && view[i].first < it->first)
            {
                view[i].second = it->second;
                it = cur.erase(it);
            }
            else it++;
            
        }  
        cur.push_back(view[i]);
        N -= flag;
    }
    cout << N;
}

