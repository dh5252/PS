#include <bits/stdc++.h>

using namespace std;



list<string> lt;

int solution(int cacheSize, vector<string> cities) {
    
    vector<string> cp(cities.size());
    
    for (int i = 0 ; i < cities.size() ; ++i) {
        for (int j = 0 ; j < cities[i].length() ; ++j) {
            if (cities[i][j] >= 'A' && cities[i][j] <= 'Z')
                cp[i].push_back(cities[i][j] - 'A' + 'a');
            else
                cp[i].push_back(cities[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0 ; i < cp.size() ; ++i) {
        
        auto it = lt.begin();
        
        int flag = 0;
        while (it != lt.end()) {
            if (*it == cp[i])
            {
                lt.erase(it);
                lt.push_back(cp[i]);
                ans++;
                flag = 1;
                break;
            }
            it++;
        }
        if (flag) continue;
        
        if (lt.size() < cacheSize) {
            lt.push_back(cp[i]);
            ans += 5;
        }
        else if (cacheSize != 0) {
            lt.pop_front();
            lt.push_back(cp[i]);
            ans += 5;
        }
        else ans += 5;
    }
    return ans;
}