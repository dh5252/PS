#include <bits/stdc++.h>

using namespace std;

char *m[51][51];
pair<int, int> parent[51][51];
vector<pair<int, int> > child[51][51];
vector<string> output;

pair<int, int> find(int r, int c)
{
    if (parent[r][c] == make_pair(r, c))
        return parent[r][c];
    return find(parent[r][c].first, parent[r][c].second);
}

void update_value(char *v1, char *v2)
{
    for (int i = 1 ; i <= 50 ; i++)
        for (int j = 1 ; j <= 50 ; j++)
            if (m[i][j] && !strcmp(m[i][j], v1))
            {
                if (m[i][j])
                    free(m[i][j]);
                m[i][j] = strdup(v2);
            }
}

void update_loc(int r, int c, char *value)
{
    pair<int, int> p = find(r, c);
    
    if (m[p.first][p.second])
        free(m[p.first][p.second]);
    m[p.first][p.second] = strdup(value);
}

void merge(int r1, int c1, int r2, int c2)
{
    pair<int, int> s1 = find(r1, c1);
    pair<int, int> s2 = find(r2, c2);
    
    if (s1 == s2)
        return ;
    if (m[s1.first][s1.second] && m[s2.first][s2.second])
    {
        if (m[s2.first][s2.second])
            free(m[s2.first][s2.second]);
        m[s2.first][s2.second] = 0;
        parent[s2.first][s2.second] = s1;
        child[s1.first][s1.second].push_back(s2);
    }
    else if (m[s1.first][s1.second])
    {
        parent[s2.first][s2.second] = s1;
        child[s1.first][s1.second].push_back(s2);
    }
    else if (m[s2.first][s2.second])
    {
        parent[s1.first][s1.second] = s2;
        child[s2.first][s2.second].push_back(s1);
    }
    else
    {
        parent[s2.first][s2.second] = s1;
        child[s1.first][s1.second].push_back(s2);
    }
}

void unmerge(int r, int c)
{
    parent[r][c] = make_pair(r, c);
    for (int i = 0 ; i < child[r][c].size() ; i++)
        unmerge(child[r][c][i].first, child[r][c][i].second);
    child[r][c].clear();
}

void unmerge_init(int r, int c)
{
    pair<int, int> root = find(r, c);
    if (root != make_pair(r, c))
    {
        if (m[root.first][root.second])
        {
            m[r][c] = strdup(m[root.first][root.second]);    
            free(m[root.first][root.second]);
            m[root.first][root.second] = 0;
        }
    }
    unmerge(root.first, root.second);
}

void print(int r, int c)
{
    pair<int,int> root = find(r, c);
    
    if (r == 1 && c == 4)
        cout << "here : " <<root.first << " " << root.second << "\n";
    if (m[root.first][root.second] == 0)
        output.push_back("EMPTY");
    else
    {
        string tmp(m[root.first][root.second]);
        output.push_back(tmp);
    }
}

vector<string> solution(vector<string> commands) {
    
    for (int i = 1 ; i <= 50 ; i++)
        for (int j = 1 ; j <= 50 ; j++)
            parent[i][j] = make_pair(i, j);
    
    for (int i = 0 ; i < commands.size() ; i++)
    {
        char *s = (char *)malloc(100);
        strcpy(s, commands[i].c_str());
        
        if (!strncmp(s, "UPDATE", 6) )
        {
            char *a, *b, *c;
            int idx = 0;
            
            strtok(s, " ");
            a = strtok(NULL, " ");
            b = strtok(NULL, " ");
            c = strtok(NULL, " ");
            
            if (c == NULL)
                update_value(a, b);
            else
            {
                int row = atoi(a);
                int col = atoi(b);
                update_loc(row, col, c);
            }
            
        }
        else if (!strncmp(s, "MERGE", 5) )
        {
            char *a,*b,*c,*d;
            strtok(s, " ");
            a = strtok(NULL, " ");
            b = strtok(NULL, " ");
            c = strtok(NULL, " ");
            d = strtok(NULL, " ");
            int r1,c1,r2,c2;
            r1 = atoi(a);
            c1 = atoi(b);
            r2 = atoi(c);
            c2 = atoi(d);
            merge(r1, c1, r2, c2);
        }
        else if (!strncmp(s, "UNMERGE", 7) )
        {
            char *a,*b;
            strtok(s, " ");
            a = strtok(NULL, " ");
            b = strtok(NULL, " ");
            int r1,c1;
            r1 = atoi(a);
            c1 = atoi(b);
            unmerge_init(r1, c1);
        }
        else if (!strncmp(s, "PRINT", 5) )
        {
            char *a,*b;
            strtok(s, " ");
            a = strtok(NULL, " ");
            b = strtok(NULL, " ");
            int r1,c1;
            r1 = atoi(a);
            c1 = atoi(b);
            print(r1, c1);
        }
    }
    return output;
}