#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    for (int i = 0 ; i < name.length() ; ++i) {
        int tmp = min(name[i] - 'A', 'Z' + 1 - name[i]);
        answer += tmp;
    }
    
    vector<pair<int, int> > a;
    for (int i = 0 ; i < name.length() ; ++i) {
        if (name[i] == 'A') {
            int j;
            for (j = i ; j < name.length() ; ++j) {
                if (name[j] != 'A')
                    break;
            }
            a.push_back({i, j - 1});
            i = j - 1;
        }
    }
    
    if (a.size() == 0)
        return answer + name.length() - 1;
    
    int min_value = name.length() - 1;
    for (int i = 0 ; i < a.size() ; ++i) {
        if (a[i].first == 0) {
            int move1 = name.length() - a[i].second - 1;
            min_value = min(min_value, move1);
            continue;
        }
        int move1 = (a[i].first - 1) * 2 + (name.length() - a[i].second - 1);
        int move2 = (name.length() - a[i].second - 1) * 2 + a[i].first - 1;
        min_value = min(min_value, min(move1, move2));
    }
    
    return answer + min_value;
}