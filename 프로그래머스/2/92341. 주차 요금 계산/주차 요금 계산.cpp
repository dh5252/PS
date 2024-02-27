#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int time;
    bool in; // 1 -> in, 0 -> out
    int num;
}   node;


node hs[10000];
int minute[10000];


int fin_time = 23 * 60 + 59;

node transform(string record) {
    
    node n;
    const char *s = record.c_str();
    
    int h = atoi(s);
    int m = atoi(s + 3);
    n.time = h * 60 + m;
    
    s += 6;
    
    n.num = atoi(s);
    s += 5;
    
    if (!strcmp("IN", s))
        n.in = 1;
    else
        n.in = 0;
    return n;
}

int calcul_fee(int time, vector<int> &fees) {
    if (time <= fees[0]) return fees[1];
    
    int res = time - fees[0];
    int f = fees[1];
    
    f += (res / fees[2]) * fees[3];
    if (res % fees[2])
        f += fees[3];
    return f;
}


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    vector<node> nd;
    for (int i = 0 ; i < records.size() ; ++i) 
        nd.push_back(transform(records[i]));
    
    for (int i = 0 ; i < nd.size() ; ++i) {
        if (nd[i].in) {
            hs[nd[i].num] = nd[i];
        }
        else {
            minute[nd[i].num] += nd[i].time - hs[nd[i].num].time;
            hs[nd[i].num] = {0, 0, 0};
        }
    }
    for (int i = 0 ; i < 10000 ; ++i) {
        if (hs[i].in) 
            minute[i] += fin_time - hs[i].time;
        if (minute[i]){
            answer.push_back(calcul_fee(minute[i], fees));
        }
    }
    
    return answer;
}