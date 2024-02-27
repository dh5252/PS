#include <bits/stdc++.h>

using namespace std;

vector<int> nd[18];
vector<int> inf;
int max_s;

void find_sheep(int *s, list<int> *wolf, int cur) {
    
    (*s)++;
    for (int i = 0 ; i < nd[cur].size() ; ++i) {
        if (inf[nd[cur][i]] == 0) 
            find_sheep(s, wolf, nd[cur][i]);   
        else
            (*wolf).push_back(nd[cur][i]);
    }
}


void search(int s, int w, list<int> wolf, int cur) {
    
    if (s <= w) return;
    
    //cout << "check : " << cur << ' ';
    
    vector<int> sheep;
    for (int i = 0 ; i < nd[cur].size() ; ++i) {
        if (inf[nd[cur][i]] == 0)
            sheep.push_back(nd[cur][i]);
        else
            wolf.push_back(nd[cur][i]);
    }
    
    for (int i = 0 ; i < sheep.size() ; ++i) 
        find_sheep(&s, &wolf, sheep[i]);
    //cout << s << "\n";
    max_s = max(max_s, s);

    for (auto it = wolf.begin() ; it != wolf.end() ; ++it) {
        int tmp = *it;
        it = wolf.erase(it);
        search(s, w + 1, wolf, tmp);
        wolf.insert(it, tmp);
        it--;
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    inf = info;
    
    for (int i = 0 ; i < edges.size() ; ++i) 
        nd[edges[i][0]].push_back(edges[i][1]);
    
    list<int> lst;
    search(1, 0, lst, 0);
    return max_s;
}