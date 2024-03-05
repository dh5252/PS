/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int N, L;
int m[101][101];
bool check[101];
int ans;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> L;
    for (int i = 0 ; i < N ; ++i) 
        for (int j = 0 ; j < N ; ++j) 
            cin >> m[i][j];
            
    for (int i = 0 ; i < N ; ++i) {
        
        int before = m[i][0];
        int poss = 1;
        memset(check, 0, sizeof(check));
        for (int j = 1 ; j < N ; ++j) {
            
            if (before == m[i][j]) 
                before = m[i][j];
            else if (before == m[i][j] + 1) {
                int flag = 0;
                for (int k = 0 ; k < L ; ++k) {
                    if (m[i][k + j] != m[i][j]) {
                        flag = 1;
                        break ;
                    }
                    check[k + j] = 1;
                }
                if (flag == 1) {
                    poss = 0;
                    break;
                }
                j += L - 1;
            }
            else if (before == m[i][j] - 1) {
                int flag = 0;
                for (int k = 0 ; k < L ; ++k) {
                    if (!(j - k - 1 >= 0 && m[i][j - k - 1] == before && !check[j - k - 1])) {
                        flag = 1;
                        break ;
                    }
                    check[j - k -1] = 1;
                }
                if (flag == 1) {
                    poss = 0;
                    break;
                }
            }
            else {
                poss = 0;
                break;
            }
            before = m[i][j];
        }
        if (poss == 1)
            ++ans;
    }
    
    for (int i = 0 ; i < N ; ++i) {
        
        int before = m[0][i];
        int poss = 1;
        memset(check, 0, sizeof(check));
        for (int j = 1 ; j < N ; ++j) {
            
            if (before == m[j][i]) 
                before = m[j][i];
            else if (before == m[j][i] + 1) {
                int flag = 0;
                for (int k = 0 ; k < L ; ++k) {
                    if (m[k + j][i] != m[j][i]) {
                        flag = 1;
                        break ;
                    }
                    check[k + j] = 1;
                }
                if (flag == 1) {
                    poss = 0;
                    break;
                }
                j += L - 1;
            }
            else if (before == m[j][i] - 1) {
                int flag = 0;
                for (int k = 0 ; k < L ; ++k) {
                    if (!(j - k - 1 >= 0 && m[j - k - 1][i] == before && !check[j - k - 1])) {
                        flag = 1;
                        break ;
                    }
                    check[j - k -1] = 1;
                }
                if (flag == 1) {
                    poss = 0;
                    break;
                }
            }
            else {
                poss = 0;
                break;
            }
            before = m[j][i];
        }
        if (poss == 1)
            ++ans;
    }
        
    cout << ans;
    
    return 0;
}
