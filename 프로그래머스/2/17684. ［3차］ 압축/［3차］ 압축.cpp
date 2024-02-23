#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> hs;

vector<int> solution(string msg) {
    vector<int> answer;
    
    int num = 27;
    
    for (int i = 0 ; i < msg.length() ; ++i) {
        
        string tmp = "";
        
        if (i == msg.length() - 1) {
            answer.push_back(msg[i] - 'A' + 1);
            break ;
        }
            
        tmp = msg[i];
        int j;
        for (j = i + 1 ; j < msg.length() ; ++j) {
            if (hs.find(tmp + msg[j]) == hs.end()) {
                hs[tmp + msg[j]] = num++;
                break;
            }
            tmp += msg[j];
        }
        if (tmp.length() > 1) {
            answer.push_back(hs[tmp]);
            i = j - 1;
        }
        else
            answer.push_back(msg[i] - 'A' + 1);
    }
    return answer;
}