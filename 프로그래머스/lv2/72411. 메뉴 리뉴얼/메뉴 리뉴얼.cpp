#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> masking;
vector<int> cp;
map<string, int> s;
vector<string> split;
int len[20];

int count_bits(int n)
{
    if (n == 0) return 0;
    return count_bits(n / 2) + n % 2;
}

string convert_to_str(int n)
{
    string str;
    for (int i = 0 ; i < 27 ; ++i)
        if ((n & (1 << i)))
            str.push_back('A' + i);
    return str;
}

void dfs2(string str, int index, string sub)
{
    if (sub.length() >= 2)
        split.push_back(sub);
    
    if (str.length() == index) return;
    
    dfs2(str, index + 1, sub);
    sub.push_back(str[index]);
    dfs2(str, index + 1, sub);
}

void dfs(int index, int num, int cnt)
{
    if (index == masking.size()) return;
    
    int common = count_bits(num & masking[index]);
    
    if (cnt >= 2)
    {
        split.clear();
        string tmp;
        dfs2(convert_to_str(num & masking[index]), 0, tmp);
        for (int j = 0 ; j < split.size() ; ++j)
            for (int i = 0 ; i < cp.size() ; ++i)
                if (split[j].length() == cp[i]) 
                    s[split[j]] = max(cnt, s[split[j]]);    
    }
        
    dfs(index + 1, num & masking[index],  cnt + 1);
    dfs(index + 1, num, cnt);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    for (int i = 0 ; i < orders.size() ; ++i)
    {
        masking.push_back(0);
        for (int j = 0 ; j < orders[i].length() ; ++j)
            masking[i] |= (1 << (orders[i][j] - 'A'));
    }    
    cp = course;
    dfs(0, (1 << 26) - 1, 1);
    vector<string> answer;
    for (auto it = s.begin() ; it != s.end() ; ++it)
        len[it->first.length()] = max(len[it->first.length()], it->second);      
    for (auto it = s.begin() ; it != s.end() ; ++it)
        if (len[it->first.length()] == it->second)
            answer.push_back(it->first);
    
    return answer;
}