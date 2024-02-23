#include <bits/stdc++.h>

using namespace std;

//find -> delete -> find ..

int N, M;
bool del[31][31];
int ans;

void search(vector<string> b) {
    memset(del, 0, sizeof(del));
    for (int i = 0 ; i < N ; ++i) {
        for (int j = 0 ; j < b[i].size() ; ++j) {
            
            if (i + 1 == N || j == 0 || b[i + 1].length() <= j) continue;
            
            if (b[i][j] == b[i][j - 1] && b[i][j] == b[i + 1][j - 1] && b[i][j] == b[i + 1][j])
            {
                del[i][j] = 1;
                del[i + 1][j - 1] = 1;
                del[i + 1][j] = 1;
                del[i][j - 1] = 1;
            }
        }
    }
}


pair<vector<string>, bool> delete_and_cp(vector<string> b) {
    
    vector<string> cp(N);
    bool ok = 0;
    for (int j = 0 ; j < N ; ++j)
        for (int i = 0 ; i < b[j].size() ; ++i) {
            if (del[j][i]) {
                ans++;
                ok = 1;                
            }
            else
                cp[j].push_back(b[j][i]);
        }
    return make_pair(cp, ok);
}

int solution(int m, int n, vector<string> board) {
    
    N = n;
    M = m;
    
    vector<string> cp(N);
    for (int i = M - 1 ; i >= 0 ; --i)
        for (int j = 0 ; j < N ; ++j)
            cp[j].push_back(board[i][j]);
    
    while (1) {
        search(cp);
        pair<vector<string>, bool> res = delete_and_cp(cp);
        cp = res.first;
        // for (int i = 0 ; i < N ; ++i)
        //     cout << cp[i] << "\n";
        if (res.second == 0) break;
    }
    
    return ans;
}