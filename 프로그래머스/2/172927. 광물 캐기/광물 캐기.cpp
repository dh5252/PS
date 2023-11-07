#include <bits/stdc++.h>

using namespace std;

vector<int> conv;
int matrix[3][3] = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};

int calcul(int index, int mode)
{
    int sum = 0;
    for (int i = index ; i < index + 5 && i < conv.size() ; ++i)
        sum += matrix[mode][conv[i]];
    return sum;
}


int dfs(int index, int sum, vector<int> cur)
{
    if (!cur[0] && !cur[1] && !cur[2])
        return sum;
    if (index >= conv.size())
        return sum;
    int s = INT_MAX;
    if (cur[0] > 0)
    {
        vector<int> k = cur;
        --k[0];
        s = min(s, dfs(index + 5, sum + calcul(index, 0), k));
        
    }
    if (cur[1] > 0)
    {
        vector<int> k = cur;
        --k[1];
        s = min(s, dfs(index + 5, sum + calcul(index, 1), k));
    }
    if (cur[2] > 0)
    {
        vector<int> k = cur;
        --k[2];
        s = min(s, dfs(index + 5, sum + calcul(index, 2), k));
    }
    return s;
}

int solution(vector<int> picks, vector<string> minerals) {
    for (int i = 0 ; i < minerals.size() ; ++i)
    {
        if (minerals[i] == "diamond")
            conv.push_back(0);
        else if (minerals[i] == "iron")
            conv.push_back(1);
        else if (minerals[i] == "stone")
            conv.push_back(2);
    }
    return dfs(0, 0, picks);
}