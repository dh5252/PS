#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int v;
    int level;
}   node; 


node que[5000001];
int visit[1000001];
int front, rear;

void push(int v, int l)
{
    que[front].v = v;
    que[front++].level = l;
}

node pop()
{
    return que[rear++];
}

int main()
{
    int F,S,G,U,D; scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    memset(visit, -1, sizeof(visit));
    push(S, 0);
    while (front != rear)
    {
        node cur = pop();
        if (visit[cur.v] != -1) continue;
        visit[cur.v] = cur.level;
        if (cur.v == G)
            break;
        if (cur.v + U <= F)
            push(cur.v + U, cur.level + 1);
        if (cur.v - D > 0)
            push(cur.v - D, cur.level + 1);
    }
    if (visit[G] == -1)
        printf("use the stairs");
    else
        printf("%d", visit[G]);
}