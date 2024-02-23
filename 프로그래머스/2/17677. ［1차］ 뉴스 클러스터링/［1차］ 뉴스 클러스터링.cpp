#include <bits/stdc++.h>

using namespace std;

vector<string> s1, s2;
unordered_map<string, int> hs1, hs2;
unordered_set<string> v;

int solution(string str1, string str2) {
    
    int cnt = 0;
 
    for (int i = 0 ; i < str1.length(); ++i) {
        if (str1[i] >= 'A' && str1[i] <= 'Z')
            str1[i] = str1[i] - 'A' + 'a';
    }
    for (int i = 0 ; i < str2.length(); ++i) {
        if (str2[i] >= 'A' && str2[i] <= 'Z')
            str2[i] = str2[i] - 'A' + 'a';
    }
    
    for (int i = 0 ; i < str1.length() - 1; ++i)
    {
        string tmp = str1.substr(i, 2);
        if (isalpha(tmp[0]) && isalpha(tmp[1]))
        {
            ++cnt;
            s1.push_back(tmp);
            if (hs1.find(tmp) == hs1.end())
                hs1[tmp] = 1;
            else
                hs1[tmp]++;
        }
    }
    for (int i = 0 ; i < str2.length() - 1; ++i)
    {
        string tmp = str2.substr(i, 2);
        if (isalpha(tmp[0]) && isalpha(tmp[1])) {
            ++cnt;
            s2.push_back(tmp);
            if (hs2.find(tmp) == hs2.end())
                hs2[tmp] = 1;
            else
                hs2[tmp]++;
        }
    }
    
    int cross = 0;
    int sum = cnt;
    for (int i = 0 ; i < s1.size() ; ++i) {
        
        if (v.find(s1[i]) != v.end()) continue;
        
        int c1 = hs1[s1[i]];
        int c2 = hs2[s1[i]];
        cross += min(c1, c2);
        sum -= min(c1, c2);
        if (min(c1, c2) > 0)
            v.insert(s1[i]);
    }
    cout << cross << " " << sum << "\n";
    if (cross == 0 && sum == 0)
        return 65536;
    return 65536 * ((long double) cross / sum);
}