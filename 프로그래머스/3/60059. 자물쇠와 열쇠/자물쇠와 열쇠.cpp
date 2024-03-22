#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<vector<int>> keys[4];
vector<vector<int>> loc;
int hole;

void rotate(int k, int s, int e) {
    
    //left
    for (int i = 0 ; i <= e - s; ++i) 
        keys[k][s + i][s] = keys[k - 1][s][e - i];
    //bottom
    for (int i = 0 ; i <= e - s ; ++i)
        keys[k][e][s + i] = keys[k - 1][s + i][s];
    //right
    for (int i = 0 ; i <= e - s ; ++i)
        keys[k][e - i][e] = keys[k - 1][e][s + i];
    //top
    for (int i = 0 ; i <= e - s ; ++i)
        keys[k][s][e - i] = keys[k - 1][e - i][e];
    
    s++;
    e--;
    if (s < e)
        rotate(k, s, e);
    else if (s == e)
        keys[k][s][s] = keys[k-1][s][s];
}

bool check(int si, int sj) {
    
    for (int index = 0 ; index < 4 ; ++index) {
        int flag = 0;
        int cnt = 0;
        for (int i = 0 ; i < M ; ++i) {
            for (int j = 0 ; j < M ; ++j) {
                int ri = i + si;
                int rj = j + sj;
                if (ri >= 0 && rj >= 0 && ri < N && rj < N) {
                    if (loc[ri][rj] != keys[index][i][j]) {
                        if (loc[ri][rj] == 0)
                            cnt++;
                    }
                    else {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag)
                break;
        }
        if (!flag && cnt == hole)
            return true;
    }
    return false;
}



bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    M = key.size();
    N = lock.size();
    
    loc = lock;
    keys[0] = key;
    for (int i = 1; i < 4 ; ++i) {
        keys[i] = keys[i - 1];
        rotate(i, 0, M - 1);        
    }

    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < N ; ++j)
            if (lock[i][j] == 0)
                hole++;
    
    for (int i = 1 - M ; i < N ; ++i)
        for (int j = 1 - M ; j < N ; ++j)
            if (check(i, j))
                return true;
    
    return false;
}