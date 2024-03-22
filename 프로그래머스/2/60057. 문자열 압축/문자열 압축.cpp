#include <bits/stdc++.h>

using namespace std;


int cut(string s, int k) {
    
    string str;
    
    int cnt = 1;
    string before = "";
    
    for (int i = 0 ; i < s.length() ; i += k) {
        int j;
        string tmp;
        for (j = 0 ; j < k && i + j < s.length() ; ++j)
            tmp.push_back(s[i + j]);
            
        if (before == tmp)
            cnt++;
        else if (cnt > 1) {
            str.append(to_string(cnt));
            cnt = 1;
            str.append(before);
            before = tmp;
        }
        else {
            if (before != "")
                str.append(before);
            before = tmp;
        }   
    }
    if (cnt > 1) {
        str.append(to_string(cnt));
        str.append(before);
    }
    else if (before != "")
        str.append(before);
    //cout << str << " " << str.length() << "\n";
    return str.length();
}



int solution(string s) {
    
    int ans = INT_MAX;
    for (int i = 1 ; i <= s.length() / 2; ++i) {
        ans = min(ans, cut(s, i));
    }
    if (s.length() == 1)
        ans = 1;
    return ans;
}