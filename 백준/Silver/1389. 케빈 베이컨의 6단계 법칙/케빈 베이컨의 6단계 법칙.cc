#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node
{
    int f[101];
    int cnt;
} node;

typedef struct q
{
    int index;
    int lev;
}   q;

node nd[101];
q que[10000];
int visit[101];
int front, rear;
int N,M; 

void push(int index, int l)
{
    que[front].index=index;
    que[front++].lev=l;
}

q pop()
{
    return que[rear++];
}

int bfs(int index)
{
    front = rear = 0;
    memset(visit, 0, sizeof(visit));
    push(index, 0);
    while (front != rear)
    {
        q cur = pop();

        if (visit[cur.index]) continue;

        visit[cur.index] = cur.lev;
        
        for (int i = 0 ; i < nd[cur.index].cnt ; ++i)
        {
            if (visit[nd[cur.index].f[i]]) continue;
            push(nd[cur.index].f[i], cur.lev + 1);
        }
    }
    int sum = 0;
    for (int i = 1 ; i <= N ; ++i)
        sum += visit[i];
    return sum;
}


int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0 ;i<M;++i)
    {
        int s,e; scanf("%d %d", &s, &e);
        nd[s].f[nd[s].cnt++] = e;
        nd[e].f[nd[e].cnt++] = s;
    }   
    int min_v = 999999999;
    int idx = 0;
    for (int i = 1; i<=N;++i)
    {
        int tmp = bfs(i);
        if (min_v > tmp)
        {
            min_v = tmp;
            idx = i;
        }
    }
    printf("%d", idx);
}