#include <bits/stdc++.h>

using namespace std;

unordered_set<string> hs, hs2;

pair<int, int> rtn_index(vector<string> &id_list, const char *str) {
    
    int i = 0;
    int f = 0, j;
    char *s = strdup(str);
    for (i = 0 ; s[i] && s[i] != ' ' ; ++i);
    
    s[i] = 0;
    for (j = 0 ; j < id_list.size() ; ++j) {
        if (!strcmp(s, id_list[j].c_str()))
        {
            f = j;
            break;
        }
    }
    s += i + 1;
    
    for (int i = 0 ; i < id_list.size() ; ++i) {
        if (!strcmp(s, id_list[i].c_str()))
            return {f, i};
    }
    return {-1, -1};
}


vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    vector<int> cnt(id_list.size(), 0);
    
    for (int i = 0 ; i < report.size() ; ++i) {
          
        if (hs.find(report[i]) != hs.end())
            continue;
        pair<int, int> index = rtn_index(id_list, report[i].c_str());
        cnt[index.second]++;
        hs.insert(report[i]);
    }
    
    for (int i = 0 ; i < report.size() ; ++i) {
        
        if (hs2.find(report[i]) != hs2.end())
            continue;
        pair<int, int> index = rtn_index(id_list, report[i].c_str());
        if (cnt[index.second] >= k) {
            answer[index.first]++;
        }
        hs2.insert({report[i]});
    }
    return answer;
}