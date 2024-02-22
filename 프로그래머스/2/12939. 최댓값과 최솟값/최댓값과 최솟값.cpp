#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    const char *str = s.c_str();
    
    vector<int> v;
    
    int i = 0, j;
    while (str[i])
    {
        int num = 0;
        int minus = 1;
        if (str[i] == '-')
        {
            minus = -1;
            i++;
        }
        for (j = i ; str[j] && str[j] != ' ' ; ++j) {
            num *= 10;
            num += str[j] - '0';
        }
        v.push_back(num * minus);
        i = j + 1;
        if (!str[j]) break;
    }
    sort(v.begin(), v.end());
    
    string ans = to_string(v[0]);
    ans += " " + to_string(v[v.size() - 1]);
    return ans;
}
