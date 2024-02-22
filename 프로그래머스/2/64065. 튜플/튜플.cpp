#include <bits/stdc++.h>

using namespace std;

vector<int> v[1000000];
int ts = 0;


vector<int> solution(string s) {
    vector<int> answer;
    
    const char *str = s.c_str();
    
    
    int i = 1, j;
    while (str[i]) {
        int cnt = 1;
        if (str[i] == '{') {
            for (j = i + 1 ; str[j] != '}' ; ++j) 
                if (str[j] == ',') cnt++;
            ts = max(ts, cnt);
            for (j = i + 1 ; str[j] != '}' && str[j] != ',' ; ++j) {
                int num = 0;
                for ( ; str[j] != ',' && str[j] != '}' ; ++j) {
                    num *= 10;
                    num += str[j] - '0';
                }
                v[cnt].push_back(num);
            }
            if (str[j + 1] == '}')
                break;
            i = j + 1;
        }
    }
    
    vector<bool> check(100001, 0);
    for (i = 1 ; i <= ts ; ++i) {
        
        for (j = 0 ; j < i ; ++j) {
            if (!check[v[i][j]]) {
                answer.push_back(v[i][j]);
                check[v[i][j]] = 1;
            }
        }      
    }
    
    
    return answer;
}