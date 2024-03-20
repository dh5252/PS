#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int x,y;
    int left, right;
    int num;
}   node;

bool operator<(const node &a, const node &b) {
    if (a.y == b.y) 
        return a.x > b.x;
    return a.y < b.y;
}

node nd[10001];
node root;
priority_queue<node> pq;
vector<vector<int> > ans(2);

int N;

void postorder(int cur) {
    if (nd[cur].left != -1)
        postorder(nd[cur].left);
    if (nd[cur].right != -1)
        postorder(nd[cur].right);
    ans[1].push_back(cur);
}

void preorder(int cur) {
    ans[0].push_back(cur);
    if (nd[cur].left != -1)
        preorder(nd[cur].left);
    if (nd[cur].right != -1)
        preorder(nd[cur].right);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    N = nodeinfo.size();
    
    for (int i = 0 ; i < N ; ++i) {
        nd[i + 1].x = nodeinfo[i][0];
        nd[i + 1].y = nodeinfo[i][1];
        nd[i + 1].left = -1;
        nd[i + 1].right = -1;
        nd[i + 1].num = i + 1;
        pq.push(nd[i + 1]);        
    }
    
    root = pq.top();
    pq.pop(); 
    while (!pq.empty()) {
        
        node cur = pq.top();
        pq.pop();
        
        int search = root.num;
        while (1) {
            if (cur.x < nd[search].x) {
                if (nd[search].left == -1) {
                    nd[search].left = cur.num;
                    break;
                }
                search = nd[search].left;
            }
            else if (cur.x > nd[search].x) {
                if (nd[search].right == -1) {
                    nd[search].right = cur.num;
                    break;
                }
                search = nd[search].right;
            }
        }
    }
    cout << root.num;
    postorder(root.num);
    preorder(root.num);
    return ans;
}