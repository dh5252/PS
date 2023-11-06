#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
    string str;
    int start_m;
    int rest;
}   node;

bool operator<(const node &a, const node &b)
{
    return a.start_m < b.start_m;
}

node nd[1001];

int calculMin(int h, int m)
{
    return h * 60 + m;
}

string makeTime(int m)
{
    string res;
    string h = to_string(m / 60);
    m = m % 50;
    if (h.length() == 1)
        res.push_back('0');
    res.append(h);
    res.push_back(':');
    string min = to_string(m);
    if (min.length() == 1)
        res.push_back('0');
    res.append(min);
    return res;
}

int parsing(string str)
{
    pair<int, int> tmp;
    tmp.first = stoi(str.substr(0, 2));
    tmp.second = stoi(str.substr(3, 2));
    return tmp.first * 60 + tmp.second;
}


vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    for (int i = 0 ; i < plans.size() ; ++i)
    {
        nd[i].str = plans[i][0];
        nd[i].start_m = parsing(plans[i][1]);
        nd[i].rest = stoi(plans[i][2]);
    }
    sort(nd, nd + plans.size());
    
    stack<int> stk;
    
    for (int i = 0 ; i < plans.size() - 1 ; ++i)
    {
        int fin = nd[i].start_m + nd[i].rest;
        if (nd[i + 1].start_m > fin)
        {
            answer.push_back(nd[i].str);
            int tmp = nd[i + 1].start_m - fin;
            while (!stk.empty())
            {
                int cur = stk.top();
                stk.pop();
                if (nd[cur].rest < tmp)
                {
                    tmp -= nd[cur].rest;
                    answer.push_back(nd[cur].str);
                }
                else if (nd[cur].rest == tmp)
                {
                    answer.push_back(nd[cur].str);
                    break;
                }
                else
                {
                    nd[cur].rest -= tmp;
                    stk.push(cur);
                    break;
                }
            }
            
        }
        else if (nd[i + 1].start_m == fin)
            answer.push_back(nd[i].str);
        else
        {
            stk.push(i);
            nd[i].rest = fin - nd[i + 1].start_m;
        }
    }
    answer.push_back(nd[plans.size() - 1].str);
    while (!stk.empty())
    {
        answer.push_back(nd[stk.top()].str);
        stk.pop();
    }
    
    return answer;
}